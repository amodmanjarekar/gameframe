#ifndef BUTTON_H_
#define BUTTON_H_

#include <raylib.h>

typedef struct GameScreen GameScreen;

typedef enum SCREENTYPE {
    HOMESCREEN,
    GAMESCREEN,
    GAMEPLAYSCREEN,
    OPTIONSCREEN,
    CONTROLSCREEN
} SCREENTYPE;

typedef struct Button {
    Rectangle buttonRec;
    Color buttonBgColor;
    Color buttonTextColor;
    char* buttonText;
    SCREENTYPE buttonType;
    int buttonID;
    GameScreen* buttonTargetScreen;
    void (*buttonOnPress)();
} Button;

typedef struct GameScreen GameScreen;

void handleMouseClick(Button* btn, GameScreen **game_screen_stack, GameScreen ***game_screen_ptr);
void drawButton(Button* btn);
void buttonClick(Button* btn, GameScreen **game_screen_stack, GameScreen ***game_screen_ptr);
void setButtonTargetScreen(Button* btn, GameScreen* targetScreen);
void getButton(Button *btn,
        int x, int y,
        int width, int height,
        Color bg_clr, Color text_clr, 
        char* text,
        SCREENTYPE buttonType,
        int btn_id);

#endif // !BUTTON_H_
