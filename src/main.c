#include "./story.c"
#include "./button.c"
#include "./screens/home_screen/home_screen.c"

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

    //---------------------------------------- Select Screen //

    GameScreen* screenStack[SCREEN_LIMIT] = {0};
    GameScreen** screenPtr = screenStack;

    GameScreen* home_screen = homeScreen();

    defaultScreen(screenStack, home_screen);

    //----------------------------------------

    while(!WindowShouldClose()) {

        while(eventline[events_completed].eventCondtion(&john, eventline[events_completed].eventId) != 1) {

            ClearBackground(RAYWHITE);

            handleEvent(eventline, events_completed);
            handleKey(GetKeyPressed(), &john);

            BeginDrawing();

            renderScreen(screenStack, screenPtr);

            EndDrawing();

        }

        events_completed++;

    }

    free(eventline);
    free(home_screen);

    return 0;

}
