struct Head { int p0[4]; int x10, x14; int p18; int *p1c; int x20, x24, x28, x2c; };
struct Node { int p[3]; int *pc; int x10, x14, x18; };
extern "C" Head *func_00538988(int) throw();
extern "C" int func_00538830(int *);
extern "C" int func_005428E8(int) throw();
extern "C" Node *func_00542A28(Head *, int) throw();
extern "C" void func_00542DA8(int, int, int *, int) throw();
extern "C" void func_00544718(int *, int *);
extern "C" void func_005468D0(int, int, int);
extern "C" void func_005469D0(int, int, int);
extern "C" int func_00546C28(void *, int, int, int);
extern "C" int func_00543C78(int arg0, int id, int dst, int len) {
    int a[16], b[16], c[16], d[16], word;
    Node *n = 0;
    int result = 0;
    Head *h = func_00538988(arg0);
    word = 0;
    if (len && dst) {
        func_00542DA8(dst, len, &word, 4);
        word &= 0x1fffffff;
    } else {
        len = 0;
    }
    if (!h) return 0;
    if (id == 0xfffe && func_005428E8(h->x2c) == 0) {
        result = (word & 0x1fffffff) | 0x20000000;
        if (len) {
            func_005468D0(h->x24, h->x2c, result);
            func_005469D0(h->x24, dst, len);
        }
        return result;
    }
    if (id == 0xfffd) {
        func_00544718(a, b);
        if (func_00538830(a) == 0) {
            result = (word & 0x1fffffff) | 0x80000000;
            if (len) func_00546C28(a, dst, dst, len);
        }
        return result;
    }
    if (id != 0xffff || h->x14 != id) n = func_00542A28(h, id);
    if (!n && id != 0xffff) goto out;
    if (n && func_005428E8(n->x18) == 0) {
        result = (word & 0x1fffffff) | 0x60000000;
        if (len) {
            func_005468D0(n->x10, n->x18, result);
            func_005469D0(n->x10, dst, len);
        }
        goto out;
    }
    if (func_005428E8(h->x2c) == 0 && (id == 0xffff || h->x14 != 0xffff || !n || func_00538830(n->pc) != 0)) {
        result = (word & 0x1fffffff) | 0x20000000;
        if (len) {
            func_005468D0(h->x24, h->x2c, result);
            func_005469D0(h->x24, dst, len);
        }
        goto out;
    }
    if (n && func_00538830(n->pc) == 0 && (h->x14 == 0xffff || func_005428E8(n->x18) != 0)) {
        result = (word & 0x1fffffff) | 0xe0000000;
        if (len) func_00546C28(n->pc, dst, dst, len);
        goto out;
    }
    if (id != 0xffff && func_00538830(h->p1c) == 0 && h->x14 != 0xffff) {
        int x = h->x10;
        if (x != -1) {
            if (x & 0x80000000) goto out;
        }
        func_00544718(c, d);
        if (func_00538830(c) == 0) {
            result = (word & 0x1fffffff) | 0x80000000;
            if (len) func_00546C28(c, dst, dst, len);
        }
    }
out:
    return result;
}
