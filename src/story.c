#include <stdlib.h>

#include "../include/game_event.h"
#include "../include/player.h"

#define TOTAL_EVENTS 5

#define WIDTH 1280
#define HEIGHT 720

int eventNullCondition(Player* p, size_t eventId) {
    return 0;
}

int eventTrueCondition(Player* p, size_t eventId) {
    return 1;
}

int eventCondition(Player* p, size_t eventId) {

    switch (eventId) {
        case 0: return 1;
        case 1: return (p->isEmployed) ? 1 : 0;
        case 2: return (p->totalCash >= 100) ? 1 : 0;
        case 3: return (p->totalCash >= 200) ? 1 : 0;

        default: return 0;
        case -1: return 0;
    }

}

void updateEvent(Event* eventline) {

    eventline[0].eventType = INFO;
    eventline[0].eventCondtion = eventCondition;
    eventline[0].eventTimeout = 0;
    eventline[0].eventInfo.eventText = "JOHN NEEDS TO GET A JOB!";
    eventline[0].eventId = 1;

    eventline[1].eventType = INFO;
    eventline[1].eventCondtion = eventCondition;
    eventline[1].eventTimeout = 0;
    eventline[1].eventInfo.eventText = "EARN 100$";
    eventline[1].eventId = 2;

    eventline[2].eventType = INFO;
    eventline[2].eventCondtion = eventCondition;
    eventline[2].eventTimeout = 0;
    eventline[2].eventInfo.eventText = "EARN 200$";
    eventline[2].eventId = 3;

    eventline[3].eventType = UPDATE;
    eventline[3].eventCondtion = eventCondition;
    eventline[3].eventTimeout = 10;
    eventline[3].eventInfo.eventText = "SHOP IS NOW OPEN";
    eventline[3].eventId = -1;

    eventline[4].eventType = INFO;
    eventline[4].eventCondtion = eventCondition;
    eventline[4].eventTimeout = 0;
    eventline[4].eventInfo.eventText = "SIGMA SIGMA BOI";
    eventline[4].eventId = 5;

}

void handleEvent(Event* eventline, int events_completed) {

    switch (eventline[events_completed].eventType) {

        case CUTSCENE:
            break;

        case INFO:

            DrawRectangle(10, HEIGHT-60, WIDTH-20, 50, BLACK);
            DrawText(eventline[events_completed].eventInfo.eventText, 20, HEIGHT-50, 30, WHITE);

            break;

        case UPDATE:

            DrawRectangle(10, HEIGHT-60, WIDTH-20, 50, PURPLE);
            DrawText(eventline[events_completed].eventInfo.eventText, 20, HEIGHT-50, 30, WHITE);

            if (eventline[events_completed].eventTimeout < 0) {
                eventline[events_completed].eventCondtion = eventTrueCondition;
            } else {
                eventline[events_completed].eventTimeout -= 0.009f;
            }

            break;

        default:

            break;

    }

}

void handleKey(int key, Player* p) {

    switch(key) {

        case KEY_F:
            p->isEmployed = true;
            break;

        case KEY_G:
            p->totalCash = 100;
            break;

        case KEY_H:
            p->totalCash = 200;
            break;

        case KEY_J:
            p->totalCash = 700;
            break;
        case KEY_ESCAPE:
            exit(0);

    }

}
