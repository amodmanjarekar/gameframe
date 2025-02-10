#ifndef GAME_EVENT_H_
#define GAME_EVENT_H_

#include <raylib.h>
#include <unistd.h>

typedef struct Player Player;

typedef enum GameEvent {
    CUTSCENE,
    UPDATE,
    INFO
} GameEvent;

typedef struct Event {
    GameEvent eventType;
    Music eventMusic;
    Image* eventCutScenes;
    size_t eventNumCutScenes;
    int (*eventCondtion)(Player*);
    char* eventInfo;
    float eventTimeout;
} Event;

#endif // !GAME_EVENT_H_
