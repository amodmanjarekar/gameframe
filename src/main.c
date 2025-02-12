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

    int events_completed = 0;

    while(!WindowShouldClose()) {

        while(eventline[events_completed].eventCondtion(&john, eventline[events_completed].eventId) != 1) {

            ClearBackground(RAYWHITE);

            BeginDrawing();

            switch (eventline[events_completed].eventType) {

                case CUTSCENE:
                    break;

                case INFO:

                    DrawRectangle(10, HEIGHT-60, WIDTH-20, 50, BLACK);
                    DrawText(eventline[events_completed].eventInfo.eventText, 20, HEIGHT-50, 30, WHITE);

                    break;

                case UPDATE:

                    DrawRectangle(10, HEIGHT-60, WIDTH-20, 50, PURPLE);
                    DrawText(eventline[events_completed].eventInfo.eventText, 20, HEIGHT-50, 30, WHITE);

                    if (eventline[events_completed].eventTimeout < 0) {
                        eventline[events_completed].eventCondtion = eventTrueCondition;
                    } else {
                        eventline[events_completed].eventTimeout -= 0.009f;
                    }

                    break;

                default:

                    break;

            }

            if(IsKeyPressed(KEY_F)) {
                john.isEmployed = true;
            }

            if(IsKeyPressed(KEY_G)) {
                john.totalCash = 100;
            }

            if(IsKeyPressed(KEY_H)) {
                john.totalCash = 200;
            }

            if(IsKeyPressed(KEY_J)) {
                john.totalCash = 700;
            }

            EndDrawing();

        }

        events_completed++;

    }

    free(eventline);

    return 0;

}
