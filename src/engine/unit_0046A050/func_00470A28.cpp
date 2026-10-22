/* Decodes one Huffman symbol, reading a bit at a time (inferred: func_0046EC00 is called for 1 bit and its flag
 * output ends the loop). The table holds, in order of code length, a length byte, a 16-bit code and a symbol byte
 * per entry. The loop grows the code one bit at a time up to length 16 (loop bound 0x11); for every entry whose
 * length equals the current length it compares the accumulated code with the entry's code and on a hit returns the
 * symbol. If the bit reader reports a problem it sets the flag at +0xA74 and returns the raw value; if no code
 * matches (or the table is exhausted) it sets the flag at +0 and returns 0 (which flag means error is inferred
 * from where they are set). Layout resembles the JPEG-style canonical tables (inferred from the 16-bit maximum
 * length). */
#include "types.h"

struct Tbl {
    char pad0[4];
    s32 count;
    char pad8[4];
    u8 *lengths;
    u16 *keyTable;
    u8 *symbols;
};

struct Huff {
    s32 failed;
    char pad4[0xA70 - 4];
    Tbl *tbl;
    s32 sawEnd;
    void *bitReader;
};

extern "C" s32 func_0046EC00(void *s, s32 n, s32 *flag);

extern "C" s32 func_00470A28(Huff *decoder) {
    s32 endOfData = 0;
    s32 length = 1;
    s32 code = 0;
    s32 index = 0;
    void *bitSource = decoder->bitReader;
    Tbl *table = decoder->tbl;
    u8 *lengthPtr = table->lengths;
    u16 *keyPtr = table->keyTable;
    if (table->count > 0) {
        do {
            s32 bitValue = func_0046EC00(bitSource, 1, &endOfData);
            if (endOfData != 0) {
                decoder->sawEnd = 1;
                return bitValue;
            }
            code |= bitValue;
            if (*lengthPtr == length) {
                do {
                    u16 key = *keyPtr;
                    keyPtr++;
                    if (key == code) {
                        return decoder->tbl->symbols[index];
                    }
                    lengthPtr++;
                    index++;
                } while (*lengthPtr == length);
            }
            length += 1;
            code <<= 1;
            if (index >= decoder->tbl->count) {
                break;
            }
        } while (length < 0x11);
    }
    decoder->failed = 1;
    return 0;
}
