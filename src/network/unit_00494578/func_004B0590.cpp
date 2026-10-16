/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Ent { char pad[0x14]; s32 u14; };
struct Q { s32 a; s32 b; };
struct Obj {
    char pad0[0x1C];
    s32 u1C, u20, u24;
    char pad28[0x3298 - 0x28];
    Ent *u3298;
    char pad329C[8];
    Q q;
    s32 u32AC;
};
extern "C" void func_00574EB0(void *);
extern "C" void func_00574EE8(void *);
extern "C" int func_005A5930(void *, s32) __attribute__((noreturn));
extern "C" void func_004B0590(Obj *self) {
    self->u32AC = self->u24 - self->u1C;
    func_00574EE8((char *)self + 0x3260);
    func_00574EB0((char *)self + 0x3230);
    Q *q = &self->q;
    s32 v = q->a;
    s32 e = v + q->b;
    self->u20 = v;
    self->u24 = e;
    self->u1C = v;
    if (self->q.b == 0) {
        self->u3298->u14 = 1;
        func_005A5930((char *)self + 0x30A0, 1);
    }
}
