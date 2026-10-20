#include "types.h"

struct EventQueue {
    char pad[0xF4];
    char event_queue[0x20];
};

extern "C" void func_003B76F0(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void ResultArcade__postStartResultSequence(void *arg0, EventQueue *arg1) {
    func_003B76F0(arg1->event_queue, 0x17, 0, 0);
}
