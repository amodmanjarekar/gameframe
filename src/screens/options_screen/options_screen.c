#include "../../../include/screen.h"

GameScreen* optionsScreen() {

    GameScreen* gs = (GameScreen*) malloc(sizeof(GameScreen) + 3 * sizeof(Button*));

    Button* options_continue_btn = malloc(sizeof(Button));
    Button* options_options_btn = malloc(sizeof(Button));
    Button* options_exit_btn = malloc(sizeof(Button));

    getButton(options_continue_btn, 200, 100, 145, 50, PURPLE, BLACK, "VOL", OPTIONSCREEN, 1);
    getButton(options_options_btn, 200, 155, 145, 50, BLACK, WHITE, "BLA BLA", OPTIONSCREEN, 2);
    getButton(options_exit_btn, 200, 210, 145, 50, BLACK, WHITE, "CONTROLS", OPTIONSCREEN, 3);

    // TODO: home_continue_btn->buttonOnPress = pushScreen();

    gs->width = 1280;
    gs->height = 720;
    gs->screenType = OPTIONSCREEN;
    gs->backgroundImage = NULL;
    gs->numButtons = 3;
    gs->arrayOfButtons[0] = options_continue_btn;
    gs->arrayOfButtons[1] = options_options_btn;
    gs->arrayOfButtons[2] = options_exit_btn;

    return gs;

}
