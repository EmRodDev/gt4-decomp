/* compiler: ee-gcc2.9-991111 */
int func_005B3080(int);
int func_005B9548(void *, int);
int func_00589AE0(int unused, int a) {
    int r = func_005B3080(a);
    if (r < 0) r = func_005B9548(0, r);
    return r;
}
