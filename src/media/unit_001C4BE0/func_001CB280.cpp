/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Obj { u8 *data; u8 *start; u8 *end; int a; int b; };
struct Data { int x[4]; u8 *ptr; };
extern "C" int func_001CB240(Obj *) throw();
extern "C" int func_004AE230(Data *, int, int);
static inline int read16(u8 *p, int off) { return p[off] + (p[off + 1] << 8); }
extern "C" void func_001CB280(Obj *self, int key) {
    func_001CB240(self);
    Data data;
    func_004AE230(&data, key, 1);
    u8 *p = data.ptr;
    self->data = p;
    if (p[1] == 1) {
        int n = read16(p, 5);
        int depth = p[0x10];
        if (p[7] == 0x20) {
            if (depth == 8) {
                self->a = read16(p, 0xC);
                self->b = read16(p, 0xE);
                u8 *start = p + 0x12;
                self->start = start;
                self->end = start + n * 4;
            }
        }
    }
}
