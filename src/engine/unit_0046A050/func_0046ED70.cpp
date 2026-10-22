/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Reads bitCount bits (MSB first) from a byte stream with 0xFF00 byte stuffing, in the style of JPEG entropy
 * decoding (inferred: a 0xFF byte followed by 0 is data, followed by anything else is a marker). The mask for the
 * result comes from the table D_00624070 indexed by bitCount (inferred to hold 2^n - 1). bitsLeft counts the
 * unread bits of the current byte and is below zero when the byte is used up; then the cursor advances (a pending
 * stuffed zero byte is skipped first, tracked by flag: 0 means a stuffed pair was just seen). Reaching a marker
 * stores 1 in *marker and returns 0xFF00 plus the marker byte. Otherwise bytes are shifted into accum until enough
 * bits are present and the requested bits are returned. The label ret: and the goto share one exit for the two
 * marker cases. */
struct BS {
    int pad0, pad4;
    int position;
    int bitsLeft;
    unsigned char *cursor;
    int pad14;
    int flag;
};
extern int D_00624070[];
extern "C" int func_0046ED70(BS *stream, int bitCount, int *marker) {
    unsigned accum;
    int mask = D_00624070[bitCount];
    if (stream->bitsLeft < 0) {
        stream->position++;
        stream->cursor++;
        stream->bitsLeft = 7;
        if (stream->flag == 0) {
            stream->position++;
            stream->cursor++;
            stream->flag = 1;
        }
        if (stream->cursor[0] == 0xFF) {
            if (stream->cursor[1] == 0) { stream->flag = 0; }
            else { ret: *marker = 1; return 0xFF00 + stream->cursor[1]; }
        }
    }
    bitCount = bitCount - stream->bitsLeft - 1;
    accum = *stream->cursor;
    while (bitCount > 0) {
        stream->position++;
        stream->cursor++;
        if (stream->flag == 0) {
            stream->position++;
            stream->cursor++;
            stream->flag = 1;
        }
        unsigned char *next = stream->cursor;
        accum = (accum << 8) | *next;
        if (*next == 0xFF) {
            if (next[1] == 0) { stream->flag = 0; }
            else { goto ret; }
        }
        bitCount -= 8;
    }
    stream->bitsLeft = -bitCount - 1;
    return (accum >> -bitCount) & mask;
}
