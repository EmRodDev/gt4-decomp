/* Writes a JPEG start-of-frame header (SOF0, marker 0xFFC0) into the encoder's byte writer at +0x85C (identified from the byte
 * sequence: marker, length 0x11 = 8 + 3 * 3, sample precision, height, width, 3 components, and per component an id 0..2, the
 * horizontal/vertical sampling factors packed as (h << 4 | v) and a quantisation table number). func_0046F378 writes a 16-bit
 * value and func_0046F300 a byte (inferred from the argument widths). 'frame' holds {width, height, precision} at +0, +4, +0xC;
 * 'sampling' holds h,v for the three components; 'quantTables' the table number of each component. Part of the Jpeg2Sys encoder. */
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

extern "C" void func_0046F378(void *, s32);
extern "C" void func_0046F300(void *, s32);

struct func_0046C9F8_arg1 {
    char pad0[0x4];
    s32 height;
    char pad8[0x4];
    s32 precision;
};

struct func_0046C9F8_arg2 {
    char pad0[0x4];
    s32 v0;
    s32 h1;
    s32 v1;
    s32 h2;
    s32 v2;
};
struct func_0046C9F8_arg3 {
    char pad0[0x4];
    s32 table1;
    s32 table2;
};

extern "C" void func_0046C9F8(s32 *encoder, struct func_0046C9F8_arg1 *frame, s32 sampling, char **quantTables) {
    char *writer;
    writer = (char *)encoder + 0x85c;
    func_0046F378(writer, (0 | 0xffc0));
    func_0046F378(writer, 0x11);
    func_0046F300(writer, frame->precision);
    func_0046F378(writer, frame->height);
    func_0046F378(writer, *(s32 *)(char *)frame);
    func_0046F300(writer, 0x3);
    func_0046F300(writer, 0);
    func_0046F300(writer, ((*(s32 *)(char *)sampling << 4) | ((struct func_0046C9F8_arg2 *)sampling)->v0));
    func_0046F300(writer, *(s32 *)(char *)quantTables);
    func_0046F300(writer, 0x1);
    func_0046F300(writer, ((((struct func_0046C9F8_arg2 *)sampling)->h1 << 4) | ((struct func_0046C9F8_arg2 *)sampling)->v1));
    func_0046F300(writer, ((struct func_0046C9F8_arg3 *)quantTables)->table1);
    func_0046F300(writer, 0x2);
    func_0046F300(writer, ((((struct func_0046C9F8_arg2 *)sampling)->h2 << 4) | ((struct func_0046C9F8_arg2 *)sampling)->v2));
    func_0046F300(writer, ((struct func_0046C9F8_arg3 *)quantTables)->table2);
}
