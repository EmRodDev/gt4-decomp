struct Pair {
    int a;
    int b;
};
extern "C" int func_0056EA50(void *self, int id, void *mode, int a, int b);
extern "C" int func_0056F940(void *self, struct Pair *p, int value, int *src) {
    p->a = value;
    if (src != 0) {
        p->b = *src;
    } else {
        p->b = 0;
    }
    if (func_0056EA50(self, 0x35, p, 8, 8) < 0) {
        return -0x21E;
    }
    if (src != 0) {
        *src = p->b;
    }
    return p->a;
}
