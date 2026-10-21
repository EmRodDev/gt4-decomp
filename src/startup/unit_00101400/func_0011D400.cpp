/* Makes a virtual call through the entry at +0x300 of the table pointed to by src+0x64 (a this-adjust delta, an index and a
 * function pointer: the usual ee-gcc 2.96 virtual-call record, inferred). The call fills 'detail' and returns a code. The flag at
 * +0x4B4 of dst becomes 1 when the code is 9, or when the code is 6 and the detail is 6 or 7; otherwise 0. Meaning of codes unknown. */
#include "types.h"

struct V { short delta; short index; void *fn; };
struct Src { char pad[0x64]; char *tbl; };
struct Dst { char pad[0x4B4]; s32 f4B4; };

extern "C" void func_0011D400(Dst *dst, Src *src) {
    s32 detail;
    V *entry = (V *)(src->tbl + 0x300);
    s32 code = ((s32 (*)(void *, void *))entry->fn)((char *)src + entry->delta, &detail);
    dst->f4B4 = 0;
    if (code == 9) {
        dst->f4B4 = 1;
    }
    if (code == 6 && (unsigned int)(detail - 6) < 2) {
        dst->f4B4 = 1;
    }
}
