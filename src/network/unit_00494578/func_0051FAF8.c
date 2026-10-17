/* compiler: ee-gcc2.96-as2004g */
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
struct W8 {
    u32 w[2];
};

struct Obj {
    s32 unk0;
    char pad4[0xC];
    struct W8 unk10;
    s32 unk18;
    s32 unk1C;
    char pad20[8];
    char blk28[0x2C];
    char h54[1];
};

struct Vt {
    char pad0[0x30];
    s32 (*f30)(s32, s32, u32, s32 *);
    s32 (*f34)(s32, void *, s32 *, s32, s32, s32 *);
    char pad38[0x74 - 0x38];
    s32 (*f74)(struct W8, struct W8);
};

extern struct Vt *D_0064B4B0;

s32 func_00538180(void *, s32);
s32 func_00538460(void *, s32, s32);
s32 func_005385E0(void *, u32 *);
s32 func_005386A0(void *, s32 *);
void func_0053A860(void *);

s32 func_0051FAF8(struct Obj *o)
{
    struct W8 addr;
    u32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 r;
    s32 more;
    s32 mode;

    sp14 = 0;
    sp10 = 0;
    sp18 = 0;
    r = func_00538460(o->h54, 0, 0);
    if (r != 0) {
        return r;
    }
    func_005385E0(o->h54, &sp10);
    if (sp10 != 0) {
    do {
        sp18 = 0;
        more = 0;
        r = func_005386A0(o->h54, &sp14);
        if (r != 0) {
            return r;
        }
        mode = o->unk0;
        if (mode == 0) {
            u32 n = 0x1000;
            if (sp10 < 0x1001) n = sp10;
            r = D_0064B4B0->f30(o->unk1C, sp14, n, &sp18);
            if (r != 0) {
                return r;
            }
            if (sp18 == (s32)n) {
                more = 1;
            }
        } else if (mode == 1) {
            if (sp10 >= 0x248) {
                r = D_0064B4B0->f34(o->unk1C, &addr, &sp1C, sp14, 0x248, &sp18);
                if (r != 0) {
                    return r;
                }
                if (sp18 != 0) {
                    if (sp1C != o->unk18 || D_0064B4B0->f74(addr, o->unk10) == 0) {
                        sp18 = 0;
                    }
                    more = 1;
                }
            }
        } else {
            return 4;
        }
        if (sp18 != 0) {
            func_0053A860(o->blk28);
            r = func_00538180(o->h54, sp18);
            if (r != 0) {
                return r;
            }
        }
        func_005385E0(o->h54, &sp10);
    } while (sp10 != 0 && more);
    }
    return 0;
}
