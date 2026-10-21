/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned int u32;

struct Ctl {
    char pad0[0xC];
    s32 f0C;
    char pad10[0x8];
    u32 f18;
    u32 f1C;
};

extern struct Ctl D_00875878;

extern s32 func_00584538(u32, s32, s32);
extern void func_005850C0(void);
extern void func_0058B150(u32 *, u32 *);
extern s32 func_005B72A8(void);
extern int func_005B72F8(void);

s32 func_005843A0(u32 arg0, s32 arg1, s32 arg2)
{
    struct Ctl *c = &D_00875878;
    s32 temp_s4;
    s32 temp_s0;
    u32 sp0;
    u32 sp4;

    if (c->f0C == 0 || arg0 >= 6) {
        return 0;
    }
    temp_s4 = func_005B72A8();
    temp_s0 = func_00584538(arg0, arg1, arg2);
    func_005850C0();
    if (c->f18 != 0xFFFFFFFFu) {
        func_0058B150(&sp0, &sp4);
        if (sp0 < c->f18) {
            c->f18 = sp0;
        }
        if (sp0 < c->f1C) {
            c->f1C = sp4;
        }
    }
    if (temp_s4 != 0) {
        func_005B72F8();
    }
    return temp_s0;
}
