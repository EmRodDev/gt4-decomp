/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
typedef int s32;

struct G {
    char p0[0x20];
    s32 f20;
    s32 f24;
    s32 f28;
};

extern struct G D_00875898;
extern char D_00586888[];
u32 func_005843A0(u32, s32, s32);
void func_005A48D8(void *, s32, unsigned int);
int func_005B9390(u32, void *, s32);

s32 func_00585268(s32 n) {
    s32 s1;
    s32 r;
    s1 = n * 0x48;
    r = func_005843A0(0, s1, 0);
    D_00875898.f24 = r;
    if (r == 0)
        return (s32)0x8105000C;
    D_00875898.f28 = n;
    D_00875898.f20 = 1;
    func_005A48D8((void *)r, 0, s1);
    func_005B9390(0x8000000B, D_00586888, 0);
    return 0;
}
