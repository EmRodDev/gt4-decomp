/* Array lookup through a pointer held at +8: returns table[index], or 0 when the table pointer is null. */
#include "types.h"

struct Struct_0046A050 {
    char pad0[8];
    s32 *table;
};

extern "C" s32 func_0046A050(Struct_0046A050 *self, s32 index) {
    s32 *entries;

    entries = self->table;
    if (entries == 0) {
        return 0;
    }
    return entries[index];
}
