#include <stdlib.h>
#include <stdio.h>

#include "./story.c"

#define TOTAL_EVENTS 4

int main() {

    Player john = {
        .isEmployed = false,
        .totalCash = 0,
        .hasItem = 0,
    };

    Event* eventline = (Event*) malloc(sizeof(Event) * TOTAL_EVENTS);

    updateEvent(eventline);

    int events_completed = 0;
    int text_input = 0;

    do {

        do {

            switch (eventline[events_completed].eventType) {

                case CUTSCENE:
                    break;

                case INFO:
                    printf("%s\n", eventline[events_completed].eventInfo);
                    scanf("%d", &text_input);

                    if (text_input == 1) {
                        john.isEmployed = true;
                    }

                    if (text_input == 100) {
                        john.totalCash = 100;
                    } 

                    if (text_input == 200) {
                        john.totalCash = 200;
                    } 

                    break;

                case UPDATE:
                    printf("%s\n", eventline[events_completed].eventInfo);
                    break;

                default:
                    break;

            }

        } while(eventline[events_completed].eventCondtion(&john) != 1);

        events_completed++;

    } while(events_completed < TOTAL_EVENTS);

    free(eventline);

    return 0;

}
