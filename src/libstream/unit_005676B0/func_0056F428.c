#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0056EA50(s32, s32, void *, s32, s32);  /* extern */
s32 func_0056EAD0(s32, void *, s32, s32, s32);   /* extern */
s32 func_0056EB28(s32, s32, void *, s32, s32);  /* extern */

struct func_0056F428_arg1 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

s32 func_0056F428(s32 arg0, struct func_0056F428_arg1 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 temp_s1;
    s32 temp_s3;
    s32 var_v0;

    temp_s1 = arg5;
    temp_s3 = arg4;
    arg1->unk0 = arg2;
    arg1->unk4 = arg3;
    arg1->unk8 = temp_s1;
    var_v0 = func_0056EAD0(arg0, arg1, 3, temp_s3, temp_s1);
    if (var_v0 >= 0) {
        if (func_0056EA50(arg0, 0x13, arg1, temp_s1 + 0xC, temp_s1 + 0xC) < 0) {
            return -0x21E;
        }
        var_v0 = func_0056EB28(arg0, temp_s3, arg1, 3, temp_s1);
        if (var_v0 >= 0) {
            var_v0 = arg1->unk0;
        }
        /* Duplicate return node #6. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
