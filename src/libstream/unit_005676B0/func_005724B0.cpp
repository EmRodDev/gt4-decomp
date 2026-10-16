struct Heap {
    unsigned int w0;
    unsigned int w4;
    unsigned int w8;
    unsigned int bins[16];
};

struct Blk {
    unsigned int w0;
    unsigned int w4;
    unsigned int w8;
    unsigned int wC;
};

extern "C" int func_00572438(void *h, unsigned int size_al, unsigned int rem);

extern "C" unsigned int func_005724B0(struct Heap *h, unsigned int start, unsigned int size) {
    unsigned int al;
    unsigned int diff;
    unsigned int rem;
    unsigned int alsz;
    unsigned int old;
    unsigned int *p;
    char *bb;
    int i;
    int idx;

    al = (start + 0xF) & ~0xFu;
    diff = al - start;
    rem = size - diff;
    alsz = rem & ~0xFu;
    h->w8 = al;
    bb = (char *)h + 0xC;
    old = h->w0;
    h->w0 = al;
    h->w4 = al + alsz;
    i = 15;
    p = (unsigned int *)((char *)h + 0x48);
    do {
        i--;
        *p = 0;
        p--;
    } while (i >= 0);
    idx = func_00572438(h, alsz, rem);
    *(unsigned int *)(bb + (idx << 2)) = h->w0;
    ((struct Blk *)h->w0)->w0 = 0;
    ((struct Blk *)h->w0)->w4 = h->w4;
    ((struct Blk *)h->w0)->w8 = 0;
    ((struct Blk *)h->w0)->wC = 0;
    return old;
}
