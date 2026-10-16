/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Ent { char pad0[4]; s32 f4; char pad8[0x24]; s32 f2C; char pad30[0xC]; };
struct Group { char pad[0x78]; s32 cur; };
struct T {
    char pad0[0x2C]; s32 f2C; char pad30[0xC];
};

extern "C" void func_001053F8(void *, s32);
extern "C" void func_00105460(void *, s32, s32);
extern "C" void func_001054A0(void *, s32);
extern "C" void func_001060F8(T *, s32, s32, s32);
extern "C" void func_00106258(T *, s32, s32);
extern "C" void func_004AA478(void);
extern "C" s32 func_004AA570(s32, s32);

#define E(g, k) ((Ent *)((char *)(g) + (k) * 0x3C))

extern "C" void func_00106EE8(char *arg0, u32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Group *g0 = (Group *)(arg0 + 0x3C);
    Group *g1 = (Group *)(arg0 + 0xB8);
    s32 half;
    s32 buf;
    func_004AA478();
    s32 mul = 2;
    if (arg1 >= 2U) mul = 1;
    g0->cur = 0;
    s32 unit = 64 / mul;
    s32 size = ((arg2 + 63) & -64) * ((arg3 + unit - 1) & -unit);
    half = (size * mul) >> 1;
    buf = func_004AA570(half + size, 0);
    s32 end = buf + half;
    *(s32 *)(arg0 + 0x170) = buf;
    func_001053F8(E(g0, g0->cur), buf);
    { Ent *e = E(g0, g0->cur); e->f4 = arg1; }
    func_00105460(E(g0, g0->cur), arg2, arg3);
    func_001054A0(E(g0, g0->cur), arg4);
    { Ent *e = E(g0, g0->cur); e->f2C = 0; }
    func_001053F8(E(g0, (1 - g0->cur)), buf + size);
    { Ent *e = E(g0, (1 - g0->cur)); e->f4 = arg1; }
    func_00105460(E(g0, (1 - g0->cur)), arg2, arg3);
    func_001054A0(E(g0, (1 - g0->cur)), arg4);
    { Ent *e = E(g0, (1 - g0->cur)); e->f2C = 0; }
    func_001053F8(E(g1, g1->cur), buf);
    { Ent *e = E(g1, g1->cur); e->f4 = 0x31; }
    func_00105460(E(g1, g1->cur), arg2, arg3);
    func_001054A0(E(g1, g1->cur), arg4);
    { Ent *e = E(g1, g1->cur); e->f2C = 0; }
    func_001053F8(E(g1, (1 - g1->cur)), end);
    { Ent *e = E(g1, (1 - g1->cur)); e->f4 = 0x31; }
    func_00105460(E(g1, (1 - g1->cur)), arg2, arg3);
    func_001054A0(E(g1, (1 - g1->cur)), arg4);
    { Ent *e = E(g1, (1 - g1->cur)); e->f2C = 0; }
    if (mul >= 2) {
        func_001053F8(arg0 + 0x134, -1);
    } else {
        Ent *e = (Ent *)(arg0 + 0x134);
        func_001053F8(e, end);
        e->f4 = arg1 == 2 ? 0x32 : 0x3A;
        func_00105460(e, arg2, arg3);
        func_001054A0(e, arg4);
        e->f2C = 0;
    }
    ((T *)arg0)->f2C = arg1;
}
