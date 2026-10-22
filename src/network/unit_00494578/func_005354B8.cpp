/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Obj;

struct VtA {
    char pad0[8];
    void (*f8)(Obj *);
    char pad0C[0x18 - 0xC];
    s32 (*f18)();
};
struct VtB {
    char pad0[0x38];
    void (*f38)(s32);
};
struct VtC {
    char pad0[0x60];
    void (*f60)(s32);
};
struct VtD {
    char pad0[0x1C];
    int (*f1C)(s32);
    char pad20[0x6C - 0x20];
    void (*f6C)(void *);
};
struct Sys {
    char pad0[0x50];
    char blk[8];
    s32 unk58;
};
struct Arg {
    Obj *self;
    s32 a4;
    s32 a8;
    s32 aC;
    s32 a10;
};
struct Obj {
    char pad0[0x12C];
    void (*cb)(Arg *);
    s32 unk130;
    char pad134[0x144 - 0x134];
    s32 state;
    char pad148[0x158 - 0x148];
    s32 unk158;
    char pad15C[4];
    s32 unk160;
    s32 unk164;
    char pad168[0x17C - 0x168];
    u8 unk17C;
    char pad17D[3];
    char blk[1];
};

extern VtA *D_0064B4AC;
extern VtB *D_0064B4B8;
extern VtC *D_0064B4BC;
extern VtD *D_0064B4A8;
extern VtD *D_0064B4B0;
extern Sys *D_0064B47C;
extern s32 D_0064B4F0;
extern s32 D_0064B4F4;

extern "C" {
s32 func_00535A48(Obj *);
int func_0053A860(void *);
int func_0053A890(void *, u32 *);
void *func_005A48D8(void *, int, unsigned int);
}

extern "C" s32 func_005354B8(Obj *o)
{
    Arg a;
    if (o == 0) {
        return 0x17;
    }
    if (D_0064B4AC != 0 && D_0064B4AC->f18() != 0) {
        D_0064B4AC->f8(o);
    }
    if ((u32)(o->state - 1) < 4) {
        o->state = 5;
        if (D_0064B4F0 != 0 && o->unk158 == 2) {
            D_0064B4B8->f38(o->unk164);
            char *timer;
            if (o->cb == 0) {
                timer = o->blk;
                func_0053A860(timer);
                for (;;) {
                    u32 sp20;
                    D_0064B4BC->f60(D_0064B4F4);
                    func_0053A890(timer, &sp20);
                    if (sp20 >= 0x1F4) break;
                }
            } else {
                func_0053A860(o->blk);
                o->unk17C = 1;
            }
        }
        if (o->unk158 != 2) {
            D_0064B4A8->f1C(o->unk160);
            if (o->cb != 0) {
                o->state = 0;
                func_005A48D8(&a, 0, 0x14);
                a.self = o;
                a.a10 = o->unk130;
                a.a4 = 0;
                a.a8 = 0;
                a.aC = 0;
                o->cb(&a);
            }
        }
        if (o->unk17C == 0) {
            func_00535A48(o);
        }
    }
    D_0064B4B0->f6C(D_0064B47C->blk);
    D_0064B47C->unk58 = 0;
    return 0;
}
