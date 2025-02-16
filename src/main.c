#include "./story.c"
#include "./button.c"

#include "./screens/home_screen/home_screen.c"
#include "./screens/options_screen/options_screen.c"
#include "./screens/controls_screen/control_screen.c"

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
    GameScreen* control_screen = controlsScreen();

    defaultScreen(screenStack, home_screen);

    setButtonTargetScreen(home_screen->arrayOfButtons[1], options_screen);
    setButtonTargetScreen(options_screen->arrayOfButtons[1], control_screen);

    //----------------------------------------

    while(!WindowShouldClose()) {

        while(eventline[events_completed].eventCondtion(&john, eventline[events_completed].eventId) != 1) {

            UpdateMusicStream((*screenPtr)->track);

            handleEvent(eventline, events_completed);
            handleKey(GetKeyPressed(), &john);

            BeginDrawing();

            ClearBackground(RAYWHITE);

            renderScreen(screenStack, &screenPtr);

            EndDrawing();

        }

        events_completed++;

    }

    free(eventline);
    free(home_screen);
    CloseAudioDevice();
    // TODO: free GameScreens

    return 0;

}
