/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" s32 func_00567C98(s32);                             /* extern */
extern "C" void func_00567D80(s32, int, void *);        /* extern */
extern "C" char *func_00567EC0(int);                       /* extern */

static inline char *advance(char *p,int n) { return p+n; }
extern "C" void *func_0056BAD0(char **arg0) {
    s32 temp_a2;
    s32 temp_a5;
    s32 temp_t0;
    s32 temp_t2;
    s32 temp_t2_2;
    s32 temp_v0_2;
    char *temp_a0;
    char *temp_a0_10;
    char *temp_a0_11;
    char *temp_a0_2;
    char *temp_a0_3;
    char *temp_a0_4;
    char *temp_a0_5;
    char *temp_a0_6;
    char *temp_a0_7;
    char *temp_a0_8;
    char *temp_a0_9;
    char *temp_a1;
    char *temp_a1_2;
    char *temp_a1_3;
    char *temp_a1_4;
    char *temp_a1_5;
    char *temp_a1_6;
    char *temp_a2_2;
    char *temp_a2_3;
    char *temp_a4;
    char *temp_a4_2;
    char *temp_a5_2;
    char *temp_a5_3;
    char *temp_a7;
    char *temp_a7_2;
    char *temp_s1;
    char *temp_t1;
    char *temp_t1_2;
    char *temp_v0;

    int one=1;
    temp_v0 = func_00567EC0(0x5E30);
    M2C_FIELD(temp_v0, char ***, 0) = arg0;
    int *rate=(int *)(temp_v0+0x20);
    temp_s1 = *arg0;
    M2C_FIELD(temp_v0, s32 *, 0x64) = one;
    M2C_FIELD(temp_v0, void **, 0x28) = (void *) (temp_v0 + 0x70);
    temp_v0_2 = func_00567C98(M2C_FIELD(temp_s1, s32 *, 0));
    M2C_FIELD(temp_v0, s32 *, 4) = temp_v0_2;
    M2C_FIELD(temp_v0, s32 *, 8) = (s32) (M2C_FIELD(temp_s1, s32 *, 4) * 2);
    M2C_FIELD(temp_v0, s32 *, 0xC) = (s32) M2C_FIELD(temp_s1, s32 *, 4);
    M2C_FIELD(temp_v0, s32 *, 0x10) = (s32) M2C_FIELD(temp_s1, s32 *, 8);
    M2C_FIELD(temp_v0, s32 *, 0x14) = (s32) ((s32) M2C_FIELD(temp_s1, s32 *, 4) / (s32) M2C_FIELD(temp_s1, s32 *, 8));
    M2C_FIELD(temp_v0, s32 *, 0x18) = (s32) M2C_FIELD(temp_s1, s32 *, 0xC);
    func_00567D80(temp_v0_2, 0x19, rate);
    *rate *= 2;
    M2C_FIELD(temp_v0, void **, 0x68) = (void *) (temp_s1 + 0x24);
    int defaultMode=M2C_FIELD(temp_s1, s32 *, 0x44);
    temp_t1 = M2C_FIELD(temp_v0, char **, 0x28);
    temp_a5 = M2C_FIELD(temp_v0, s32 *, 0xC) * 4;
    temp_t1_2 = temp_t1 + (((s32) 0x10 - (s32) (temp_t1)) & 0xF);
    temp_a2 = M2C_FIELD(temp_v0, s32 *, 8) * 4;
    temp_a0 = temp_t1_2 + temp_a5;
    temp_t2 = M2C_FIELD(temp_v0, s32 *, 0x18);
    temp_a0_2 = temp_a0 + (((s32) 0x10 - (s32) (temp_a0)) & 0xF);
    temp_t0 = temp_t2 * 2;
    temp_a4 = temp_a0_2 + temp_a5;
    M2C_FIELD(temp_v0, void **, 0x30) = temp_a0_2;
    temp_a4_2 = temp_a4 + (((s32) 0x10 - (s32) (temp_a4)) & 0xF);
    temp_t2_2 = temp_t2 * 8;
    M2C_FIELD(temp_v0, s32 *, 0x6C) = defaultMode;
    temp_a1 = temp_a4_2 + temp_a2;
    M2C_FIELD(temp_v0, s32 *, 0x1C) = one;
    M2C_FIELD(temp_v0, void **, 0x2C) = temp_t1_2;
    temp_a1_2 = temp_a1 + (((s32) 0x10 - (s32) (temp_a1)) & 0xF);
    M2C_FIELD(temp_v0, void **, 0x34) = temp_a4_2;
    temp_a0_3 = temp_a1_2 + temp_a2;
    M2C_FIELD(temp_v0, void **, 0x38) = temp_a1_2;
    M2C_FIELD(temp_v0, s32 *, 0x24) = 0;
    temp_a0_4 = temp_a0_3 + (((s32) 0x10 - (s32) (temp_a0_3)) & 0xF);
    temp_a2_2 = temp_a0_4 + temp_a2;
    M2C_FIELD(temp_v0, void **, 0x3C) = temp_a0_4;
    temp_a2_3 = temp_a2_2 + (((s32) 0x10 - (s32) (temp_a2_2)) & 0xF);
    temp_a0_5 = temp_a2_3 + 0x100;
    M2C_FIELD(temp_v0, void **, 0x40) = temp_a2_3;
    temp_a0_6 = temp_a0_5 + (((s32) 0x10 - (s32) (temp_a0_5)) & 0xF);
    temp_a1_3 = temp_a0_6 + 0x100;
    M2C_FIELD(temp_v0, void **, 0x44) = temp_a0_6;
    temp_a1_4 = temp_a1_3 + (((s32) 0x10 - (s32) (temp_a1_3)) & 0xF);
    temp_a5_2 = temp_a1_4 + temp_a5;
    M2C_FIELD(temp_v0, void **, 0x48) = temp_a1_4;
    temp_a5_3 = temp_a5_2 + (((s32) 0x10 - (s32) (temp_a5_2)) & 0xF);
    temp_a0_7 = temp_a5_3 + temp_t0;
    M2C_FIELD(temp_v0, void **, 0x4C) = temp_a5_3;
    temp_a0_8 = temp_a0_7 + (((s32) 0x10 - (s32) (temp_a0_7)) & 0xF);
    temp_a1_5 = temp_a0_8 + temp_t0;
    M2C_FIELD(temp_v0, void **, 0x50) = temp_a0_8;
    temp_a1_6 = temp_a1_5 + (((s32) 0x10 - (s32) (temp_a1_5)) & 0xF);
    temp_a0_9 = temp_a1_6 + temp_t0;
    M2C_FIELD(temp_v0, void **, 0x54) = temp_a1_6;
    temp_a0_10 = advance(temp_a0_9 + (((s32) 0x10 - (s32) (temp_a0_9)) & 0xF),temp_t0+2);
    temp_a0_11 = temp_a0_10 + (((s32) 0x10 - (s32) (temp_a0_10)) & 0xF);
    M2C_FIELD(temp_v0, s32 *, 0x58) = (s32) ((temp_a0_10 - temp_t0) - 2);
    temp_a7 = temp_a0_11 + (M2C_FIELD(temp_v0, s32 *, 0x14) * 4);
    M2C_FIELD(temp_v0, void **, 0x60) = temp_a0_11;
    temp_a7_2 = temp_a7 + (((s32) 0x10 - (s32) (temp_a7)) & 0xF) + temp_t2_2;
    M2C_FIELD(temp_v0, void **, 0x28) = temp_a7_2;
    M2C_FIELD(temp_v0, s32 *, 0x5C) = (s32) (temp_a7_2 - temp_t2_2);
    return temp_v0;
}
