#include "types.h"

struct RaceDisplay {
    char pad0[0x17BC];
    char event_display[0x2D14 - 0x17BC];
    char car_icon_display[1];
};

extern "C" void RaceEventDisplay__clear(void *arg0, float arg1);
extern "C" void RaceCarIconDisplay__clear(void *arg0);

extern "C" void RaceDisplay__clear(struct RaceDisplay *arg0) {
    RaceEventDisplay__clear(arg0->event_display, 0.0f);
    RaceCarIconDisplay__clear(arg0->car_icon_display);
}
