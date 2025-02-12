#include <raylib.h>
#include <stdlib.h>

#include "./story.c"

#define TOTAL_EVENTS 5
#define WIDTH 1280
#define HEIGHT 720

int main() {

    SetTraceLogLevel(LOG_ERROR);
    InitWindow(WIDTH, HEIGHT, "GAME");

    Player john = {
        .isEmployed = false,
        .totalCash = 0,
        .hasItem = 0,
    };

    Event* eventline = (Event*) malloc(sizeof(Event) * TOTAL_EVENTS);

    updateEvent(eventline);

    int events_completed = 0; // LOAD FROM SAVE FILE

    while(!WindowShouldClose()) {

        while(eventline[events_completed].eventCondtion(&john, eventline[events_completed].eventId) != 1) {

            ClearBackground(RAYWHITE);

            BeginDrawing();

            handleEvent(eventline, events_completed);

            handleKey(GetKeyPressed(), &john);

            if(IsKeyPressed(KEY_ESCAPE)) {
                exit(0);
            }

            EndDrawing();

        }

        events_completed++;

    }

    free(eventline);

    return 0;

}
