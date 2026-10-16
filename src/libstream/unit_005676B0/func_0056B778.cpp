#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" void func_00567F50(const char *);
extern char D_006CAC98[];                     /* extern */
extern "C" void *func_005A48D8(void *, int, unsigned int);           /* extern */

extern "C" s32 func_0056B778(char *arg0, u32 arg1, char *arg2) {
    s32 *temp_a1;
    s32 *temp_a1_2;
    s32 *temp_a1_3;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v1;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_a3_3;
    s32 var_v0;
    void *temp_v0;

    switch (arg1) {
    case 0x6:
    case 0x8:
        M2C_FIELD(arg0, s32 *, 0x7C) = (s32) M2C_FIELD(arg2, s32 *, 0);
        break;
    case 0x7:
    case 0x9:
        M2C_FIELD(arg2, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x7C);
        break;
    case 0x0:
        M2C_FIELD(arg0, s32 *, 0x80) = (s32) M2C_FIELD(arg2, s32 *, 0);
        break;
    case 0x1:
        M2C_FIELD(arg2, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x80);
        break;
    case 0x3:
        M2C_FIELD(arg2, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0xC);
        break;
    case 0x13:
        temp_v0 = *(void * *)((M2C_FIELD(arg0, s32 *, 0x7C) * 4) + M2C_FIELD(arg0, s32 *, 0x78));
        if (temp_v0 != NULL) {
            M2C_FIELD(arg2, s32 *, 0) = M2C_FIELD(arg0, s32 *, 0x2C) * M2C_FIELD(temp_v0, s32 *, 0x38) / M2C_FIELD(arg0, s32 *, 0xC);
        } else {
            M2C_FIELD(arg2, s32 *, 0) = M2C_FIELD(arg0, s32 *, 0x2C) * 5 / M2C_FIELD(arg0, s32 *, 0xC);
        }
        break;
    case 0x18:
        M2C_FIELD(arg0, s32 *, 0x2C) = (s32) M2C_FIELD(arg2, s32 *, 0);
        break;
    case 0x19:
        M2C_FIELD(arg2, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x2C);
        break;
    case 0x14:
        M2C_FIELD(((M2C_FIELD(arg2, s32 *, 0) * 0x14) + arg0), s32 *, 0x8C) = (s32) M2C_FIELD(arg2, s32 *, 4);
        M2C_FIELD(((M2C_FIELD(arg2, s32 *, 0) * 0x14) + arg0), s32 *, 0x90) = (s32) M2C_FIELD(arg2, s32 *, 8);
        temp_v1 = M2C_FIELD(arg2, s32 *, 0);
        M2C_FIELD(((temp_v1 * 0x14) + arg0), s32 *, 0x88) = temp_v1;
        break;
    case 0x16:
        M2C_FIELD(arg0, s32 *, 0x1CC) = (s32) M2C_FIELD(arg2, s32 *, 4);
        M2C_FIELD(arg0, s32 *, 0x1D0) = (s32) M2C_FIELD(arg2, s32 *, 8);
        M2C_FIELD(arg0, s32 *, 0x1C8) = (s32) M2C_FIELD(arg2, s32 *, 0);
        break;
    case 0x1A:
        func_005A48D8(M2C_FIELD(arg0, void **, 0x5C), 0, M2C_FIELD(arg0, s32 *, 0x1C) * 8);
        func_005A48D8(M2C_FIELD(arg0, void **, 0x40), 0, M2C_FIELD(arg0, s32 *, 0x1C) * 4);
        func_005A48D8(M2C_FIELD(arg0, void **, 0x38), 0, M2C_FIELD(arg0, s32 *, 0x1C) * 4);
        break;
    case 0x24:
        M2C_FIELD(arg0, s32 *, 0x74) = (s32) M2C_FIELD(arg2, s32 *, 0);
        break;
    case 0x25:
        M2C_FIELD(arg2, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x74);
        break;
    case 0x64:
        var_a3 = 0;
        if (M2C_FIELD(arg0, s32 *, 0x14) > 0) {
            do {
                temp_v0_2 = var_a3 * 4;
                temp_a1 = (s32 *)(temp_v0_2 + (int)arg2);
                var_a3 += 1;
                *(s32 *)temp_a1 = *(s32 *)(temp_v0_2 + M2C_FIELD(arg0, s32 *, 0x60));
            } while (var_a3 < M2C_FIELD(arg0, s32 *, 0x14));
        }
        break;
    case 0x65:
        var_a3_2 = 0;
        if (M2C_FIELD(arg0, s32 *, 0xC) > 0) {
            do {
                temp_v0_3 = var_a3_2 * 4;
                temp_a1_2 = (s32 *)(temp_v0_3 + (int)arg2);
                var_a3_2 += 1;
                *(s32 *)temp_a1_2 = *(s32 *)(temp_v0_3 + M2C_FIELD(arg0, s32 *, 0x44));
            } while (var_a3_2 < M2C_FIELD(arg0, s32 *, 0xC));
        }
        break;
    case 0x66:
        var_a3_3 = 0;
        if (M2C_FIELD(arg0, s32 *, 0xC) > 0) {
            do {
                temp_v0_4 = var_a3_3 * 4;
                temp_a1_3 = (s32 *)(temp_v0_4 + (int)arg2);
                var_a3_3 += 1;
                *(s32 *)temp_a1_3 = *(s32 *)(temp_v0_4 + M2C_FIELD(arg0, s32 *, 0x48));
            } while (var_a3_3 < M2C_FIELD(arg0, s32 *, 0xC));
        }
        break;
    case 0x67:
        M2C_FIELD(arg2, s32 *, 0) = (s32) M2C_FIELD(arg0, s32 *, 0x1EC);
        break;
    default:
        func_00567F50(D_006CAC98);
        return -1;
    }
    return 0;
}
