/* compiler: ee-gcc2.96-nsa-nosib */
struct Self {
    int lock;
    char pad4[0x38];
    int active;
    char pad40[0x40];
    int field80;
    int field84;
    int field88;
    int field8C;
    char pad90[0x30];
};
extern int D_0064C3C8;
extern "C" void func_00578500(int);
extern "C" void func_00578480(int);
extern "C" void func_00576AD8(int, int);
extern "C" int func_00578168(void *, int, int, void *, int);
extern "C" void func_0060FF18(Self *self, int a, int b, int c, int d) {
    func_00578500(D_0064C3C8);
    func_00578500(self->lock);
    self->active = 1;
    self->field80 = b;
    self->field8C = d;
    self->field84 = c;
    self->field88 = a;
    func_00576AD8(a, c);
    func_00578168(self, 3, 1, (char *)self + 0xC0, 0x40);
    func_00578480(D_0064C3C8);
}
