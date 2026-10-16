extern void func_005A609C(char *, const char *);
int func_0056EC10(void *unused, char *dest, const int *base, int index) {
    if (dest == 0) return 0;
    func_005A609C(dest, (const char *)(base + index));
    return 0;
}
