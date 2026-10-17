extern const unsigned char *D_00645424; /* base64 alphabet */
/* Encodes len bytes of src as base64 into dst (padding with '='); returns the number of characters written. */
extern "C" int func_0060DD00(int unused, char *dst, const signed char *src, unsigned len) {
    int bits = 0;
    int out = 0;
    while (len >= 3) {
        bits = ((src[0] << 16) | (src[1] << 8)) | src[2];
        src += 3;
        len -= 3;
        *dst++ = D_00645424[(bits >> 18) & 0x3F];
        *dst++ = D_00645424[(bits >> 12) & 0x3F];
        *dst++ = D_00645424[(bits >> 6) & 0x3F];
        *dst++ = D_00645424[bits & 0x3F];
        out += 4;
    }
    if (len != 0) bits = src[0] << 16;
    if (len >= 2) bits |= src[1] << 8;
    if (len != 0) {
        *dst++ = D_00645424[(bits >> 18) & 0x3F];
        *dst++ = D_00645424[(bits >> 12) & 0x3F];
        char *third = dst++;
        if (len >= 2) *third = D_00645424[(bits >> 6) & 0x3F];
        else *third = '=';
        *dst = '=';
        out += 4;
    }
    return out;
}
