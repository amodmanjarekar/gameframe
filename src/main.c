#include "./story.c"
#include "./button.c"
#include "./screen.c"

#include "./screens/home_screen/home_screen.c"
#include "./screens/options_screen/options_screen.c"
#include <string.h>

int main() {

    SetTraceLogLevel(LOG_ERROR);
    InitWindow(WIDTH, HEIGHT, "GAME");
    InitAudioDevice();

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
    GameScreen* options_screen = optionsScreen();

    defaultScreen(screenStack, home_screen);

    /* pushScreen(screenStack, &screenPtr, options_screen); */
    /* popScreen(screenStack, &screenPtr); */

    //----------------------------------------

    while(!WindowShouldClose()) {

        while(eventline[events_completed].eventCondtion(&john, eventline[events_completed].eventId) != 1) {

            UpdateMusicStream((*screenPtr)->track);

            handleEvent(eventline, events_completed);
            handleKey(GetKeyPressed(), &john);

            if (IsKeyPressed(KEY_T)) {
                pushScreen(screenStack, &screenPtr, options_screen);
            } else if(IsKeyPressed(KEY_U)) {
                popScreen(screenStack, &screenPtr);
            }

            BeginDrawing();

            ClearBackground(RAYWHITE);

            renderScreen(screenStack, screenPtr);

            EndDrawing();

        }

        events_completed++;

    }

    free(eventline);
    free(home_screen);
    // TODO: free GameScreens

    return 0;

}
