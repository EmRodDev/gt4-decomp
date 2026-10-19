#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

struct E00572B08 {
    s32 p0;
    s32 q4;
    char pad8[0x4];
    s32 pC;
};

extern "C" void func_005769F0(s32 arg0);
extern "C" void func_00576A28(s32 arg0);

extern "C" s32 func_00572B08(s32 arg0) {
    s32 temp_s2;
    s32 temp_v0;
    s32 var_a0;
    s32 var_s1;
    s32 var_s0;
    s32 var_v1;

    temp_s2 = arg0 + 0x4C;
    func_005769F0(temp_s2);
    var_s1 = 0;
    var_s0 = arg0 + 0xC;
    var_a0 = 0xF;
    do {
        var_v1 = *(s32 *)(s32 *)(var_s0);
        if (var_v1 != 0) {
            do {
                temp_v0 = *(s32 *)((char *)var_v1 + 0x4) - var_v1;
                var_v1 = *(s32 *)((char *)var_v1 + 0xC);
                var_s1 = (var_s1 + temp_v0) - 0x10;
            } while (var_v1 != 0);
        }
        var_a0 -= 1;
        var_s0 += 4;
    } while (var_a0 >= 0);
    func_00576A28(temp_s2);
    return var_s1;
}
