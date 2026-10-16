extern "C" int func_0056EAD0(void *self, int *out, int a, int b, int c);
extern "C" int func_0056EA50(void *self, int id, int *out, int a, int b);
extern "C" int func_0056EF70(void *self, int *out, int c) {
    int r = func_0056EAD0(self, out, 1, c, 0x40);
    if (r < 0) {
        return r;
    }
    r = func_0056EA50(self, 1, out, 0x44, 4);
    if (r < 0) {
        return -0x21E;
    }
    r = *out;
    return r != 0 ? r : -0x21C;
}
