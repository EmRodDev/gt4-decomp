/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk { char d[0x200]; };
struct Self {
    char pad0[0xD0];
    char decoder[0x630 - 0xD0];
    char sub[0x760 - 0x630];
    Blk *src;
    Blk *dst;
    int out;
    char pad76C[0x77C - 0x76C];
    int remain;
    float phase;
};
extern "C" {
int func_00567920(void *, void *, char *);
void *func_005A48D8(void *, int, unsigned);
void func_00551318(int, Blk *, int);
}
extern "C" void func_00558100(Self *s) {
    int n = 0;
    int size = 0xF00;
    char *p = (char *)s->src;
    while (n < 4) {
        n++;
        char *q = p;
        p += 0x500;
        s->remain = s->remain - func_00567920(s->decoder, s->sub, q);
        if (s->remain <= 0) {
            func_005A48D8(p, 0, size);
            break;
        }
        size -= 0x500;
    }
    p = (char *)s->src;
    Blk *dst = s->dst;
    for (n = 0x1200; n >= 0; n -= 0x200) {
        *dst = *(Blk *)p;
        dst++;
        *dst = *(Blk *)p;
        dst++;
        p += 0x200;
    }
    func_00551318(s->out, s->dst, 0x2800);
    s->phase = s->phase + 53.333335f;
}
