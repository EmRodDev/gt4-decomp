typedef int s32;
typedef unsigned int u32;
struct Inner { s32 unk0; };
struct G { char pad0[0x24]; void *unk24; char pad28[4]; Inner *unk2C; };
extern G *D_006452D4;
extern "C" void func_004BC6E8(G *);
extern "C" s32 func_004BEC88(G *, s32);
extern "C" s32 func_004C1458(void *, s32);
extern "C" s32 func_004BBFF0(u32 arg0) {
    G *g = D_006452D4;
    s32 a, b;
    if (g->unk2C->unk0 == 0x65) return 0x80000269;
    if (!(arg0 < 3)) return 0x80000469;
    func_004BC6E8(g);
    a = func_004C1458(D_006452D4->unk24, arg0);
    b = func_004BEC88(D_006452D4, arg0);
    if (a < 0) return a;
    if (b >= 0) return a + b;
    return b;
}
