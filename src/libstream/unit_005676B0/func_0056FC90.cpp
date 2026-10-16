extern "C" int func_0056F4D8(void *self, int *p, int *x, int value);
extern "C" int func_0056F568(void *self, int *p, int v, int c, int *flags, int d);
extern "C" int func_0056FC90(void *self, int *p, int *out) {
    int buf[0x100];
    int flags;
    int n = func_0056F4D8(self, p, buf, 0x100);
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return -2;
    }
    int i = 0;
    int *cur = buf;
    while (i < n) {
        int v = *cur;
        cur++;
        if (func_0056F568(self, p, v, 8, &flags, 4) < 0) {
            return -1;
        }
        if (flags & 2) {
            break;
        }
        i++;
    }
    if (i == n) {
        return -2;
    }
    *out = buf[i];
    return 0;
}
