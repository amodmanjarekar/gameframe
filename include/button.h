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

typedef struct GameScreen GameScreen;

void handleMouseClick(Button* btn, GameScreen* game_screen_stack[], GameScreen*** game_screen_ptr, GameScreen* new_game_screen);
void drawButton(Button* btn);
void buttonClick(Button* btn, GameScreen* game_screen_stack[], GameScreen*** game_screen_ptr, GameScreen* new_game_screen);
void getButton(Button *btn,
        int x, int y,
        int width, int height,
        Color bg_clr, Color text_clr, 
        char* text,
        SCREENTYPE buttonType,
        int btn_id);

#endif // !BUTTON_H_
