/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ring { char pad00[0x24]; int base; int pad28; int head; int skip; int bias; int lock; };
extern int D_0086F7C4;
extern int D_0086F7CC;
extern int D_0086F7D8;
extern int D_0086F7DC;
extern "C" void func_005ADCC0(int);
extern "C" void func_005ADCE0(int);
extern "C" void func_00550038(Ring *r, int *addr, int *len1, int *addr2, int *len2) {
    func_005ADCE0(r->lock);
    int off = (((r->head + r->skip) << D_0086F7CC) + r->bias) & D_0086F7DC;
    int avail = (((D_0086F7C4 - r->skip) - 2) << D_0086F7CC) - r->bias;
    if (D_0086F7D8 - off >= avail) {
        *addr = r->base + off;
        *len1 = avail;
        *addr2 = 0;
        *len2 = 0;
    } else {
        *addr = r->base + off;
        *len1 = D_0086F7D8 - off;
        *addr2 = r->base;
        *len2 = avail - (D_0086F7D8 - off);
    }
    func_005ADCC0(r->lock);
}
