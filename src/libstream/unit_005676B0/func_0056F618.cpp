extern "C" int func_0056EA50(void *self, int id, int *out, int a, int b) throw();
extern "C" int func_0056EB28(void *self, int x, int *p, int flag, int size) throw();
extern "C" int func_0056F618(void *self, int *p, int x, int value) {
    *p = value;
    int r = func_0056EA50(self, 10, p, 4, value * 72 + 4);
    if (r < 0) {
        return -0x21E;
    }
    int n = *p;
    if (n < 0) {
        return n;
    }
    r = func_0056EB28(self, x, p, 1, n * 72);
    if (r >= 0) {
        return *p;
    }
    return r;
}
