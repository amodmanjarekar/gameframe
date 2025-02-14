#ifndef SCREEN_H_
#define SCREEN_H_

#include "../include/button.h"
#include <stdlib.h>

typedef struct GameScreen {
    int width;
    int height;
    SCREENTYPE screenType;
    Texture2D backgroundImage;
    char* trackPath;
    Music track;
    size_t numButtons;
    Button* arrayOfButtons[];
} GameScreen;

void pushScreen(GameScreen* game_screen_stack[], GameScreen*** game_screen_ptr, GameScreen* new_game_screen);
void popScreen(GameScreen* game_screen_stack[], GameScreen*** game_screen_ptr);
void defaultScreen(GameScreen* game_screen_stack[], GameScreen* new_game_screen);
void renderScreen(GameScreen* game_screen_stack[], GameScreen** game_screen_ptr);

#endif // !SCREEN_H_
