/* compiler: ee-gcc2.9-991111 */
int func_0058B208(void *);
int func_0058B228(int);
int func_005861D0(void) {
    int next = func_0058B228(func_0058B208(__builtin_return_address(0)));
    int old;
    __asm__ volatile ("daddu %0, $28, $0" : "=r"(old));
    __asm__ volatile ("daddu $28, %0, $0" : : "r"(next) : "$28");
    return old;
}
