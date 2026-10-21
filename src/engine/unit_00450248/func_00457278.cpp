/* Bounds-checked table lookup: the row (40 bytes each, count in the u16 at +0x16) and column (4 bytes each, starting at +0x1c in the
 * row) give a value; when it is not negative it is passed with the sink's field 0x14 to func_004569F0. Does nothing for a missing
 * sink or an out-of-range row. The table's meaning is unknown. */
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

extern "C" void func_004569D0(void *, void *);
extern "C" void func_004569F0(void *, s32, s32, s32);

struct func_00457278_arg0 {
    char pad0[0x38];
    s32 unk38;
    char pad3C[0x20];
    s32 unk5C;
};
struct func_00457278_arg3 {
    char pad0[0x14];
    s32 unk14;
};

extern "C" void func_00457278(s32 *table, void *column, s32 row, char **sink) {
    s32 scratch[4];
    s32 cellValue;
    if ((row < (s32)*(u16 *)((char *)table + 0x16))) {
        if (sink != 0) {
            cellValue = *(s32 *)((char *)((((s32)column << 2) + ((((row << 2) + row) << 3) + ((struct func_00457278_arg0 *)table)->unk38))) + 0x1c);
            if (cellValue >= 0) {
                func_004569D0(scratch, sink);
                func_004569F0(scratch, ((struct func_00457278_arg0 *)table)->unk5C, cellValue, ((struct func_00457278_arg3 *)sink)->unk14);
            }
        }
    }
}
