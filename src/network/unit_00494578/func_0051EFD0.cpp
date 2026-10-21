/* Parses a reply of at least 0x10 bytes (arg3 = size, arg2 = data): only valid in state 1 (else 0xCB20); fails with 3 when no item (+0x7C) is attached and 0xCB20 when the data is too short or the 16-bit value read at +0x10 (func_00538F98) is 0. Otherwise it stores that value in the item (+0x18), copies the state into it, calls func_0051E028 and, on success, moves the object to state 6. The value is probably a length or id; not determined. */
#include "types.h"
struct Item { char pad0[4]; s32 unk4; char pad8[0x10]; s32 unk18; };
struct Obj { char pad0[4]; s32 unk4; s32 unk8; char padC[0x70]; Item *unk7C; };
struct Vt { char pad0[0x80]; s32 (*f80)(void *, void *); };
extern Vt *D_0064B4B0;
extern "C" s32 func_0051E028(Obj *, Item &) throw();
extern "C" s32 func_00538F98(u8 *, u16 *);
static inline int fits(u32 size, u32 offset) { return offset + 1 < size; }
extern "C" s32 func_0051EFD0(Obj *conn, void *unused, void *data, u32 size) {
    u16 value;
    s32 state = conn->unk4;
    if (state != 1) return 0xCB20;
    Item *item = conn->unk7C;
    if (item == 0) return 3;
    if (size < 0x10) return 0xCB20;
    D_0064B4B0->f80((char *)item + 0x10, data);
    u8 *p = (u8 *)data + 0x10;
    if (!fits(size, 16)) return 0xCB20;
    func_00538F98(p, &value);
    item->unk18 = value;
    if (value == 0) return 0xCB20;
    item->unk4 = state;
    s32 status = func_0051E028(conn, *item);
    if (status == 0) conn->unk8 = 6;
    return status;
}
