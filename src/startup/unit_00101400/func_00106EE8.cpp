/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Allocates one block (func_004AA570) and carves it into a set of double-buffered image descriptors (shape inferred from the
 * alignment arithmetic and the cur / 1 - cur indexing): width is rounded up to a multiple of 64 and height to a multiple of 64/mul,
 * where mul is 2 for modes below 2 and 1 otherwise. Group 0 (+0x3C) and group 1 (+0xB8) each get two 0x3C-byte entries (the current one
 * and its partner) initialised with func_001053F8 (base address), sizes via func_00105460 (width, height) and func_001054A0
 * (the last argument); group 0 entries store the mode in their field at +4, group 1 entries the constant 0x31. A third entry at +0x134
 * is either marked unused (-1, when mul >= 2) or placed after the group 1 half and given mode 0x32 / 0x3A. The block address
 * is kept at +0x170 and the mode at +0x2C. The meaning of the mode values is unknown. */
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
extern "C" void func_004AA478(void);
extern "C" s32 func_004AA570(s32, s32);

#define E(g, k) ((Ent *)((char *)(g) + (k) * 0x3C))

extern "C" void func_00106EE8(char *self, u32 mode, s32 width, s32 height, s32 setting) {
    Group *g0 = (Group *)(self + 0x3C);
    Group *g1 = (Group *)(self + 0xB8);
    s32 half;
    s32 buf;
    func_004AA478();
    s32 mul = 2;
    if (mode >= 2U) mul = 1;
    g0->cur = 0;
    s32 unit = 64 / mul;
    s32 size = ((width + 63) & -64) * ((height + unit - 1) & -unit);
    half = (size * mul) >> 1;
    buf = func_004AA570(half + size, 0);
    s32 end = buf + half;
    *(s32 *)(self + 0x170) = buf;
    func_001053F8(E(g0, g0->cur), buf);
    { Ent *e = E(g0, g0->cur); e->f4 = mode; }
    func_00105460(E(g0, g0->cur), width, height);
    func_001054A0(E(g0, g0->cur), setting);
    { Ent *e = E(g0, g0->cur); e->f2C = 0; }
    func_001053F8(E(g0, (1 - g0->cur)), buf + size);
    { Ent *e = E(g0, (1 - g0->cur)); e->f4 = mode; }
    func_00105460(E(g0, (1 - g0->cur)), width, height);
    func_001054A0(E(g0, (1 - g0->cur)), setting);
    { Ent *e = E(g0, (1 - g0->cur)); e->f2C = 0; }
    func_001053F8(E(g1, g1->cur), buf);
    { Ent *e = E(g1, g1->cur); e->f4 = 0x31; }
    func_00105460(E(g1, g1->cur), width, height);
    func_001054A0(E(g1, g1->cur), setting);
    { Ent *e = E(g1, g1->cur); e->f2C = 0; }
    func_001053F8(E(g1, (1 - g1->cur)), end);
    { Ent *e = E(g1, (1 - g1->cur)); e->f4 = 0x31; }
    func_00105460(E(g1, (1 - g1->cur)), width, height);
    func_001054A0(E(g1, (1 - g1->cur)), setting);
    { Ent *e = E(g1, (1 - g1->cur)); e->f2C = 0; }
    if (mul >= 2) {
        func_001053F8(self + 0x134, -1);
    } else {
        Ent *e = (Ent *)(self + 0x134);
        func_001053F8(e, end);
        e->f4 = mode == 2 ? 0x32 : 0x3A;
        func_00105460(e, width, height);
        func_001054A0(e, setting);
        e->f2C = 0;
    }
    ((T *)self)->f2C = mode;
}
