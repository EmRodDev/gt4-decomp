/* Query over course runway data: 003E6E90 tests queryValue/queryRef against the block at +0x20 and fills two 16-byte results; when it
 * reports a hit, GT4Course::RunwayData::traverse walks the entries from index 0 to count-1 (u16 at +0x4C) with those results (the 0..count-1
 * range suggests a recursive subdivision, inferred). Twin of 003E5B40, which differs only in the test function (003E7038); the geometric
 * meaning of the query is purpose unknown. */
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

extern "C" s32 func_003E6E90(void *, void *, void *, s32, void *);
extern "C" void GT4Course__RunwayData__traverse(void *, void *, void *, void *, void *, s32, s32, s32);

struct func_003E5AB8_arg0 {
    char pad0[0x4C];
    u16 unk4C;
};

extern "C" void func_003E5AB8(s32 *runway, void *context, s32 queryValue, char **queryRef) {
    s32 resultA[4];
    s32 resultB[4];
    char *part20;
    s32 *resultBPtr;
    part20 = (char *)runway + 0x20;
    resultBPtr = resultB;
    if (func_003E6E90(part20, resultA, resultBPtr, queryValue, queryRef) != 0) {
        GT4Course__RunwayData__traverse(runway, context, part20, resultA, resultBPtr, 0, ((struct func_003E5AB8_arg0 *)runway)->unk4C - 0x1, 0);
    }
}
