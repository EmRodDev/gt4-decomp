/* Worker loop: waits on the semaphore-like object at +0x31D0 (func_00574EB0) until o->f3290 becomes zero, and each time asks func_004AF860 to process the request at f3298 (using the record at +0x329C); a negative return is saved in f32B0 as the error, then the object at +0x3200 is signalled (func_00574EE8). Reading of the +0x31D0/+0x3200 pair as wait/signal is inferred from the call order. */
#include "types.h"

struct Obj {
    char pad0[0x3290];
    s32 f3290;
    char pad3294[4];
    s32 f3298;
    char pad329C[0x14];
    s32 f32B0;
};

extern "C" s32 func_004AF860(s32 a, void *b);
extern "C" void func_00574EB0(void *arg0);
extern "C" void func_00574EE8(void *arg0);

extern "C" void func_004B0668(void *worker) {
    struct Obj *self = (struct Obj *)worker;
    s32 result;

    while (func_00574EB0((char *)self + 0x31D0), self->f3290 != 0) {
        result = func_004AF860(self->f3298, (char *)self + 0x329C);
        if (result < 0) {
            self->f32B0 = result;
        }
        func_00574EE8((char *)self + 0x3200);
    }
}
