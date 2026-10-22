/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Resets the game object held in self->g and re-reads a 32-byte block from it. It writes 1/60 (the hex float
 * 0x1.111110p-6) into g+0xCF5C, 0x100 into g+0xE330 and 0 into g+0xE320 (the meaning of the last two is unknown),
 * then calls func_00332530 on the sub-object at self+0x44. When the word at self+0x164 is zero the block is
 * refreshed: a virtual call at g's vtable+0xD0 with index 0 gives an object, a virtual call at that object's
 * vtable+0x1C0 returns a pointer to 8 ints, and they are copied to self+0x144 (a struct copy). When the word at
 * +0x168 is zero, func_00334E38(self) finishes the job. Both vtable entries carry a this-adjustment, hence the
 * small entry structs. */
typedef int s32;
typedef float f32;

struct Blob32 { s32 w[8]; };
struct VEntry1 { short delta; short index; char *(*fn)(void *, s32); };
struct VEntry2 { short delta; short index; Blob32 *(*fn)(void *); };

struct G {
    char pad0[0x64];
    char *vtbl;
    char pad68[0xCF5C - 0x68];
    f32 timeStep;
    char padCF60[0xE320 - 0xCF60];
    s32 uE320;
    char padE324[0xE330 - 0xE324];
    s32 uE330;
};

struct Obj {
    G *g;
    char pad4[0x40];
    char sub[0x100];
    Blob32 b144;
    s32 u164;
    s32 u168;
};

extern "C" void func_00332530(void *);
extern "C" void func_00334E38(void *);

extern "C" void func_00333900(Obj *self) {
    self->g->timeStep = 0x1.111110p-6f;
    self->g->uE330 = 0x100;
    self->g->uE320 = 0;
    func_00332530(&self->sub[0]);
    if (self->u164 == 0) {
        G *g = self->g;
        VEntry1 *entry1 = (VEntry1 *)(g->vtbl + 0xD0);
        char *source = entry1->fn((char *)g + entry1->delta, 0);
        VEntry2 *entry2 = (VEntry2 *)(*(char **)source + 0x1C0);
        Blob32 *blobPtr = entry2->fn(source + entry2->delta);
        self->b144 = *blobPtr;
    }
    if (self->u168 == 0) {
        func_00334E38(self);
    }
}
