#include "./screen.c"
#include <stdio.h>

void getButton(
        Button *btn,
        int x, int y,
        int width, int height,
        Color bg_clr, Color text_clr,
        char* text,
        SCREENTYPE buttonType,
        int btn_id) {

        btn->buttonType = buttonType,
        btn->buttonRec.x = x,
        btn->buttonRec.y = y,
        btn->buttonRec.width = width,
        btn->buttonRec.height = height,
        btn->buttonBgColor = bg_clr,
        btn->buttonTextColor = text_clr,
        btn->buttonText = text,
        btn->buttonID = btn_id;
        btn->buttonOnPress = NULL;

}

void drawButton(Button* btn) {

    DrawRectangleRec(btn->buttonRec, btn->buttonBgColor);
    DrawText(btn->buttonText, btn->buttonRec.x + 20, btn->buttonRec.y + 15, 20, btn->buttonTextColor);

}

void buttonClick(Button* btn, GameScreen **game_screen_stack, GameScreen ***game_screen_ptr) {

    Vector2 mouse = GetMousePosition();

    if (CheckCollisionPointRec(mouse, btn->buttonRec)) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            handleMouseClick(btn, game_screen_stack, game_screen_ptr);
        }
    }

}

void setButtonTargetScreen(Button* btn, GameScreen* targetScreen) {

    btn->buttonTargetScreen = targetScreen;

}

void handleMouseClick(Button* btn, GameScreen **game_screen_stack, GameScreen ***game_screen_ptr) {

    switch(btn->buttonType) {

        case HOMESCREEN:

            switch (btn->buttonID) {

                case 1:
                    break;

                case 2:
                    pushScreen(game_screen_stack, game_screen_ptr, btn->buttonTargetScreen);
                    break;

                case 3:
                    // TODO: FREE FUNCTION CALL
                    exit(0);
                    break;
            
            }

            break;

        case GAMESCREEN:
            break;

        case GAMEPLAYSCREEN:
            break;

        case OPTIONSCREEN:

            switch (btn->buttonID) {

                case 1:
                    break;

                case 2:
                    break;

                case 3:
                    popScreen(game_screen_stack, game_screen_ptr);
                    break;
            
            }

            break;

    }

}
