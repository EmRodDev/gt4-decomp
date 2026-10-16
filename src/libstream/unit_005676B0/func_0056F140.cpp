extern "C" int func_0056EA50(void *, int, int *, int, int) throw();
extern "C" int func_0056EB28(void *, int, int *, int, int) throw();
extern "C" int func_0056F140(void *self, int *p, int value, int dest, int size, int *option, int info, int *result, int last) {
    p[0] = value;
    if (option) p[1] = *option; else p[1] = 0;
    p[2] = size;
    p[3] = last;
    int r = func_0056EA50(self, 13, p, 16, size + 28);
    if (r < 0) return -542;
    int n = p[0];
    if (n < 0) return n;
    if (option) *option = p[1];
    r = func_0056EB28(self, info, p, 2, 16);
    if (r < 0) return r;
    if (result) *result = p[6];
    r = func_0056EB28(self, dest, p, 7, p[0]);
    if (r >= 0) return p[0];
    return r;
}
