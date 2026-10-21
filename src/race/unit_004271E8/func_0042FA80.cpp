/* Constructor: runs the base constructor, installs vtable D_006879A0, initialises two embedded sub-objects (at 0xD8 and 0x598)
 * and clears the state fields (unkD4 gets the constant 0x157529FF; several indices start at -1). The class name is unknown. */
#include "types.h"

extern char D_006879A0[];
extern "C" s32 func_0043A3F8(s32 *self);
extern "C" void *func_0043DC20(void *self);

struct func_0042FA80_obj {
    void *vtbl;          /* 0x00 */
    s32 unk4;            /* 0x04 */
    s32 unk8;            /* 0x08 */
    s32 unkC;            /* 0x0C */
    s32 unk10;           /* 0x10 */
    s8 unk14;            /* 0x14 */
    char pad15[0x1F];
    s8 unk34;            /* 0x34 */
    char pad35[0x1F];
    s8 unk54;            /* 0x54 */
    char pad55[0x1F];
    s8 unk74;            /* 0x74 */
    char pad75[0x1F];
    s8 unk94;            /* 0x94 */
    char pad95[0x3F];
    s32 unkD4;           /* 0xD4 */
    char padD8[0x980];
    s32 unkA58;          /* 0xA58 */
    s32 unkA5C;          /* 0xA5C */
    s32 unkA60;          /* 0xA60 */
    s32 unkA64;          /* 0xA64 */
    s32 unkA68;          /* 0xA68 */
    s8 unkA6C;           /* 0xA6C */
    char padA6D[0xFF];
    s8 unkB6C;           /* 0xB6C */
    char padB6D[0x1F];
    s8 unkB8C;           /* 0xB8C */
    char padB8D[0x1F];
    s32 unkBAC;          /* 0xBAC */
    s8 unkBB0;           /* 0xBB0 */
};

extern "C" void func_0042FA80(void *self) {
    func_0043A3F8((s32 *)self);
    ((struct func_0042FA80_obj *)self)->vtbl = D_006879A0;
    func_0043DC20((char *)self + 0xD8);
    func_0043DC20((char *)self + 0x598);
    ((struct func_0042FA80_obj *)self)->unk4 = 0;
    ((struct func_0042FA80_obj *)self)->unkD4 = 0x157529FF;
    ((struct func_0042FA80_obj *)self)->unk8 = 0;
    ((struct func_0042FA80_obj *)self)->unkC = 0;
    ((struct func_0042FA80_obj *)self)->unk10 = 0;
    ((struct func_0042FA80_obj *)self)->unkB6C = 0;
    ((struct func_0042FA80_obj *)self)->unkB8C = 0;
    ((struct func_0042FA80_obj *)self)->unk14 = 0;
    ((struct func_0042FA80_obj *)self)->unk34 = 0;
    ((struct func_0042FA80_obj *)self)->unk54 = 0;
    ((struct func_0042FA80_obj *)self)->unk74 = 0;
    ((struct func_0042FA80_obj *)self)->unk94 = 0;
    ((struct func_0042FA80_obj *)self)->unkA68 = 0;
    ((struct func_0042FA80_obj *)self)->unkA6C = 0;
    ((struct func_0042FA80_obj *)self)->unkBAC = -1;
    ((struct func_0042FA80_obj *)self)->unkBB0 = 0;
    ((struct func_0042FA80_obj *)self)->unkA58 = 0;
    ((struct func_0042FA80_obj *)self)->unkA5C = 0;
    ((struct func_0042FA80_obj *)self)->unkA60 = -1;
    ((struct func_0042FA80_obj *)self)->unkA64 = -1;
}
