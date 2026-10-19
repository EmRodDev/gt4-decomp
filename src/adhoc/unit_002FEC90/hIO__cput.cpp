typedef short s16;
typedef int s32;
typedef signed char s8;

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *, s32);
};

struct Obj {
    char pad0[4];
    VEntry *vtbl;
};

/* Layout backed by include/gt4/hIO.h:
 *   vtable slot 51 (0x198 / 8): write(buf, len)
 */
extern "C" void hIO__cput(struct Obj *arg0, s8 arg1) {
    s8 tmp = arg1;
    VEntry *e = &arg0->vtbl[51];

    e->fn((char *)arg0 + e->delta, &tmp, 1);
}
