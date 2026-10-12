/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern "C" void func_002D4C88(void *arg0, void *arg1);
extern "C" int func_005C0FC8(s32, s32, s32, void *, s32, void *);

extern char D_005E8348[];
extern char D_005EFF90[];

extern "C" void func_002B4528(void *arg0, void *arg1) {
    char *var_a0;
    char *temp_v0;

    func_002D4C88(arg0, arg1);
    var_a0 = 0;
    if (arg1 != 0) {
        temp_v0 = *(char **)((char *)arg1 + 4);
        var_a0 = (char *)func_005C0FC8(*(s32 *)(temp_v0 + 4), (s32)D_005E8348, 0,
                                       (char *)arg1 + *(s16 *)temp_v0, (s32)D_005EFF90, arg1);
    }
    if (var_a0 != 0) {
        *(s32 *)((char *)arg0 + 0xEC) = *(s32 *)(var_a0 + 0xEC);
        *(s32 *)((char *)arg0 + 0xF0) = *(s32 *)(var_a0 + 0xF0);
        *(f32 *)((char *)arg0 + 0xF4) = *(f32 *)(var_a0 + 0xF4);
        *(f32 *)((char *)arg0 + 0xF8) = *(f32 *)(var_a0 + 0xF8);
        *(f32 *)((char *)arg0 + 0xFC) = *(f32 *)(var_a0 + 0xFC);
        *(f32 *)((char *)arg0 + 0x100) = *(f32 *)(var_a0 + 0x100);
        *(f32 *)((char *)arg0 + 0x104) = *(f32 *)(var_a0 + 0x104);
        *(s32 *)((char *)arg0 + 0x108) = *(s32 *)(var_a0 + 0x108);
        *(s32 *)((char *)arg0 + 0x10C) = *(s32 *)(var_a0 + 0x10C);
    }
}
