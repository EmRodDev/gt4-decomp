/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { int pad0; Node *parent; Node *left; Node *right; };
struct Tree {              /* map header at +0x8C */
    int pad0;
    Node *header;
    int size;
};
struct Rep { int pad0; int pad4; int refs; };
struct Obj {
    char pad0[0x54];
    char *text;            /* refcounted string data, Rep lives 0x10 before */
    int pad58;
    char *vtable;
    char pad60[0x2C];
    Tree tree;             /* 0x8C */
    char pad98[0xC];
    int member;            /* 0xA4 */
    int dataA8;
};
extern char D_00688A80[], D_00688A20[];
extern "C" void func_00575DA0(void *);
extern "C" int func_005C1628(int);
extern "C" void func_00606258(void *, Node *);
extern "C" void func_00608FD0(void *);
extern "C" int func_00608E38(Obj *self, int flags) {
    Tree *t = &self->tree;
    int *m = &self->member;
    *(char **)&self->vtable = D_00688A80;
    func_00608FD0(m);
    func_00575DA0((void *)m[1]);
    if (t->size != 0) {
        func_00606258(t, t->header->parent);
        t->header->left = t->header;
        t->header->parent = 0;
        t->header->right = t->header;
        t->size = 0;
    }
    func_00575DA0(t->header);
    self->vtable = D_00688A20;
    Rep *rep = (Rep *)(self->text - 0x10);
    if (--rep->refs == 0) func_00575DA0(rep);
    if (flags & 1) return func_005C1628((int)self);
}
