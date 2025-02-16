#include "../../../include/screen.h"
#include <stdio.h>
#include <raylib.h>

GameScreen* homeScreen() {

    GameScreen* gs = (GameScreen*) malloc(sizeof(GameScreen) + 3 * sizeof(Button*));

    Button* home_continue_btn = malloc(sizeof(Button));
    Button* home_options_btn = malloc(sizeof(Button));
    Button* home_exit_btn = malloc(sizeof(Button));

    getButton(home_continue_btn, 100, 100, 145, 50, PURPLE, BLACK, "CONTINUE", HOMESCREEN, 1);
    getButton(home_options_btn, 100, 155, 145, 50, BLACK, WHITE, "OPTIONS", HOMESCREEN, 2);
    getButton(home_exit_btn, 100, 210, 145, 50, BLACK, WHITE, "EXIT", HOMESCREEN, 3);

    // TODO: home_continue_btn->buttonOnPress = pushScreen();

    gs->width = 1280;
    gs->height = 720;
    gs->screenType = HOMESCREEN;
    gs->backgroundImage = LoadTexture("/home/arhant/Sandbox/c/tryhere/gameframe/src/screens/home_screen/sans.png");
    gs->trackPath = "/home/arhant/Sandbox/c/tryhere/gameframe/src/screens/home_screen/home_track.mp3";
    gs->numButtons = 3;
    gs->arrayOfButtons[0] = home_continue_btn;
    gs->arrayOfButtons[1] = home_options_btn;
    gs->arrayOfButtons[2] = home_exit_btn;
    printf("%s\n", GetWorkingDirectory());

    gs->track = LoadMusicStream(gs->trackPath);
    PlayMusicStream(gs->track);

    return gs;

}
