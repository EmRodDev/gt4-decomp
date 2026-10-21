/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Constructor-shaped initialiser of a large object (about 0x6E88 bytes; inferred from the placement-new of a 1024-entry table of
 * 0x20-byte blank entries at offset 0 and from the field set-up). Zeroes the counters at +0x5000, +0x6E30..+0x6E38 and +0x6E80..+0x6E84,
 * builds the container at +0x5008 (func_00606568 then func_00606540 for its first pointer, count 0), stores the four initial
 * values, sets the float at +0x6E28 to 1.0, and gives the member at +0x6E18 the colour value (inferred from the Color helper
 * type kept in the source: its constructor and destructor are what make the compiler emit the temporary). The meaning of the
 * individual fields is unknown. */
inline void *operator new(unsigned, void *p) { return p; }
struct Inner { Inner() {} };
struct Blank { Inner i; char pad[0x1F]; };
struct Holder { Blank a[1024]; };

struct Obj {
    char pad0[0x5000];
    int i5000;
    int pad5004;
    char sub[0x6E14 - 0x5008];
    int i6E14;
    char s6E18[4];
    int i6E1C_;
    int i6E20;
    float f6E24;
    float f6E28;
    int pad6E2C;
    int i6E30, i6E34, i6E38;
    char s6E3C[0x6E7C - 0x6E3C];
    int i6E7C;
    int i6E80, i6E84;
};
struct Sub2 { char pad[0x1E04]; void *a; int b; };
extern "C" void func_00606568(void *);
extern "C" void *func_00606540(void *);
struct Color { unsigned v; Color(unsigned x):v(x) {} ~Color() {} };
extern "C" void func_0047E780(void *, unsigned);
extern "C" void func_004A7550(void *);

extern "C" int func_004791C0(Obj *self, int init6E14, int init6E20, int color, int init6E7C, float init6E24) {
    new (self) Holder;
    self->i5000 = 0;
    char *container = (char *)self + 0x5008;
    func_00606568(container);
    void *first = func_00606540(container);
    ((Sub2 *)container)->b = 0;
    ((Sub2 *)container)->a = first;
    self->i6E14 = init6E14;
    self->i6E20 = init6E20;
    self->f6E24 = init6E24;
    self->f6E28 = 1.0f;
    self->i6E7C = init6E7C;
    self->i6E30 = 0;
    self->i6E34 = 0;
    self->i6E38 = 0;
    int *pair = &self->i6E80;
    pair[0] = 0;
    pair[1] = 0;
    unsigned tmp[4];
    tmp[0] = color;
    func_0047E780(self->s6E18, tmp[0]);
    func_004A7550(self->s6E3C);
}
