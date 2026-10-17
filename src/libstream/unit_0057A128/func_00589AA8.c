/* compiler: ee-gcc2.9-991111 */
int func_005B2DF0(const char *, int);
int func_005B9548(void *, int);
int func_00589AA8(int unused, const char *a, int b) {
    int r = func_005B2DF0(a, b);
    if (r < 0) r = func_005B9548(0, r);
    return r;
}
