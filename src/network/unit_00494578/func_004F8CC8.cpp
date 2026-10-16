/* compiler: ee-gcc2.96-no-strict-aliasing */
static inline bool negative(int n) { return n<0; }
void func_004F8CC8(char *a) {
    int *p = (int *)(a + 0xCBC);
    int m = -1;
    int i = 1;
    do { i--; *p = m; p--; } while (!negative(i));
}
