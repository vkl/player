#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <poll.h>
#include <pthread.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <sys/eventfd.h>
#include <sys/times.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#include "cast_control.h"

#include "tls.h"
#include "cli.h"

#include "media.h"

int efd;

static void loadMedia(struct MessageData *data, char **media, uint16_t size); 
static void freeMedia(struct MessageData *data); 

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *hostname = argv[1];
    const char *port = argv[2];

    SSL_CTX *ctx = NULL;
    SSL *ssl = NULL;
    BIO *bio = NULL;
    int res = EXIT_FAILURE;
    int ret;
    int eof = 0;
    efd = eventfd(0, 0);
    pthread_t interactive_id = 0;
    struct MessageItem *msgItem = NULL;
    struct MessageQueueItem *msgQueueItem = NULL;
    char *media = NULL;
    struct MessageData data1, data2;
    loadMedia(&data1, media1, 1);
    loadMedia(&data2, media3, 3);
    
    ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Failed to create the SSL_CTX\n");
        goto end;
    }

    SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL);

    if (!SSL_CTX_set_default_verify_paths(ctx)) {
        fprintf(stderr, "Failed to set the default trusted certificate store\n");
        goto end;
    }

    if (!SSL_CTX_set_min_proto_version(ctx, TLS1_2_VERSION)) {
        fprintf(stderr, "Failed to set the minimum TLS protocol version\n");
        goto end;
    }

    ssl = SSL_new(ctx);
    if (ssl == NULL) {
        fprintf(stderr, "Failed to create the SSL object\n");
        goto end;
    }

    bio = create_socket_bio(hostname, port, AF_INET);
    if (bio == NULL) {
        fprintf(stderr, "Failed to crete the BIO\n");
        goto end;
    }
    SSL_set_bio(ssl, bio, bio);

    if (!SSL_set_tlsext_host_name(ssl, hostname)) {
        fprintf(stderr, "Failed to set the SNI hostname\n");
        goto end;
    }

    if (!SSL_set1_host(ssl, hostname)) {
        fprintf(stderr, "Failed to set the certificate verification hostname");
        goto end;
    }

    while ((ret = SSL_connect(ssl)) != 1) {
        if (handle_io_failure(ssl, ret) == 1)
            continue; /* Retry */
        printf("Failed to connect to server\n");
        goto end; /* Cannot retry: error */
    }

    pthread_create(&interactive_id, NULL, interactive, NULL);
    
    size_t written;

    uint8_t buf[4096];
    size_t readbytes;
    int ssl_error;
    //fd_set fds;
    //int width, sock;
    int sock = SSL_get_fd(ssl);
    struct pollfd fds[2];
    //FD_ZERO(&fds);
    //FD_SET(sock, &fds);
    //width = sock + 1;

    fds[0].fd = sock;
    fds[0].events = POLLIN;
    fds[1].fd = efd;
    fds[1].events = POLLIN;
    
    uint16_t requestId = 0;
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    long long elapsed = 0;
    struct CastState cs = {
        .senderId = DEFAULT_SOURCE_ID,
        .appId = APPMEDIA,
        .requestId = 1
    };
    strcpy(cs.receiverId, DEFAULT_DESTINATION_ID);
   
    enum CastMessageType waitForType, lastType;
    waitForType = NONE;
    lastType = NONE;

    for (;;) {

        
        int ret = poll(fds, 2, 500);
        if (ret == -1) {
            perror("poll");
            goto end;
        }
        //else if (ret == 0) {
        //    continue;
        //}

        /* Heartbeat */
        // add PING every 4000 ms
        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed = ((end.tv_sec - start.tv_sec) * 1000) + \
                            ((end.tv_nsec - start.tv_nsec) / 1e6);
        if (elapsed >= 4000) {
            //queueMessage(&msgQueueItem, PING, NULL);
            clock_gettime(CLOCK_MONOTONIC, &start);
        }

        if ((fds[0].revents & POLLIN) && 
                SSL_read_ex(ssl, buf, sizeof(buf), &readbytes)) {
                //printf("read %lu bytes\n\r", readbytes);
            lastType = processData(&msgQueueItem, &msgItem, &cs, buf, readbytes);
            //printf("received type: %s\n\r", TYPE_TO_STR(lastType));
        }

        bool checkType = (waitForType == NONE) || (waitForType == lastType);
        if ((fds[0].revents & POLLOUT) && checkType) {
            //printf("%s %s \n\r", TYPE_TO_STR(waitForType), TYPE_TO_STR(lastType));
            waitForType = sendMessage(&msgQueueItem, &msgItem, &cs);
            //printf("wait for %s\n\r", TYPE_TO_STR(waitForType));
            if (SSL_write_ex(ssl, msgItem->msg, msgItem->msgLen, &written)) {
                //printf("sent %lu bytes\n\r", written);
            }
            free(msgItem->msg);
            free(msgItem);     
            fds[0].events &= ~POLLOUT;
        }

        // signal from user
        if (fds[1].revents & POLLIN) {
            uint64_t signal = 0;
            read(efd, &signal, sizeof(signal));
            switch (signal) {
                case (char)'q':
                    goto end;
                    break;
                case (char)'x':
                    queueMessage(&msgQueueItem, CLOSE, NULL, NONE);
                    queueMessage(&msgQueueItem, GET_STATUS, NULL, NONE);
                    break;
                case (char)'c':
                    queueMessage(&msgQueueItem, CONNECT, NULL, NONE);
                    queueMessage(&msgQueueItem, LAUNCH, NULL, RECEIVER_STATUS);
                    queueMessage(&msgQueueItem, CONNECT, NULL, NONE);
                    //queueMessage(&msgQueueItem, GET_STATUS, NULL, RECEIVER_STATUS);
                    queueMessage(&msgQueueItem, GET_MEDIA_STATUS, NULL, NONE);
                    break;
                case (char)'1':
                    queueMessage(&msgQueueItem, LOAD, &data1, NONE);
                    break;
                case (char)'2':
                    queueMessage(&msgQueueItem, LOAD, &data2, MEDIA_STATUS);
                    if (data2.size > 1) {
                        queueMessage(&msgQueueItem, QUEUE_INSERT, &data2, NONE);
                    }
                    break;
                case (char)'s':
                    queueMessage(&msgQueueItem, STOP, NULL, NONE);
                    break;
                case (char)'i':
                    queueMessage(&msgQueueItem, QUEUE_NEXT, NULL, NONE);
                    break;
                case (char)'o':
                    queueMessage(&msgQueueItem, QUEUE_PREV, NULL, NONE);
                    break;
                case (char)'p':
                    if (cs.mediaStatus.playerState == PLAYING)
                        queueMessage(&msgQueueItem, PAUSE, NULL, NONE);
                    else if (cs.mediaStatus.playerState == PAUSED)
                        queueMessage(&msgQueueItem, PLAY, NULL, NONE);
                    break;
                case (char)'m':
                    queueMessage(&msgQueueItem, GET_MEDIA_STATUS, NULL, NONE);
                    break;
                case (char)'+':
                    cs.mediaStatus.volume.level += 0.05;
                    queueMessage(&msgQueueItem, SET_VOLUME, NULL, NONE);
                    break;
                case (char)'-':
                    cs.mediaStatus.volume.level -= 0.05;
                    queueMessage(&msgQueueItem, SET_VOLUME, NULL, NONE);
                    break;
            }
        }

        /* check message queue */
        if (msgQueueItem != NULL) {
            fds[0].events |= POLLOUT;
        }

    }
    
    if (SSL_get_error(ssl, 0) != SSL_ERROR_ZERO_RETURN) {
        fprintf(stderr, "Failed reading remaining data\n");
        goto end;
    }

    ret = SSL_shutdown(ssl);
    if (ret < 1) {
        fprintf(stderr, "Error shutting down\n");
        goto end;
    }

    res = EXIT_SUCCESS;

    struct MessageQueueItem *curr, *tmp;

end:
    freeMedia(&data1);
    freeMedia(&data2);
    curr = msgQueueItem;    
    while (curr) {
        tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    if (res == EXIT_FAILURE)
        ERR_print_errors_fp(stderr);

    SSL_free(ssl);
    SSL_CTX_free(ctx);
    pthread_join(interactive_id, NULL);
    return res;
}

static void loadMedia(struct MessageData *data, char **media, uint16_t size) {
    data->size = size;
    data->items = calloc(size, sizeof(char*));
    for (uint16_t i=0; i<size; i++) {
        data->items[i] = strdup(media[i]);
    }
}

static void freeMedia(struct MessageData *data) {
    for (uint16_t i=0; i<data->size; i++) {
        free(data->items[i]);
    }
    free(data->items);
}

