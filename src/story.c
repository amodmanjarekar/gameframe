#include "../include/game_event.h"
#include "../include/player.h"

int eventNullCondition(Player* p) {
    return 0;
}

int eventTrueCondition(Player* p) {
    return 1;
}

int event1Condition(Player* p) {
    return p->isEmployed ? 1 : 0;
}

int event2Condition(Player* p) {
    return (p->totalCash >= 100) ? 1 : 0;
}

int event3Condition(Player* p) {
    return (p->totalCash >= 200) ? 1 : 0;
}

// event4 -> NULL

int event5Condition(Player* p) {
    return (p->totalCash >= 500) ? 1 : 0;
}

void updateEvent(Event* eventline) {

    eventline[0].eventType = INFO;
    eventline[0].eventCutScenes = NULL;
    eventline[0].eventNumCutScenes = 0;
    eventline[0].eventInfo = "JOHN NEEDS TO GET A JOB!";
    eventline[0].eventCondtion = event1Condition;
    eventline[0].eventTimeout = 0;

    eventline[1].eventType = INFO;
    eventline[1].eventCutScenes = NULL;
    eventline[1].eventNumCutScenes = 0;
    eventline[1].eventInfo = "JOHN NEEDS TO EARN 100$";
    eventline[1].eventCondtion = event2Condition;
    eventline[1].eventTimeout = 0;

    eventline[2].eventType = INFO;
    eventline[2].eventCutScenes = NULL;
    eventline[2].eventNumCutScenes = 0;
    eventline[2].eventInfo = "JOHN NEEDS TO EARN 200$";
    eventline[2].eventCondtion = event3Condition;
    eventline[2].eventTimeout = 0;

    eventline[3].eventType = UPDATE;
    eventline[3].eventCutScenes = NULL;
    eventline[3].eventNumCutScenes = 0;
    eventline[3].eventInfo = "SHOP IS NOW OPEN";
    eventline[3].eventCondtion = eventNullCondition;
    eventline[3].eventTimeout = 10;
    
    eventline[4].eventType = INFO;
    eventline[4].eventCutScenes = NULL;
    eventline[4].eventNumCutScenes = 0;
    eventline[4].eventInfo = "GET SOME MORE CASH";
    eventline[4].eventCondtion = event5Condition;
    eventline[4].eventTimeout = 0;

}
