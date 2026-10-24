/* compiler: ee-gcc2.96-as2004g */
struct Pair { int lo, hi; };
struct Req { char x0; char x1; signed char kind; char rest[0xD]; };
struct Box { char pad[0x2074]; int arg; };
struct Self {
    int handle; char pad4[0x18]; struct Pair key; int a2; int x28; char t2c[8]; int count; char pad38[4];
    int state; char pad40[4]; struct Box *box;
};
struct Api { char pad0[0x20]; int (*send)(int, struct Pair, int, struct Req *, int, int *); char pad24[0x4C]; int (*isNull)(struct Pair); };
extern struct Api *D_0064B4B0;
int func_0053EF68(struct Self *);
void func_0053EFA0(struct Self *);
void func_0053A878(void *);
void *memset(void *, int, unsigned int);

int func_0053ECE8(struct Self *self, struct Pair key, int a2, int a3) {
    struct Req req;
    int out = 0;
    int r;
    if (self == 0)
        return 2;
    if (self->state != 0)
        return 0xD6DA;
    if (D_0064B4B0->isNull(key))
        return 2;
    if (a3 == 0)
        return 2;
    if (func_0053EF68(self) != 0)
        return 100;
    memset(&self->key, 0, 0x20);
    self->x28 = 0;
    self->key = key;
    self->a2 = a2;
    self->box->arg = a3;
    req.kind = -28;
    r = D_0064B4B0->send(self->handle, self->key, a2, &req, 4, &out);
    if (r != 0 || out != 4) {
        func_0053EFA0(self);
        return r;
    }
    func_0053A878(self->t2c);
    self->count++;
    self->state = 10;
    return 0;
}
