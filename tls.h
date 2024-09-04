#ifndef _TLS_H
#define _TLS_H

#include <openssl/ssl.h>

BIO *create_socket_bio(const char *hostname, const char *port, int family);

void wait_for_activity(SSL *ssl, int write);

int handle_io_failure(SSL *ssl, int res);

#endif
