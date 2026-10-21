/* Initialises a 3-field record: the first word becomes -1 ('none', inferred from the sentinel) and the two floats at +4 and +8 become
 * 1.0 (identity scale, inferred from the value). Returns the record. */
#include "types.h"
struct S00459D70 {
    s32 unk0;
    f32 unk4;
    f32 unk8;
};
extern "C" void *func_00459D70(S00459D70 *self) {
    self->unk0 = -1;
    self->unk4 = 1.0f;
    self->unk8 = 1.0f;
    return self;
}
