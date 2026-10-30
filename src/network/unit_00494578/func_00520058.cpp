// Walks a buffer of variable-length records and returns how many bytes of whole records fit
// within a limit; each record length is decoded by func_00538F98 (3 or 7 bytes extra, flag 0x80).
// Single exit label because the compiler shares the v0 = total move across all returns.
extern "C" int func_00538F98(unsigned char *, unsigned short *);
extern "C" unsigned func_00520058(unsigned char *p, unsigned len, unsigned limit) {
    unsigned char *end = p + len;
    unsigned total = 0;
    if (limit >= len) { total = len; goto done; }
    for (;;) {
        struct { unsigned char flags; unsigned short n; } h;
        unsigned step;
        if (!(p < end)) goto done;
        h.flags = *p;
        func_00538F98(p + 1, &h.n);
        step = h.n + 3;
        if (h.n != 0 && (h.flags & 0x80)) step = h.n + 7;
        if (limit < total + step) goto done;
        total += step;
        p += step;
    }
done:
    return total;
}
