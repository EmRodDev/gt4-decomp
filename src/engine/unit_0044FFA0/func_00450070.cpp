/* Returns the 16-bit field at +4 of the record that func_00450040 finds for (id, 0) (purpose unknown). */
#include "types.h"
struct Obj {
    char pad[0x4];
    u16 unk4;
};
extern "C" Obj *func_00450040(s32 id, s32 arg1);
extern "C" u16 func_00450070(s32 id) {
    return func_00450040(id, 0)->unk4;
}
