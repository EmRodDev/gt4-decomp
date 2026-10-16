inline void *operator new(unsigned int, void *p) { return p; }
struct Ent { int *ptr; int z[3]; int flag; int pad14; };
struct Dev {
    char pad0[0x84]; char *tab84; Ent *tab88; unsigned char b8c; char pad8d[0x9C - 0x8D];
    unsigned short cnt; char pad9e[0xBC - 0x9E]; unsigned int n;
};
struct Hdr { short s0; unsigned char b2; char pad3[13]; };
struct IOV { void *p; int len; };
struct IOVec {
    IOV v[8]; int total; int count;
    void init() { count = 0; total = 0; }
    void add(void *p) { v[count].p = p; v[count].len = 4; total += 4; count++; }
};
struct L { Hdr h; char iov[0x48]; char pad58[8]; };
extern "C" void func_00526040(Dev *, int *, unsigned short *);
extern "C" short func_00525648(int, int);
extern "C" int func_00527510(Dev *, int, int, int, void *);

inline unsigned short sentinel() { return 0xfffe; }
extern "C" int func_00524DD0(Dev *dev, int arg1) {
    Hdr h;
    IOVec iov;
    unsigned short s60;
    int s64;
    unsigned char idx = arg1;
    s60 = sentinel();
    s64 = 0;
    if (dev == 0) return 2;
    if (idx >= dev->n) return 2;
    if (dev->tab88 == 0) return 3;
    func_00526040(dev, &s64, &s60);
    if (s60 >= dev->cnt) {
        dev->b8c = idx;
        return 0;
    }
    Ent *e = (Ent *)((char *)dev->tab88 + idx * 0x18);
    unsigned int i;
    for (i = 0; i < dev->cnt; i++) e->ptr[i] = 0;
    for (i = 0; i < 3; i++) e->z[i] = 0;
    e->flag = 1;
    e->ptr[s60] = (int)(dev->tab84 + s60 * 0x44);
    h.s0 = func_00525648(6, 4);
    h.b2 = idx;
    iov.init();
    iov.v[iov.count].p = &h;
    iov.v[iov.count].len = 4;
    iov.total += 4;
    iov.count++;
    int r = func_00527510(dev, 0, 0, 0xF000, &iov);
    if (r == 0 || r == 0xD2F3) return 0;
    return r;
}
