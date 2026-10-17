/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node {
    int kind;
    int size;
    int handle;
    int mode;
};
struct Desc {
    int kind;
    char pad4[4];
    int handle;
    char padC[0x20 - 0xC];
    int size;
};
extern "C" int func_00538BF8(Node **, int);
extern "C" int func_00538C68(Node **);
extern "C" int func_0056EF70(int, int, int *);
extern "C" int func_00571530(Node *);
extern "C" int func_005715D8(Node *);
extern "C" int func_00570128(int a, int b, Node **out, Desc *d) {
    Node *n;
    int r;
    if (out == 0 || d == 0) return -0x200;
    *out = 0;
    n = 0;
    if (func_00538BF8(&n, 0x28) != 0) return -0x1F5;
    if (n == 0) return -0x1F5;
    n->kind = d->handle;
    n->size = d->size;
    if (n->kind == 0) n->mode = d->kind;
    else if (n->kind == 3) {
        n->mode = 4;
    } else {
        n->mode = 0;
    }
    if (func_00571530(n) != 0) {
        func_00538C68(&n);
        return -0x1F5;
    }
    r = func_0056EF70(a, b, &d->handle);
    if (r < 0) {
        func_005715D8(n);
        func_00538C68(&n);
        return r;
    }
    n->handle = r;
    *out = n;
    return 0;
}
