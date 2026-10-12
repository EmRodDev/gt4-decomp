struct VEntry {
    short delta;
    short pad2;
    void *tf;
};

struct Node {
    char pad0[4];
    VEntry *e;
    char pad1[0x4C];
    Node *next;
};

extern "C" int func_0025C110(Node *arg0);
extern "C" int func_005C0FC8(void *, void *, int, void *, void *, void *);
extern char D_005DAD50[];
extern char D_005DEA30[];

extern "C" int func_0025C178(Node *self) {
    int r;
    if (self->next != 0)
        return func_0025C110(self->next);
    if (self != 0) {
        VEntry *e = self->e;
        r = func_005C0FC8(e->tf, D_005DAD50, 0, (char *)self + e->delta, D_005DEA30, self);
    } else {
        r = 0;
    }
    return r;
}
