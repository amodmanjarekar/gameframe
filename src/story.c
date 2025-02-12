#include "../include/game_event.h"
#include "../include/player.h"

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
