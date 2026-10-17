/* compiler: ee-gcc2.9-991111 */
int func_005B3438(int, void *, int);
int func_005B9548(void *, int);
int func_00589B20(int unused, int a, void *b, int c) {
    int r = func_005B3438(a, b, c);
    if (r < 0) r = func_005B9548(0, r);
    return r;
}
