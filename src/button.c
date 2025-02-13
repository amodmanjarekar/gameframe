#include "../include/button.h"
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

void buttonClick(Button* btn) {

    Vector2 mouse = GetMousePosition();

    if (CheckCollisionPointRec(mouse, btn->buttonRec)) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            handleMouseClick(btn);
        }
    }

}

void handleMouseClick(Button* btn) {
    printf("CLICKED %s\n", btn->buttonText);
}
