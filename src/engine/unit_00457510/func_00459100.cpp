/* Fixes up an object after it moved in memory (shape inferred): the field at +4 remembers the address the object had when its inner
 * pointers were last valid, so offset = current address - remembered address. If it is non-zero, the remembered address is updated
 * and each non-null pointer at +0x10 and +0x14 is shifted by that offset and passed to func_00454410 / func_00458238 respectively. */
#include "types.h"

struct Node {
    char pad0[4];
    Node *lastAddress;
    char pad8[0x4];
    s32 unkC;
    s32 pointerA;
    s32 pointerB;
};

extern "C" void func_00454410(s32 arg0);
extern "C" void func_00458238(s32 arg0);

extern "C" void func_00459100(Node *self) {
    s32 offset = (char *)self - (char *)self->lastAddress;
    if (offset != 0) {
        self->lastAddress = self;
        if (self->pointerA != 0) {
            s32 *firstPtr = (s32 *)((char *)self + 0x10);
            *firstPtr = *firstPtr + offset;
            func_00454410(*firstPtr);
        }
        if (self->pointerB != 0) {
            s32 *secondPtr = (s32 *)((char *)self + 0x14);
            *secondPtr = *secondPtr + offset;
            func_00458238(*secondPtr);
        }
    }
}
