/* Calls func_003968B8 and then func_00396808 with the handle stored at +4; the second call also gets the sub-block at
 * +0x94. Purpose of the handle unknown. */
#include "types.h"

struct Obj00394D48 {
    char pad[4];
    s32 unk4;
};

extern "C" void func_003968B8(s32 arg0);
extern "C" void func_00396808(s32 arg0, void *arg1);

extern "C" void func_00394D48(struct Obj00394D48 *self) {
    struct Obj00394D48 *obj = self;
    func_003968B8(obj->unk4);
    func_00396808(obj->unk4, (char *)obj + 0x94);
}
