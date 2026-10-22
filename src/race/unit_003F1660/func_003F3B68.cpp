#include "types.h"
#include "m2c_macros.h"
struct Car { u8 bytes[0xA8]; };
struct Six { signed char data[6]; };
extern "C" {
void func_004413C8(void *, char *);
void *func_005A48D8(void *, int, unsigned int);
struct Config { u8 pad[0x13d]; u8 a,b; u8 pad2[11]; u8 c,d; };
extern Config D_00620CD8;
extern u8 D_006224A0, D_006224A1, D_006224A2, D_006224A3, D_006224A4, D_006224A5;
extern char D_00622420[], D_00622428[];
extern Six D_006A4028, D_006A4030;
}
extern "C" void func_003F3B68(char *arg0, void *arg1, int arg2, s32 arg3) {
    Six sp0;
    Six sp10;
    u32 temp_v1_3;
    s32 var_a0;
    u16 temp_v0;
    u16 temp_v0_2;
    u32 var_t1;
    char *temp_a0;
    char *temp_a2;
    u8 *var_a0_2;
    u8 *var_v1;
    u8 *var_v1_2;
    u8 temp_a1_2;
    int temp_v0_3;
    int temp_v0_4;
    u8 temp_v1;
    char *temp_a1;
    char *temp_a4;
    char *temp_v1_2;
    char *var_a2;
    u32 var_a3;
    char *var_a6;

    func_005A48D8(arg0, 0, 0x600);
    func_004413C8(arg1, arg0);
    M2C_FIELD(arg0, s8 *, 0) = 2;
    if (M2C_FIELD(arg0, u8 *, 0x11C) == 0) {
        M2C_FIELD(arg0, u8 *, 0x11C) = (u8) D_00620CD8.c;
    }
    if (M2C_FIELD(arg0, u8 *, 0x112) == 0) {
        M2C_FIELD(arg0, u8 *, 0x112) = (u8) D_00620CD8.d;
    }
    temp_v1 = M2C_FIELD(arg0, u8 *, 1);
    if (temp_v1 == 3) {
        M2C_FIELD(arg0, u8 *, 0x11C) = 0U;
        M2C_FIELD(arg0, u8 *, 0x112) = 0U;
    }
    if (temp_v1 == 2) {
        M2C_FIELD(arg0, u8 *, 0x11C) = 0U;
        M2C_FIELD(arg0, u8 *, 0x112) = 0U;
    }
    if (temp_v1 == 4) {
        M2C_FIELD(arg0, u8 *, 0x11C) = 0U;
        M2C_FIELD(arg0, u8 *, 0x112) = 0U;
    }
    if ((temp_v1 == 2) && ((u32) (arg3 - 2) < 2U)) {
        M2C_FIELD(arg0, s8 *, 0xA8) = 3;
        M2C_FIELD(arg0, u16 *, 0x66) = (u16) (M2C_FIELD(arg0, u16 *, 0x66) + D_006224A1);
        M2C_FIELD(arg0, u16 *, 0x7E) = (u16) (M2C_FIELD(arg0, u16 *, 0x7E) + D_006224A1);
        M2C_FIELD(arg0, u8 *, 0x92) = (u8) (M2C_FIELD(arg0, u8 *, 0x92) + D_006224A2);
        M2C_FIELD(arg0, u8 *, 0x93) = (u8) (M2C_FIELD(arg0, u8 *, 0x93) + D_006224A2);
        M2C_FIELD(arg0, u16 *, 0x9A) = (u16) (M2C_FIELD(arg0, u16 *, 0x9A) + D_006224A0);
        M2C_FIELD(arg0, u16 *, 0x9C) = (u16) (M2C_FIELD(arg0, u16 *, 0x9C) + D_006224A0);
        M2C_FIELD(arg0, u8 *, 0x94) = (u8) (M2C_FIELD(arg0, u8 *, 0x94) + D_006224A3);
        M2C_FIELD(arg0, u8 *, 0x95) = (u8) (M2C_FIELD(arg0, u8 *, 0x95) + D_006224A3);
        M2C_FIELD(arg0, u8 *, 0x58) = (u8) D_006224A4;
        M2C_FIELD(arg0, u8 *, 0x70) = (u8) D_006224A5;
    }
    if (M2C_FIELD(arg0, s16 *, 0x12) == 0) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x10);
        M2C_FIELD(arg0, s16 *, 0x12) = (s16) ((s32) ((s16) temp_v0 + ((u32) (temp_v0 << 0x10) >> 0x1F)) >> 1);
    }
    if (M2C_FIELD(arg0, s16 *, 0x14) == 0) {
        temp_v0_2 = M2C_FIELD(arg0, u16 *, 0x10);
        M2C_FIELD(arg0, s16 *, 0x14) = (s16) ((s32) ((s16) temp_v0_2 + ((u32) (temp_v0_2 << 0x10) >> 0x1F)) >> 1);
    }
    if (D_00620CD8.a != 0) {
        M2C_FIELD(arg0, s8 *, 0x25) = (s8) ((s32) (M2C_FIELD(arg0, u8 *, 0x24) * D_00620CD8.a) / 100);
    }
    if (D_00620CD8.b != 0) {
        M2C_FIELD(arg0, s8 *, 0x26) = (s8) ((s32) (M2C_FIELD(arg0, u8 *, 0x24) * D_00620CD8.b) / 100);
    }
    sp0 = D_006A4028;
    sp10 = D_006A4030;
    if (M2C_FIELD(arg0, u8 *, 0x182) == 0) {
        M2C_FIELD(arg0, u8 *, 0x182) = 6U;
        *(Six *)(arg0 + 0x19C) = sp0;
        *(Six *)(arg0 + 0x1A2) = sp10;
    }
    if (M2C_FIELD(arg0, u8 *, 0x195) == 0) {
        M2C_FIELD(arg0, s8 *, 0x181) = 6;
        *(Six *)(arg0 + 0x190) = sp0;
        *(Six *)(arg0 + 0x196) = sp10;
    }
    if (M2C_FIELD(arg0, u8 *, 0x1AA) == 0) {
        M2C_FIELD(arg0, u8 *, 0x1AA) = -0x74U;
    }
    if (M2C_FIELD(arg0, u8 *, 0x1AB) == 0) {
        M2C_FIELD(arg0, u8 *, 0x1AB) = 0x64U;
    }
    if (M2C_FIELD(arg0, u8 *, 0x1C3) == 0x64) {
        M2C_FIELD(arg0, s8 *, 0x1C2) = 0;
    }
    M2C_FIELD(arg0, s8 *, 0x1E0) = 1;
    M2C_FIELD(arg0, s8 *, 0x1F2) = 1;
    M2C_FIELD(arg0, s8 *, 0x1F3) = 1;
    M2C_FIELD(arg0, s8 *, 0x1F4) = 1;
    M2C_FIELD(arg0, s8 *, 0x1F5) = 1;
    M2C_FIELD(arg0, s8 *, 0x1FD) = 1;
    M2C_FIELD(arg0, s8 *, 0x1FE) = 1;
    M2C_FIELD(arg0, s8 *, 0x1FF) = 1;
    M2C_FIELD(arg0, s8 *, 0x1F6) = 2;
    M2C_FIELD(arg0, s8 *, 0x204) = 2;
    M2C_FIELD(arg0, s8 *, 0x205) = 2;
    M2C_FIELD(arg0, s8 *, 0x206) = 2;
    M2C_FIELD(arg0, s8 *, 0x207) = 2;
    var_t1 = 0;
    u8 dflt100 = 0x64;
    u8 dflt80 = 0x50;
    var_a2 = arg0;
    do {
        temp_a1 = var_a2 + 0x210;
        var_v1 = (u8 *)var_a2 + 0x27E;
        for (var_a0 = 0; var_a0 < 5; ++var_a0) {
        if (*var_v1 == 0) {
            *var_v1 = dflt100;
        }
        var_v1 += 1;
        }
        if (M2C_FIELD(temp_a1, u8 *, 0x73) == 0) {
            M2C_FIELD(temp_a1, u8 *, 0x73) = dflt80;
        }
        var_t1 += 1;
        var_a2 += 0xA8;
    } while (var_t1 < 6U);
    temp_v1_2 = arg0 + 0x210;
    if (M2C_FIELD(temp_v1_2, u8 *, 0x78) == 0) {
        M2C_FIELD(temp_v1_2, u8 *, 0x78) = (u8) M2C_FIELD(temp_v1_2, u8 *, 0x64);
    }
    if (M2C_FIELD(temp_v1_2, u8 *, 0x79) == 0) {
        M2C_FIELD(temp_v1_2, u8 *, 0x79) = (u8) M2C_FIELD(temp_v1_2, u8 *, 0x65);
    }
    var_t1 = 0;
    if (M2C_FIELD(temp_v1_2, u8 *, 0x7A) == 0) {
        M2C_FIELD(temp_v1_2, u8 *, 0x7A) = (u8) M2C_FIELD(temp_v1_2, u8 *, 0x6D);
    }
    u8 dflt45 = 0x2D;
    u8 dflt6 = 6;
    var_a6 = arg0;
    do {
        temp_a4 = var_a6 + 0x210;
        if (M2C_FIELD(temp_a4, u8 *, 2) == 0) {
            M2C_FIELD(temp_a4, u8 *, 2) = dflt45;
        }
        if (M2C_FIELD(temp_a4, u8 *, 0xC) == 0) {
            M2C_FIELD(temp_a4, u8 *, 0xC) = dflt6;
            for (var_a3 = 0; var_a3 < 6; ++var_a3) {
                ((Car *)temp_a4)->bytes[var_a3 + 0x50] = D_00622420[var_a3];
                ((Car *)(var_a6 + 0x216))->bytes[var_a3 + 0x50] = D_00622428[var_a3];
            }
        }
        var_a0_2 = (u8 *)temp_a4 + 0x64;
        var_a3 = 0;
        var_v1_2 = (u8 *)arg0;
        var_v1_2 += 0x274;
        do {
        if (*var_a0_2 == 0) {
            *var_a0_2 = *var_v1_2;
        }
        var_a3 += 1;
        var_v1_2 += 1;
        var_a0_2 += 1;
        } while (var_a3 < 0x20U);
        var_t1 += 1;
        var_a6 += 0xA8;
    } while (var_t1 < 6U);
}
