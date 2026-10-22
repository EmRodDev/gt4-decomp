/* Writes every entry of a table to its own file (inferred from the fwrite/fclose calls). For each index below the
 * 16-bit count, when the key entry in the pointer array at +0x14 is non-null, a file name is formatted into an
 * 0x80-byte buffer with func_0057DA20 from the format string D_006AE550 and the key's value, the file is opened
 * with func_005A3830 using the mode string D_006AE558, the data entry at the same index of the array at +0x18 is
 * written with fwrite for the number of bytes in its field +0xC, and the file is closed. The count is re-read
 * after every file written, as in the matched source. Whether the entries are dumps of some resource is unknown. */
#include "types.h"

struct E1 {
    s32 v;
};

struct E2 {
    char pad[0xC];
    s32 c;
};

struct Obj {
    char pad0[0x10];
    u16 count;
    char pad1[2];
    E1 **t14;
    E2 **t18;
};

extern char D_006AE550[];
extern char D_006AE558[];

extern "C" void func_0057DA20(int table, int arg1, ...);
extern "C" s32 func_005A3830(int table, int arg1);
extern "C" void fwrite(void *table, s32 arg1, s32 arg2, s32 arg3);
extern "C" s32 fclose(void *table);

extern "C" void func_004918B0(Obj *table) {
    char fileName[0x80];
    s32 i = 0;
    u16 currentCount = table->count;

    if (currentCount != 0) {
        do {
            s32 byteOffset = i << 2;
            E1 *entry = *(E1 **)(byteOffset + (s32)table->t14);
            i += 1;
            if (entry != 0) {
                func_0057DA20((int)fileName, (int)D_006AE550, entry->v);
                s32 size = (*(E2 **)(byteOffset + (s32)table->t18))->c;
                s32 file = func_005A3830((int)fileName, (int)D_006AE558);
                fwrite(*(E2 **)(byteOffset + (s32)table->t18), 1, size, file);
                fclose((void *)file);
                currentCount = table->count;
            }
        } while (i < (s32)currentCount);
    }
}
