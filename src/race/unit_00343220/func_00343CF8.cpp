/* Writes one value into the field at +0x1C8 of every wheel record (0xEC bytes apart; wheel count is the byte at +1 of the car info
 * returned by func_00359510). */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
void *func_00359510(s32);                           /* extern */

struct func_00343CF8_arg0 {
    char pad0[0x10];
    s32 unk10;
};
struct func_00343CF8_temp_v0 {
    char pad0[0x1];
    u8 unk1;
};

void func_00343CF8(char *self, f32 value) {
    f32 *wheelField;
    s32 wheelIndex;
    char *carInfo;

    carInfo = (char *)(func_00359510(((struct func_00343CF8_arg0 *)self)->unk10));
    wheelIndex = 0;
    if (((struct func_00343CF8_temp_v0 *)carInfo)->unk1 != 0) {
        wheelField = (f32 *)(self + 0x1C8);
        do {
            *wheelField = value;
            wheelIndex += 1;
            wheelField = (f32 *)((char *)wheelField + 0xEC);
        } while (wheelIndex < (s32) ((struct func_00343CF8_temp_v0 *)carInfo)->unk1);
    }
}

}
