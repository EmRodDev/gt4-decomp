/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct mRenderContextPS2Layout {
    char pad[0x4];
    VEntry *vtbl;
    char pad8[0x1D5C - 8];
    s32 rect_data[8];
};

extern "C" void func_00105728(s32 *arg0);

extern "C" void mRenderContextPS2__virtual_70(mRenderContextPS2Layout *self) {
    VEntry *e = &self->vtbl[58];
    e->fn((char *)self + e->delta);
    func_00105728(self->rect_data);
}
