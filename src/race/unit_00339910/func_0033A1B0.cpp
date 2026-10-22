/* Serializes a race entry into a binary stream. func_0045B4D8 opens a block on the writer (tag D_0069F308) and
 * func_0045B548 closes it with the same scope object at the end (begin/end pair, inferred from the arguments).
 * Inside: a version byte 1, four values obtained from the entry through func_003B5A20 (called with 1 and with 0),
 * func_003B5AF8 and func_003B5B80, each written with func_0045B040, and finally the byte at entry+0x345C. The same
 * scratch buffer is passed to all four getters (purpose of that buffer unknown); the selector goes only to the
 * first two. */
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

extern char D_0069F308[];
extern "C" void func_0045B4D8(void *, void *, void *);
extern "C" void GT4Model__BinStreamWriter__write8u(void *, s32);
extern "C" s32 func_003B5A20(void *, s32, s32, void *);
extern "C" void func_0045B040(void *, s32);
extern "C" s32 func_003B5AF8(void *, void *);
extern "C" s32 func_003B5B80(void *, void *);
extern "C" void GT4Model__BinStreamWriter__write8(void *, s32);
extern "C" void func_0045B548(void *, void *);

struct func_0033A1B0_arg1 {
    char pad0[0x345C];
    s32 unk345C;
};

extern "C" void func_0033A1B0(s32 *writer, struct func_0033A1B0_arg1 *entry, s32 selector) {
    s32 blockScope[4];
    s32 scratch[4];
    s32 *scratchPtr;
    func_0045B4D8(blockScope, writer, &D_0069F308);
    GT4Model__BinStreamWriter__write8u(writer, 0x1);
    scratchPtr = scratch;
    func_0045B040(writer, func_003B5A20(entry, 0x1, selector, scratchPtr));
    func_0045B040(writer, func_003B5A20(entry, 0, selector, scratchPtr));
    func_0045B040(writer, func_003B5AF8(entry, scratchPtr));
    func_0045B040(writer, func_003B5B80(entry, scratchPtr));
    GT4Model__BinStreamWriter__write8(writer, entry->unk345C);
    func_0045B548(blockScope, writer);
}
