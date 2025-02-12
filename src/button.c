#include "../include/button.h"
#include <raylib.h>

void drawButton(Button btn) {

    DrawRectangleRec(btn.buttonRec, btn.buttonBgColor);
    DrawText(btn.buttonText, btn.buttonRec.x + 20, btn.buttonRec.y + 15, 20, btn.buttonTextColor);

}

void buttonClick(Button btn) {

    Vector2 mouse = GetMousePosition();

    if (CheckCollisionPointRec(mouse, btn.buttonRec)) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            handleMouseClick();
        }
    }

}

void handleMouseClick() {
}
