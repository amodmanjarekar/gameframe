#ifndef BUTTON_H_
#define BUTTON_H_

#include <raylib.h>

typedef enum SCREENTYPE {
    HOMESCREEN,
    GAMESCREEN,
    GAMEPLAYSCREEN,
    OPTIONSCREEN
} SCREENTYPE;

typedef struct Button {
    Rectangle buttonRec;
    Color buttonBgColor;
    Color buttonTextColor;
    char* buttonText;
    SCREENTYPE buttonType;
    int buttonID;
} Button;

void handleMouseClick();
void drawButton(Button btn);
void buttonClick(Button btn);

#endif // !BUTTON_H_
