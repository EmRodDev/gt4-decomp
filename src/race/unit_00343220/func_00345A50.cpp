/* For each wheel (count from the car info, byte at +1; wheel records 0xEC apart) stores the length of the 2D vector (unk28, unk2C)
 * times 0.02, clamped to 1.0, into unk40. The length saturates at 50 units; what the vector is (slip or contact velocity) is not
 * known - func_0035D6B0 writes the same two fields. */
#include "types.h"

struct func_00345A50_temp {
    char pad0[0x1];
    u8 unk1;
};

struct func_00345A50_elem {
    char pad0[0x28];
    f32 unk28;
    f32 unk2C;
    char pad30[0x10];
    f32 unk40;
    char pad44[0xA8];
};

extern "C" void *func_00359538(void *);

extern "C" void func_00345A50(void *self) {
    s32 wheelIndex;
    struct func_00345A50_temp *carInfo;
    struct func_00345A50_elem *wheel;
    f32 vecX;
    f32 vecY;
    f32 squaredLength;
    f32 length;
    f32 scaled;

    carInfo = (struct func_00345A50_temp *)func_00359538(self);
    wheelIndex = 0;
    if (carInfo->unk1 != 0) {
        wheel = (struct func_00345A50_elem *)((char *)self + 0x164);
        do {
            vecX = wheel->unk28;
            vecY = wheel->unk2C;
            squaredLength = vecX * vecX + vecY * vecY;
            __asm__("sqrt.s %0, %1" : "=f"(length) : "f"(squaredLength));
            scaled = length * 0x1.47AE16p-6f;
            if (scaled > 1.0f) {
                scaled = 1.0f;
            }
            wheel->unk40 = scaled;
            wheelIndex += 1;
            wheel++;
        } while (wheelIndex < (s32)carInfo->unk1);
    }
}
