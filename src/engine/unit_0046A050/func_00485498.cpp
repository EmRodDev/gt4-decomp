/* Array element read: returns the 32-bit entry at 'index' of the table whose pointer is stored at +4 (no null or bounds check). */
#include "types.h"
struct Obj {
    char pad[0x4];
    s32 *table;
};
extern "C" s32 func_00485498(struct Obj *self, s32 index) {
    s32 *entry = self->table + index;
    return *entry;
}
