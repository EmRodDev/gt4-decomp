/* compiler: ee-gcc2.96-as2004g */
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long U64 __attribute__((aligned(4)));

struct H { int v; int w; };
struct Addr8 {
    char d[8];
};
struct G {
    struct Addr8 addr[16];
    u32 count;
    s32 res;
};
struct Obj {
    s32 unk0;
    char pad4[8];
    struct H unkC;
    char pad14[0x220 - 0x14];
    void (*cb)(struct G *);
};

extern char D_008638B8[];
extern struct G D_00863AB8;


s32 func_005224B0(struct H *);
s32 func_00521388(s32, struct H *, s32 *, void *, u32, u32 *);
s32 func_005224E8(struct H, struct H);
s32 func_00521CE8(struct Obj *, void *, u32, u32 *, u32 *);
s32 func_00521EF0(struct Obj *, void *, u32, u32 *, struct Addr8 *, u32 *);
void func_00520E60(s32);
void *func_005A48D8(void *, int, unsigned int);

s32 func_00521B38(struct Obj *o)
{
    struct H h[2];
    s32 sp10;
    u32 sp14;
    u32 sp18;
    u32 sp1C;
    s32 r;
    u32 i;

    sp14 = 0;
    sp18 = 0;
    sp1C = 0;
    if (o->cb != 0) {
        func_005224B0(h);
        sp10 = 0;
        func_00521388(o->unk0, h, &sp10, D_008638B8, 0x200, &sp14);
        if (sp14 != 0) {
            func_005A48D8(&D_00863AB8, 0, 0x88);
            r = func_005224E8(h[0], o->unkC);
            if (r == 0) {
                return r;
            }
            if (sp10 != 0x35) {
                return 0;
            }
            if (sp14 < 0xC) {
                return 0;
            }
            r = func_00521CE8(o, D_008638B8, sp14, &sp18, &sp1C);
            if (r != 0) {
                D_00863AB8.res = r;
                o->cb(&D_00863AB8);
                func_00520E60(o->unk0);
                func_005A48D8(o, 0, 0x224);
                return 0;
            }
            {
                for (i = 0; i < sp1C; i++) {
                    r = func_00521EF0(o, D_008638B8, sp14, &sp18, &D_00863AB8.addr[D_00863AB8.count], &D_00863AB8.count);
                    if (r != 0) {
                        D_00863AB8.res = r;
                        o->cb(&D_00863AB8);
                        func_00520E60(o->unk0);
                        func_005A48D8(o, 0, 0x224);
                        return 0;
                    }
                }
            }
            D_00863AB8.res = r;
            o->cb(&D_00863AB8);
            func_00520E60(o->unk0);
            func_005A48D8(o, 0, 0x224);
        }
    }
    return 0;
}
