/* compiler: ee-gcc2.9-991111 */
typedef int s32;
extern s32 func_005ADCC0(s32);
extern s32 func_005ADCF0(s32);
extern s32 func_005B19B0(void *, s32, s32, void *, s32, void *, s32, void *, s32);
extern char D_0087E480[];
extern char D_0087E500[];
extern char D_00880000[];
extern char D_00657AF4[];
extern char D_00657AF0[];
extern char D_0058D748[];

s32 func_0058D758(s32 arg0) {
    char *s1 = D_0087E480;
    s32 saved = arg0;
    if (*(s32 *)(s1 + 0x24) == 0) {
        return -0x64;
    }
    if (func_005ADCF0(*(s32 *)D_00657AF4) < 0) {
        return -0xC8;
    }
    {
    char *a3 = D_0087E500;
    *(s32 *)(a3 + 0x14) = saved;
    if (func_005B19B0(s1, 0x14, 1, a3, 0x30, D_00880000 - 0x5C0, 4, D_0058D748, 0) != 0) {
        func_005ADCC0(*(s32 *)D_00657AF4);
        return -0x5B;
    }
    }
    *(s32 *)D_00657AF0 = 0x14;
    return 0;
}
