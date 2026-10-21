/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Decodes one 8x8 block of Huffman-coded coefficients for colour component `component` (inferred from the code shape: a DC
 * size/extend step, then run/size pairs for 63 AC values written through the zigzag order table D_006ABCBC; this is the JPEG
 * decoding scheme, the owning decoder is not identified). The DC value is a difference added to the previous DC of
 * the same component (array at +0xA50) and stored in the block at +0x750 + component*0x100. Returns 1 on success, 2 when the bit reader
 * reports an error, -1 on a corrupt code and -2 when the reader has run past its data (inferred; the exact meaning of the
 * reader's +0x20 flag is unknown). */
typedef int s32;

struct Src {
    s32 f0;
    s32 f4;
    s32 f8;
    char pad[0x14];
    s32 f20;
};
struct Comp { void *dc; void *ac; };
struct Sub { char pad[0x430]; Comp comp[1]; };
struct Dec {
    s32 f0;
    char pad4[0xA6C];
    void *tbl;
    s32 err;
    Src *src;
};

extern "C" s32 func_0046EC00(Src *, s32, s32 *) throw();
extern "C" s32 func_00470A28(Dec *);
extern "C" s32 func_00470B48(Dec *);
extern s32 D_006ABCBC[];

extern "C" s32 func_00470778(Dec *decoder, s32 component) {
    s32 dc = 0;
    Sub *tableSet = (Sub *)((char *)decoder + 0x14);
    decoder->err = 0;
    Src *bitReader = decoder->src;
    decoder->tbl = tableSet->comp[component].dc;
    s32 bitCount = func_00470A28(decoder);
    if (decoder->err != 0) return 2;
    if (bitCount > 0) {
        dc = func_0046EC00(bitReader, bitCount, &decoder->err);
        if (decoder->err != 0) return 2;
        if (((dc >> (bitCount - 1)) & 1) == 0) dc = dc - (1 << bitCount) + 1;
    }
    s32 blockOffset = component << 8;
    char *decoderBase = (char *)decoder + 0xC;
    *(s32 *)(blockOffset + (s32)decoderBase + 0x750) = *(s32 *)(decoderBase + component * 4 + 0xA50) + dc;
    if (decoder->f0 != 0) return -1;
    if (bitReader->f20 != 0) return -2;
    s32 *zigzagPos = D_006ABCBC;
    decoder->tbl = tableSet->comp[component].ac;
    tableSet = (Sub *)((char *)decoder + blockOffset + 0x75C);
    s32 coefIndex = 1;
    do {
        if (bitReader->f4 - bitReader->f8 >= 0x41) bitCount = func_00470B48(decoder);
        else bitCount = func_00470A28(decoder);
        if (decoder->err != 0) return 2;
        s32 run = bitCount >> 4;
        if (bitCount == 0) {
            while (coefIndex < 0x40) {
                ((s32 *)tableSet)[*zigzagPos++] = 0;
                coefIndex++;
            }
            if (decoder->f0 != 0) return -1;
            return bitReader->f20 != 0 ? -2 : 1;
        }
        bitCount = bitCount & 0xF;
        s32 coefficient = 0;
        s32 endIndex;
        if (bitCount > 0) {
            coefficient = func_0046EC00(bitReader, bitCount, &decoder->err);
            if (decoder->err != 0) return 2;
            if (((coefficient >> (bitCount - 1)) & 1) == 0) coefficient = coefficient - (1 << bitCount) + 1;
        } else if (run != 15) {
            return -1;
        }
        endIndex = run + coefIndex;
        if (endIndex >= 0x40) return -1;
        while (run-- > 0) {
            ((s32 *)tableSet)[*zigzagPos++] = 0;
            coefIndex++;
        }
        ((s32 *)tableSet)[*zigzagPos++] = coefficient;
        coefIndex++;
    } while (coefIndex < 0x40);
    return bitReader->f20 != 0 ? -2 : 1;
}
