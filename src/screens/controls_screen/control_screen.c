#include "../../../include/screen.h"

GameScreen* controlsScreen() {

    GameScreen* gs = (GameScreen*) malloc(sizeof(GameScreen) + 3 * sizeof(Button*));

    Button* controls_continue_btn = malloc(sizeof(Button));
    Button* controls_options_btn = malloc(sizeof(Button));
    Button* controls_exit_btn = malloc(sizeof(Button));

    getButton(controls_continue_btn, 100, 100, 145, 50, PURPLE, BLACK, "KEYBOARD", CONTROLSCREEN, 1);
    getButton(controls_options_btn, 100, 155, 145, 50, BLACK, WHITE, "MOUSE", CONTROLSCREEN, 2);
    getButton(controls_exit_btn, 100, 210, 145, 50, BLACK, WHITE, "BACK", CONTROLSCREEN, 3);

    gs->width = 1280/2;
    gs->height = 720/2;
    gs->screenType = HOMESCREEN;
    gs->backgroundImage = LoadTexture("/home/arhant/Sandbox/c/tryhere/gameframe/src/screens/controls_screen/panda.png");
    gs->trackPath = "/home/arhant/Sandbox/c/tryhere/gameframe/src/screens/home_screen/home_track.mp3";
    gs->numButtons = 3;
    gs->arrayOfButtons[0] = controls_continue_btn;
    gs->arrayOfButtons[1] = controls_options_btn;
    gs->arrayOfButtons[2] = controls_exit_btn;

    gs->track = LoadMusicStream(gs->trackPath);
    PlayMusicStream(gs->track);

    return gs;

}
