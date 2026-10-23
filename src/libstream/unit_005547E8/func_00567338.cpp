/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Slot { int state; unsigned char low : 7; unsigned char high : 1; char pad[3]; };
struct Obj {
    char pad0[0x14];
    int enabled;
    char pad18[0x48];
    void *queue;
    char pad64[8];
    Slot slots[1];
};
extern "C" int func_005657E0(void *queue, int timeout, int *out);
extern "C" int func_00567338(Obj *self, int timeout)
{
    int index[4];
    if (!self->enabled) goto fail;
    if (func_005657E0(self->queue, timeout, index)) { fail: return 0; }
    return self->slots[index[0]].high;
}
