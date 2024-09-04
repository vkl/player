#ifndef _CAST_MESSAGE_H
#define _CAST_MESSAGE_H

#define HEARTBEAT_NS           "urn:x-cast:com.google.cast.tp.heartbeat"
#define CONNECTION_NS          "urn:x-cast:com.google.cast.tp.connection"
#define RECEIVER_NS            "urn:x-cast:com.google.cast.receiver"
#define MEDIA_NS               "urn:x-cast:com.google.cast.media"

#define DEFAULT_SOURCE_ID      "sender-0"
#define DEFAULT_DESTINATION_ID "receiver-0"

#define APPBACKDROP            "E8C28D3C"
#define APPMEDIA               "CC1AD845"
#define APPURL                 "5CB45E5A"
#define APPYOUTUBEMUSIC        "2DB7CC49"
#define APPYOUTUBE             "233637DE"

#include <stdbool.h> 

enum CastMessageType {
    NONE,
    PING,
    PONG,
    CONNECT,
    CLOSE,
    GET_STATUS,
    RECEIVER_STATUS,
    LAUNCH,
    MEDIA_STATUS,
    GET_MEDIA_STATUS,
    LOAD,
    QUEUE_INSERT,
    QUEUE_NEXT,
    QUEUE_PREV,
	PLAY,
	PAUSE,
    STOP,
    SET_VOLUME
};

#define TYPE_TO_STR(type) \
    ((type) == NONE ? "NONE" : \
    (type) == PING ? "PING" : \
    (type) == PONG ? "PONG" : \
    (type) == CONNECT ? "CONNECT" : \
    (type) == CLOSE ? "CLOSE" : \
    (type) == GET_STATUS ? "GET_STATUS" : \
    (type) == RECEIVER_STATUS ? "RECEIVER_STATUS" : \
    (type) == LAUNCH ? "LAUNCH" : \
    (type) == MEDIA_STATUS ? "MEDIA_STATUS" : \
    (type) == GET_MEDIA_STATUS ? "GET_MEDIA_STATUS" : \
    (type) == LOAD ? "LOAD" : \
    (type) == QUEUE_INSERT ? "QUEUE_INSERT" : \
    (type) == QUEUE_NEXT ? "QUEUE_NEXT" : \
    (type) == QUEUE_PREV ? "QUEUE_PREV" : \
    (type) == PLAY ? "PLAY" : \
    (type) == PAUSE ? "PAUSE" : \
    (type) == STOP ? "STOP" : \
    (type) == SET_VOLUME ? "SET_VOLUME" : "UNKNOWN_TYPE")

enum PlayerState {
    IDLE,
    BUFFERING,
    PAUSED,
    PLAYING
};

struct Volume {
    float level;
    bool muted;
};

struct MediaStatus {
    int mediaSessionId;
    enum PlayerState playerState;
    struct Volume volume;
};

#endif
