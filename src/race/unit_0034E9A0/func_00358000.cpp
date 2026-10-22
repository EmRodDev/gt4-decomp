/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Pylon-touch handler of a dynamics conductor (inferred from the call to
 * DynamicsConductor__GetNumberOfPylonsToBeTouched). Does nothing and returns 0 unless carIndex is 0, the info
 * block's fields at +0xDC and +0xE0 are zero, the flag byte at +0xCBDC is zero, the tag differs from the sentinel
 * 0x157529FF and is below the limit at info+0x968. Then, if the virtual query at vtable+0x30 (vtable at +0x10140)
 * is non-zero and no pylons remain to be touched, the touched flag at info+0x98 is set to 1; when the active word
 * at info+0x88 is non-zero, func_0035DF80 is called with 0x16 and the car index (an event code, inferred). Returns
 * 1. The meaning of the tag is unknown. */
struct State { int active; char pad[12]; int touched; };
struct Info { char pad0[0x88]; State state; char pad1[0xdc-0x9c]; int dc; int e0; char pad2[0x968-0xe4]; unsigned int limit; };
struct Obj { Info *info; char pad0[0xcbdc-4]; unsigned char flag; char pad1[0x10140-0xcbdd]; char *vt; };
struct Entry { short delta; short index; int (*fn)(void *); };
extern "C" unsigned char DynamicsConductor__GetNumberOfPylonsToBeTouched(void *);
extern "C" void func_0035DF80(char *, int, int, int);
extern "C" int func_00358000(Obj *self, int carIndex, unsigned int tag) {
    if (carIndex != 0) return 0;
    Info *info = self->info;
    if (info->dc != 0) return 0;
    if (self->flag != 0) return 0;
    if (info->e0 != 0) return 0;
    if (tag == 0x157529ff) return 0;
    if (tag >= info->limit) return 0;
    State *state = &info->state;
    Entry *entry = (Entry *)(self->vt + 0x30);
    if (entry->fn((char *)self + entry->delta) != 0 && DynamicsConductor__GetNumberOfPylonsToBeTouched(self) == 0)
        state->touched = 1;
    if (state->active != 0)
        func_0035DF80((char *)info, 0x16, carIndex, 0);
    return 1;
}
