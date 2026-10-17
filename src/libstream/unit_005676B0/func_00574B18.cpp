/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Stream {
    char pad0[0x14];
    int f14;
    char pad18[4];
    int f1C, f20, f24;
    int *f28;
    char pad2C[0x40 - 0x2C];
    int f40;
    const void *vtable;
    int f48;
};
extern char D_00689D40[];
extern "C" int func_00572CD8(Stream *);
extern "C" void func_00572D48(Stream *, int, int);
extern "C" int func_00573898(Stream *);
extern "C" int func_00574B18(Stream *s, int size, int a, int b) {
    func_00572CD8(s);
    s->vtable = D_00689D40;
    s->f40 = b;
    func_00572D48(s, a, -1);
    s->f1C = size;
    s->f20 = size;
    s->f24 = size - 1;
    s->f28 = &s->f48;
    s->f14 = 0;
    return func_00573898(s);
}
