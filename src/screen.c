#include "../include/screen.h"

#define SCREEN_LIMIT 5

void pushScreen(GameScreen* game_screen_stack[], GameScreen*** game_screen_ptr, GameScreen* new_game_screen) {

    if (*game_screen_ptr - game_screen_stack >= SCREEN_LIMIT - 1) {
        return;
    }

    (*game_screen_ptr)++;
    **game_screen_ptr = new_game_screen;

}

void popScreen(GameScreen* game_screen_stack[], GameScreen*** game_screen_ptr) {

    if(*game_screen_ptr == game_screen_stack) {
        return;
    }

    (*game_screen_ptr)--;

}

void defaultScreen(GameScreen* game_screen_stack[], GameScreen* new_game_screen) {

    game_screen_stack[0] = new_game_screen;

}

void renderScreen(GameScreen **game_screen_stack, GameScreen ***game_screen_ptr) {

    for(size_t i = 0; i < (**game_screen_ptr)->numButtons; i++) {
        drawButton((**game_screen_ptr)->arrayOfButtons[i]);
        buttonClick((**game_screen_ptr)->arrayOfButtons[i], game_screen_stack, game_screen_ptr);
    }

    DrawTextureEx((**game_screen_ptr)->backgroundImage, (Vector2){200, 200}, 0.0f, 0.5f, WHITE);

}

