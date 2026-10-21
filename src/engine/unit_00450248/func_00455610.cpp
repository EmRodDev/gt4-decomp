/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Renders, through ModelSet2, every part of `modelSet` whose name matches `name` (inferred: the table at +0x58 holds
 * +0x2A entries of 8 bytes {name, part}; func_00604778 looks like a search for the first entry for the key, and func_0057F238 == 0
 * looks like a string-equality test, so consecutive entries with the same name are drawn between one begin/end pair). The m2c stack frame
 * struct and the goto loop are kept as they were because they are what matched; nothing is drawn when no entry matches. */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" void ModelSet2__begin(void *, int) throw();             /* extern */
extern "C" void ModelSet2__end(void *) throw();                      /* extern */
extern "C" void ModelSet2___render(void *, s32, s32);            /* extern */
extern "C" s32 func_0057F238(s32, s32) throw();                        /* extern */
extern "C" void *func_00604778(s32, s32, void *, int, int); /* extern */

extern "C" void func_00455610(void *modelSet, s32 name, s32 renderArg) {
    struct StackFrame_00455610 { s32 wantedName; s32 tableBegin; s8 flag; s8 pad0[0x7]; } searchKey;
    s32 part;
    s32 tableEnd;
    s32 tableBegin;
    void *firstMatch;
    void *cursor;

    searchKey.wantedName = name;
    tableBegin = M2C_FIELD(modelSet, s32 *, 0x58);
    if (tableBegin != 0) {
        tableEnd = tableBegin + (M2C_FIELD(modelSet, u16 *, 0x2A) * 8);
        searchKey.tableBegin = tableBegin;
        searchKey.flag = 0;
        firstMatch = func_00604778(tableBegin, tableEnd, ((s8 *)&searchKey), 0, 0);
        if ((firstMatch != (void *)tableEnd) && (func_0057F238(M2C_FIELD(firstMatch, s32 *, 0), searchKey.wantedName) == 0)) {
            cursor = (char *)firstMatch + 8;
            ModelSet2__begin(modelSet, 0);
            ModelSet2___render(modelSet, M2C_FIELD(firstMatch, s32 *, 4), renderArg);
nextPart:
            if ((cursor != (void *)tableEnd) && (func_0057F238(M2C_FIELD(cursor, s32 *, 0), searchKey.wantedName) == 0)) {
                part = M2C_FIELD(cursor, s32 *, 4);
                cursor = (char *)cursor + 8;
                ModelSet2___render(modelSet, part, renderArg);
                goto nextPart;
            }
            ModelSet2__end(modelSet);
        }
    }
}
