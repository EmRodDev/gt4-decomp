extern "C" int func_0056EA50(void *, int, int *, int, int) throw();
extern "C" int func_0056EB28(void *, int, int *, int, int) throw();
extern "C" int func_0056F078(void *self, int *p, int value, int dest, int size, int *option, int last) {
    p[0] = value;
    if (option) p[1] = *option; else p[1] = 0;
    p[2] = size;
    p[3] = last;
    if (func_0056EA50(self, 4, p, 16, size + 8) < 0) return -542;
    int n = p[0];
    if (n < 0) return n;
    if (option) *option = p[1];
    int r = func_0056EB28(self, dest, p, 2, p[0]);
    if (r >= 0) return p[0];
    return r;
}
