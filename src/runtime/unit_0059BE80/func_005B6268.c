/* compiler: ee-gcc2.9-991111 */
typedef int s32;

struct G {
    char pad[0x24];
    s32 f24;
};

extern s32 D_00658358;
extern struct G D_00889E80;
extern char D_00889C80[];
extern char D_00889EA8[];

extern s32 func_005B17D0(struct G *, s32, s32);
extern s32 func_005B19B0(struct G *, s32, s32, s32, s32, char *, s32, s32, s32);

s32 func_005B6268(int unused0) {
    s32 w;
    s32 r;

    if (D_00658358 < 0) {
        for (;;) {
            r = func_005B17D0(&D_00889E80, 0x80000006, 0);
            if (r < 0) {
                return -1;
            }
            if (D_00889E80.f24 != 0) {
                D_00658358 = 0;
                if (func_005B19B0(&D_00889E80, 0xFF, 0, 0, 0, D_00889C80, 4, 0, 0) < 0) {
                    return 0xFFFEFFFF;
                }
                __builtin_memcpy(D_00889EA8, D_00889C80, 4);
                return 0;
            }
            w = 0x100000;
            do {
                w = w - 1;
            } while (w != -1);
        }
    }
    return 0;
}
