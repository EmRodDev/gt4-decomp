/* Full-screen transition/blend step on the sprite base (spr_base): after the common set-up (func_004A4910, func_0049FE28) it picks, by passType 0..9, one of several fixed sequences of func_004A3620 (blend-pass) or func_004A3498 calls on the two buffers at +0x24C and +0x260, with blend codes 0x44..0xA9 and the strength 'strength' (negated when not positive in cases 0 and 2). Cases 8 and 9 additionally read the flags at +0x2C0/+0x2C1 to choose among three pass layouts with +-16 pixel offsets. Case 4 and 5 swap the two buffers. The meaning of each pass type is not decoded; names come from the call shapes only. */
#include "spr.h"
extern "C" void func_004A4910(float);
extern "C" void func_0049FE28() throw();
extern "C" void func_004A3308(char *) throw();
extern "C" void func_004A3910(char *) throw();
extern "C" void func_004A3498(char *, int, float) throw();
extern "C" void func_004A3620(char *, char *, char *, int, int, int, float) throw();
extern "C" void func_004A3998(unsigned int passType, float strength) {
    char *spriteBase = (char *)spr_base();
    char *unused1;
    char *unused2;
    char *unused3;
    char *unused4;
    char *unused5;
    char *unused6;
    char *unused7;
    char *unused8;
    char *unused9;
    char *unused10;

    func_004A4910(strength);
    func_0049FE28();
    switch (passType) {                                 /* irregular */
    case 0:
        func_004A3308(spriteBase);
        if (!(strength > 0.0f)) {
            func_004A3620(spriteBase, spriteBase + 0x24C, spriteBase + 0x260, 0x62, 0, 0, -strength);
            return;
        }
        func_004A3620(spriteBase, spriteBase + 0x24C, spriteBase + 0x260, 0x68, 0, 0, strength);
        return;
    case 1:
        func_004A3308(spriteBase);
        func_004A3620(spriteBase, spriteBase + 0x24C, spriteBase + 0x260, 0xA8, 0, 0, strength);
        return;
    case 2:
        func_004A3308(spriteBase);
        if (!(strength > 0.0f)) {
            func_004A3498(spriteBase, 0x62, -strength);
            return;
        }
        func_004A3498(spriteBase, 0x68, strength);
        return;
    case 3:
        func_004A3308(spriteBase);
        func_004A3498(spriteBase, 0xA9, strength);
        return;
    case 4:
        func_004A3910(spriteBase);
        func_004A3620(spriteBase, spriteBase + 0x260, spriteBase + 0x24C, 0xA8, 0, 0, strength);
        return;
    case 5:
        func_004A3910(spriteBase);
        func_004A3620(spriteBase, spriteBase + 0x260, spriteBase + 0x24C, 0x64, 0, 0, strength);
        return;
    case 6:
        func_004A3308(spriteBase);
        func_004A3620(spriteBase, spriteBase + 0x24C, spriteBase + 0x260, 0x64, 0, 0, strength);
        return;
    case 7:
        func_004A3308(spriteBase);
        func_004A3620(spriteBase, spriteBase + 0x24C, spriteBase + 0x260, 0x44, 0, 0, strength);
        return;
    case 8:
        func_004A3308(spriteBase);
        if (*(signed char *)(spriteBase+0x2c0) == 0) {
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 168, 0, 16, 1.0f);
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 100, 16, 16, 0.5f);
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 100, 0, 0, strength);
            return;
        }
        else if (*(unsigned char *)(spriteBase+0x2c1) != 0) {
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 168, 0, 0, 1.0f);
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 100, 0, 16, 0.5f);
            return;
        }
        else {
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 168, 0, 0, 1.0f);
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 100, -16, 0, 0.5f);
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 100, 0, 16, strength);
            return;
        }
    case 9:
        func_004A3308(spriteBase);
        if (*(signed char *)(spriteBase+0x2c0) == 0) {
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 168, 0, 0, 1.0f);
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 100, -16, 0, 0.5f);
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 100, 0, 16, strength);
            return;
        }
        else if (*(unsigned char *)(spriteBase+0x2c1) != 0) {
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 168, 0, 0, 1.0f);
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 100, 16, 16, 0.5f);
            return;
        }
        else {
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 168, 0, 16, 1.0f);
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 100, 16, 16, 0.5f);
            func_004A3620(spriteBase, spriteBase+0x24c, spriteBase+0x260, 100, 0, 0, strength);
            return;
        }
    }
}
