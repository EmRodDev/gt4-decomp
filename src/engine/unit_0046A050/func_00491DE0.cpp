/* Sets up the 32x32 texture object D_0088FED0 (names inferred from the pgluTex* calls): resets it, binds an image at the base address
 * returned by func_004AB030 (stored in D_006D6190) with the constants 0x14 and 0x40, then sets two parameters with func_0049AF00 and
 * func_0049AFD0 (0x20 x 0x20 size and two settings, both inferred only from the argument values). Finally D_006D6180 is set to
 * base + 0x7C0, the address just past this image (inferred; meaning of the constants unknown). The argument is not used. */
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

extern s32 D_006D6180;
extern char D_006D6190[];
extern char D_0088FED0[];
extern "C" s32 func_004AB030(void);
extern "C" void pgluTexReset(void *);
extern "C" void pgluTexImage(void *, s32, s32, s32, s32);
extern "C" void func_0049AF00(void *, s32, s32);
extern "C" void func_0049AFD0(void *, s32, s32);

extern "C" void func_00491DE0(s32 *unused) {
    char *baseSlot;
    s32 base;
    char *texture;
    base = func_004AB030();
    baseSlot = (char *)&D_006D6190;
    texture = (char *)&D_0088FED0;
    *(s32 *)(char *)baseSlot = base;
    pgluTexReset(texture);
    pgluTexImage(texture, 0, *(s32 *)(char *)baseSlot, 0x14, 0x40);
    func_0049AF00(texture, 0x20, 0x20);
    func_0049AFD0(texture, 0x4, 0x2);
    func_0049AFD0(texture, 0x5, 0x2);
    D_006D6180 = *(s32 *)(char *)baseSlot + 0x7c0;
}
