/* compiler: ee-gcc2.96-nsa-nosib */
struct Self {
    int lock;
    char pad4[0x3C];
    int field40;
    int field44;
    int field48;
    int field4C;
    char name[1];
};
struct Slot { long long id; char pad8[0xC]; int count; };
extern Slot D_0086CB40;
extern "C" void func_00578500(int);
extern "C" char *func_005A609C(char *, const char *);
extern "C" int func_00578168(void *, int, int, int, int);
extern "C" void func_0060FB50(Self *self, int a, int b, int c, int d, const char *name) {
    func_00578500(self->lock);
    D_0086CB40.id = -1;
    D_0086CB40.count = 0;
    self->field40 = a;
    self->field44 = b;
    self->field48 = c;
    self->field4C = d;
    self->name[0] = 0;
    if (name) func_005A609C(self->name, name);
    func_00578168(self, 1, 0, 0, 0);
}
