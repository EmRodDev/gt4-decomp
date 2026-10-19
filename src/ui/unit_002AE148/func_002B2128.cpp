typedef int s32;
typedef float f32;

struct Obj {
    char pad[0xB0];
    s32 unkB0;
    char pad2[0x11C - 0xB0 - 4];
    void *unk11C;
};

extern "C" f32 mWidget__getWindowW(void *widget);
extern "C" f32 mWidget__getWindowH(void *widget);

extern "C" f32 func_002B2128(Obj *arg0) {
    s32 cond = arg0->unkB0;
    void *val = arg0->unk11C;
    if (cond == 0) {
        return mWidget__getWindowW(val);
    }
    return mWidget__getWindowH(val);
}
