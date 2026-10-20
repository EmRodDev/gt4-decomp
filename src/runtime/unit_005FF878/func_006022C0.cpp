typedef int s32;

struct S12 {
    s32 a;
    s32 b;
    s32 c;
};

struct Obj {
    char pad[0x16A4];
    s32 unk16A4;
};

extern "C" void func_006022C0(Obj *arg0, S12 *arg1) {
    s32 spare[4];
    s32 old = arg0->unk16A4;
    S12 *target = (S12 *)((char *)arg0 + 0x16A4);
    *target = *arg1;
    arg0->unk16A4 = old;
}
