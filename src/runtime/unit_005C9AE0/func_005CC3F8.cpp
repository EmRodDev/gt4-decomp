/* Thin wrapper: forwards the pointer-sized field at +0x10 to func_004369E8 and returns its result. */
typedef int s32;

struct Obj {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 func_004369E8(s32 arg0);

extern "C" s32 func_005CC3F8(Obj *self)
{
    return func_004369E8(self->unk10);
}
