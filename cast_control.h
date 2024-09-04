#ifndef _CAST_CONTROL_H
#define _CAST_CONTROL_H

#include <stdint.h>
#include <stdbool.h>
#include "cast_message.h"

struct MessageItem {
    uint8_t *msg;
    uint16_t msgLen;
    enum CastMessageType type;
};

struct MessageData {
    char **items;
    uint16_t size;
};

struct MessageQueueItem {
    struct MessageQueueItem *next;
    enum CastMessageType type;
    struct MessageData  *data;
    enum CastMessageType waitFor;
};

struct CastState {
    char *senderId;
    char receiverId[64];
    char *appId;
    uint16_t requestId;
	struct MediaStatus mediaStatus;
};

enum CastMessageType sendMessage(struct MessageQueueItem **item, struct MessageItem **msgItem, struct CastState *cs);
void queueMessage(struct MessageQueueItem **item, enum CastMessageType msgType,
        struct MessageData *data, enum CastMessageType waitFor);
enum CastMessageType processData(struct MessageQueueItem **msgQueueItem, struct MessageItem **item, struct CastState *cs, uint8_t *buf, uint16_t buflen);

#endif

