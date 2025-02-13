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
    void (*buttonOnPress)();
} Button;

void handleMouseClick(Button* btn);
void drawButton(Button* btn);
void buttonClick(Button* btn);
void getButton(Button *btn,
        int x, int y,
        int width, int height,
        Color bg_clr, Color text_clr, 
        char* text,
        SCREENTYPE buttonType,
        int btn_id);

#endif // !BUTTON_H_
