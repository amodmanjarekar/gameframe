#ifndef STORY_H_
#define STORY_H_

#include "game_event.h"
#include "shop.h"
#include "player.h"

typedef struct Story {
    Event* storyEventLine;
    Shop storyShop;
    Player storyPlayer;
} Story;

GameEvent next_event(Story* game);

#endif // !STORY_H_
