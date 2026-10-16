struct Token { double value; } __attribute__((packed));
struct Obj;
struct Inner { char pad[8]; int x; int state; char pad2[0x2078 - 0x10]; void (*cb)(Obj *, int, int, double, int, void *); };
struct Obj { char pad[0x44]; Inner *inner; int m48; void *m4c; };
extern "C" void func_0053DF70(Obj *self, int b, Token token, int d) {
    if (self) {
        Inner *p = self->inner;
        p->state = 0;
        p->cb(self, b, p->x, token.value, d, self->m4c);
        self->inner->cb = 0;
        self->m4c = 0;
    }
}
