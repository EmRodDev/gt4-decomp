typedef int s32;
extern "C" void func_00601288(int *first, int *last, int val) {
    (void)&val;
    while (first != last) {
        int tmp = val; val++; *first++ = tmp;
    }
}
