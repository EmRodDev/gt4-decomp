/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Replays the stored speed events of a race into the display: a RaceDisplaySpeedEvent is built on the stack, and for as many entries as the info
 * block counts for the event's type (the type comes from the event's virtual at vtable slot 1; the counts are the bytes at info+0x8FC onward),
 * the event id is set and 003A3248 fills the event for entry i; when it reports success the resulting value is handed to 003A12A0 on the display.
 * The reading of the counts as one list per event type is inferred from the indexing; what an event stands for is purpose unknown. */
typedef int s32;
typedef float f32;
typedef short s16;
typedef unsigned char u8;

struct VEntry {
    short delta;
    short index;
    int (*fn)(void *);
};

static inline int vcall1(VEntry *vtbl, void *o) {
    VEntry *e = &vtbl[1];
    return e->fn((char *)o + e->delta);
}

struct Event {
    int id;
    VEntry *vtbl;
    f32 value;
    int kind;
};

struct Sub {
    char pad[0x800];
    u8 counts[1];
    int count(int t) { return counts[t]; }
};

struct Info {
    char pad0[0xFC];
    Sub sub;
};

extern "C" void RaceDisplaySpeedEvent__structor_0(Event *);
extern "C" int func_003A3248(Event *, Info *, int);
extern "C" void func_003A12A0(void *, f32);

extern "C" void func_003A0600(void *self, Info *raceInfo, int eventId) {
    Event event;
    RaceDisplaySpeedEvent__structor_0(&event);
    for (int i = 0; i < raceInfo->sub.count(vcall1(event.vtbl, &event)); i++) {
        event.id = eventId;
        if (func_003A3248(&event, raceInfo, i) != 0) {
            func_003A12A0(self, event.value);
        }
    }
}
