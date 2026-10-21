/* If func_003683A8 reports true, resets the record at +0x788 (word 0 = 0, float at +4 = 1.0f, bytes at +8 and +9 = 0) and then calls
 * func_00368260 on the object. The record's meaning is unknown. The tail call is written as `return` of a void call, as matched. */
#include "types.h"

struct Sub003683C8 {
    s32 unk0;
    f32 unk4;
    u8 unk8;
    u8 unk9;
};

extern "C" s32 func_003683A8(void *arg0);
extern "C" void func_00368260(void *arg0);

extern "C" void func_003683C8(void *self) {
    struct Sub003683C8 *record;

    if (func_003683A8(self) != 0) {
        record = (struct Sub003683C8 *)((char *)self + 0x788);
        record->unk4 = 1.0f;
        record->unk0 = 0;
        record->unk8 = 0;
        record->unk9 = 0;
        return func_00368260(self);
    }
}
