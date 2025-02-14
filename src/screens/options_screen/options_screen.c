#include "../../../include/screen.h"

GameScreen* optionsScreen() {

    GameScreen* gs = (GameScreen*) malloc(sizeof(GameScreen) + 3 * sizeof(Button*));

    Button* options_volume_btn = malloc(sizeof(Button));
    Button* options_control_btn = malloc(sizeof(Button));
    Button* options_back_btn = malloc(sizeof(Button));

    getButton(options_volume_btn, 100, 100, 145, 50, PURPLE, BLACK, "VOLUME", OPTIONSCREEN, 1);
    getButton(options_control_btn, 100, 155, 145, 50, BLACK, WHITE, "CONTROLS", OPTIONSCREEN, 2);
    getButton(options_back_btn, 100, 210, 145, 50, BLACK, WHITE, "BACK", OPTIONSCREEN, 3);

    // TODO: home_continue_btn->buttonOnPress = pushScreen();

    gs->width = 1280;
    gs->height = 720;
    gs->screenType = OPTIONSCREEN;
    gs->backgroundImage = LoadTexture("/home/arhant/Sandbox/c/tryhere/gameframe/src/screens/options_screen/hk.png");
    gs->trackPath = "/home/arhant/Sandbox/c/tryhere/gameframe/src/screens/options_screen/Anime Villian.mp3";
    gs->numButtons = 3;
    gs->arrayOfButtons[0] = options_volume_btn;
    gs->arrayOfButtons[1] = options_control_btn;
    gs->arrayOfButtons[2] = options_back_btn;

    gs->track = LoadMusicStream(gs->trackPath);
    PlayMusicStream(gs->track);

    return gs;

}
