/* Returns base + element[index].field10 + 2, where the elements are addressed at base + index * 4 and the field is at +0x10: the
 * address of something stored 'field10 + 2' bytes after the base (shape only; purpose unknown). */
#include "types.h"
struct Elem {
    char pad[0x10];
    s32 unk10;
};
extern "C" s32 func_004501D0(s32 base, s32 index) {
    s32 offset = ((Elem *)(index * 4 + base))->unk10;
    return base + offset + 2;
}
