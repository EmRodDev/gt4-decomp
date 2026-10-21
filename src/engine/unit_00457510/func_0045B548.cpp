/* Back-patches a length prefix in an output buffer (shape inferred from the arithmetic). The buffer 'out' keeps its start at +0 and
 * its write cursor at +8. If the record's offset at +4 is non-negative, the record's second length at +8 becomes
 * (bytes written so far) - offset; the cursor is moved back to start + offset, the record's first word and that length are written with
 * func_0045AFC8, and the cursor is restored to start + bytes written. Does nothing for a negative offset. */
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

extern "C" void func_0045AFC8(void *, s32);

struct func_0045B548_arg0 {
    char pad0[0x4];
    s32 offset;
    s32 tailLength;
};
struct func_0045B548_arg1 {
    char pad0[0x8];
    s32 cursor;
};

extern "C" void func_0045B548(s32 *record, void *out) {
    s32 written;
    if (((struct func_0045B548_arg0 *)record)->offset >= 0) {
        written = ((struct func_0045B548_arg1 *)out)->cursor;
        written = (written - *(s32 *)(char *)out);
        ((struct func_0045B548_arg0 *)record)->tailLength = (written - ((struct func_0045B548_arg0 *)record)->offset);
        ((struct func_0045B548_arg1 *)out)->cursor = (*(s32 *)(char *)out + ((struct func_0045B548_arg0 *)record)->offset);
        func_0045AFC8(out, *(s32 *)(char *)record);
        func_0045AFC8(out, ((struct func_0045B548_arg0 *)record)->tailLength);
        ((struct func_0045B548_arg1 *)out)->cursor = (*(s32 *)(char *)out + written);
    }
}
