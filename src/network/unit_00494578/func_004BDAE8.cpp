/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk {
    char pad0[5];
    unsigned char f5;
    char pad6[2];
    unsigned char f8;
    char pad9[5];
    unsigned char fe;
    char padf[9];
    int f18;
};

extern "C" int func_004BDAE8(int unused, int flags, Blk *b, int mode, int *out0, int *out1) {
    if ((flags & 0xff00) == 0x200) {
        *out0 = b->f18;
        *out1 = b->fe;
    } else {
        if (!mode)
            *out1 = b->f8 + b->f5;
        else
            *out1 = b->f8;
        *out0 = b->f18 + b->fe - *out1;
    }
    return 0;
}
