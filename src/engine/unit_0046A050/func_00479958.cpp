/* Runs a per-element pass over an array of 24-byte elements (pointer and count in the member at +0x28). The flag at +0x6E38 of the
 * second object is raised for the duration of the pass; func_0047E400 fills a 0x40-byte scratch buffer from the block at +0x10,
 * func_004A7698 consumes it, and func_00479A28 is called on every element. func_004A53F8 / func_004A5400 bracket the pass in matching
 * pairs (inferred: enter/leave, they take no arguments). Purpose of the elements unknown. */
#include "types.h"

struct E00479958 {
    char pad0[24];
};

struct Sub00479958 {
    struct E00479958 *first;
    u32 count;
};

struct S00479958 {
    char pad0[0x10];
    char blockA[0x18];
    struct Sub00479958 sub;
};

struct T00479958 {
    char pad0[0x6E38];
    s32 passActive;
};

extern "C" void func_004A53F8(void);
extern "C" void func_0047E400(void *arg0, void *arg1);
extern "C" void func_004A7698(void *arg0);
extern "C" void func_004A5400(void);
extern "C" void func_00479A28(struct E00479958 *arg0, struct T00479958 *arg1);

extern "C" void func_00479958(struct S00479958 *self, struct T00479958 *context) {
    char scratch[0x40];
    struct Sub00479958 *array;
    struct E00479958 *base;
    struct E00479958 *end;
    struct E00479958 *element;

    context->passActive = 1;
    func_004A53F8();
    func_0047E400(self->blockA, scratch);
    func_004A7698(scratch);
    func_004A53F8();
    array = &self->sub;
    base = array->first;
    end = base + array->count;
    element = base;
    if (element != end) {
        do {
            struct E00479958 *current = element;
            element++;
            func_00479A28(current, context);
        } while (element != end);
    }
    func_004A5400();
    func_004A5400();
    context->passActive = 0;
}
