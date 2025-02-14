#ifndef GAME_EVENT_H_
#define GAME_EVENT_H_

#include <raylib.h>
#include <unistd.h>

typedef struct Player Player;

typedef enum GameEvent {
    CUTSCENE,
    UPDATE,
    INFO,
} GameEvent;

typedef struct CutsceneEvent {
    Image* eventCutscenes;
    Music eventBackgroundTrack;
    size_t eventNumCutscenes;
} CutsceneEvent;

typedef struct InfoEvent {
    char* eventText;
} InfoEvent;

typedef struct Event {
    GameEvent eventType;
    int (*eventCondtion)(Player*, size_t);
    float eventTimeout;
    size_t eventId;
    union {
        InfoEvent eventInfo;
        CutsceneEvent eventCutscene;
    };
} Event;

#endif // !GAME_EVENT_H_
