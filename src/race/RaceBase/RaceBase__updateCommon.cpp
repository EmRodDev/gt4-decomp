/* compiler: ee-gcc2.96-nsa-nogcse */
/* Partial layouts from RaceEventQueue construction/accessors and this dispatcher.
 * Event IDs and mode keys retain their numeric values pending enum recovery. */
struct EventRecord { short id, reserved; int value; };
struct EventQueue {
    int lock[2];
    EventRecord records[256];
    unsigned char references[28];
    int count;
    void *vtable;
};
struct Controller {
    char unknown0[0xF4];
    EventQueue events;
};
class RaceMode {
public:
    int unknown0;
    virtual ~RaceMode();
    virtual void unknown1();
    virtual void unknown2();
    virtual void unknown3();
    virtual void set(int key, bool special);
    virtual void previous();
    virtual void next();
    virtual void toggle();
};
struct RaceBase {
    char unknown0[0x64];
    char *vtable;
    int unknown68;
    Controller *controller;
    int unknown70;
    RaceMode *mode;
    char unknown78[0xD60 - 0x78];
    int primaryMode;
    int alternateMode;
};
/* GCC's vtable entries carry a signed this adjustment before the function.
 * These event handlers return void, as their recovered implementations show. */
struct EventEntry { short delta, index; void (*call)(void *); };
struct GoalEntry { short delta, index; void (*call)(void *, int); };
static inline void raceEvent(RaceBase *self, int offset) {
    char *table = self->vtable;
    EventEntry *entry = (EventEntry *)(table + offset);
    entry->call((char *)self + entry->delta);
}
static inline void goalEvent(RaceBase *self, int value) {
    char *table = self->vtable;
    GoalEntry *entry = (GoalEntry *)(table + 0x150);
    entry->call((char *)self + entry->delta, value);
}
extern "C" void RaceEventQueue__update(EventQueue *);
extern "C" int RaceEventQueue__get(EventQueue *, int, int *, int);
extern "C" void RaceEventQueue__clear(EventQueue *, int);
extern "C" int RaceEventQueue__check(EventQueue *, int, int *, int);
extern "C" int RaceBase__updateCommon(RaceBase *self) {
    Controller *controller = self->controller;
    RaceMode *mode = self->mode;
    EventQueue *queue = &controller->events;
    RaceEventQueue__update(queue);
    if (RaceEventQueue__get(queue, 7, 0, 1)) raceEvent(self, 0x148);
    if (RaceEventQueue__get(queue, 1, 0, 1)) {
        raceEvent(self, 0x280);
        return 0;
    }
    int startPending = controller->events.references[4];
    if (startPending > 0) raceEvent(self, 0x278);
    RaceEventQueue__clear(queue, 4);
    int key;
    if (RaceEventQueue__get(queue, 24, &key, 1)) {
        const int selection = key;
        switch (selection) {
        case -1: mode->toggle(); break;
        case -2: mode->previous(); break;
        case -3: mode->next(); break;
        case 10: case 19:
            key = self->primaryMode;
            mode->set(key, key == 12);
            break;
        case 11:
            key = self->alternateMode;
            mode->set(key, key == 12);
            break;
        default: mode->set(selection, selection == 12); break;
        }
    }
    /* Callbacks may change the goal count; reread it after each notification. */
    unsigned char *count = &controller->events.references[5];
    int i = 0;
    if (*count) {
        EventQueue *goals = &controller->events;
        int value;
        int *result = &value;
        do {
            if (RaceEventQueue__check(goals, 5, result, i)) goalEvent(self, value);
            ++i;
        } while (i < *count);
    }
    return 1;
}
