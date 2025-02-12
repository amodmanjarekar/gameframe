#ifndef SCREEN_H_
#define SCREEN_H_

#include "../include/button.h"

typedef struct GameScreen {
    int width;
    int height;
    SCREENTYPE screenType;
    Button list[];
} GameScreen;

#endif // !SCREEN_H_
