#include "./story.c"
#include "./button.c"

int main() {

    SetTraceLogLevel(LOG_ERROR);
    InitWindow(WIDTH, HEIGHT, "GAME");

    Player john = {
        .isEmployed = false,
        .totalCash = 0,
        .hasItem = 0,
    }; // LOAD FROM SAVE FILE

    int events_completed = 0; // LOAD FROM SAVE FILE

    Event* eventline = (Event*) malloc(sizeof(Event) * TOTAL_EVENTS);

    updateEvent(eventline);

    Button home_continue_btn = {
        .buttonType = HOMESCREEN,
        .buttonRec.x = 100,
        .buttonRec.y = 100,
        .buttonRec.width = 145,
        .buttonRec.height = 50,
        .buttonBgColor = DARKGRAY,
        .buttonTextColor = WHITE,
        .buttonText = "CONTINUE",
        .buttonID = 1
    };

    buttonClick(home_continue_btn);

    while(!WindowShouldClose()) {

        while(eventline[events_completed].eventCondtion(&john, eventline[events_completed].eventId) != 1) {

            ClearBackground(RAYWHITE);

            handleEvent(eventline, events_completed);
            handleKey(GetKeyPressed(), &john);

            BeginDrawing();

            drawButton(home_continue_btn);
            buttonClick(home_continue_btn);

            EndDrawing();

        }

        events_completed++;

    }

    free(eventline);

    return 0;

}
