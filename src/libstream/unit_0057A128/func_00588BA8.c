/* compiler: ee-gcc2.9-991111 */
extern void *func_0058B138(int, unsigned, int);
extern int func_00588C68(int, int, int, int, void *, unsigned, int *);
extern void func_0058B140(void *);
void * __attribute__((register_precision ($16, 128))) func_00588BA8(int a, int b, int c, int *error, unsigned size, int mode) {
    void *dst = func_0058B138(mode, size, 0);
    if (dst == 0) {
        *error = 0x8105000C;
        return 0;
    }
    if (func_00588C68(a, b, c, 0, dst, size, error) != 0) {
        func_0058B140(dst);
        return 0;
    }
    *error = 0;
    return dst;
}
