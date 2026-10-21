/* compiler: ee-gcc2.9-991111 */
extern int D_00657A80;
struct Result { char pad[12]; int value; };
extern struct Result *func_0058B208(void *addr);
int func_00585928(void *addr) {
    int result;
    struct Result *p;
    if (!D_00657A80) return 0x81058001;
    result = 0x8105902D;
    p = func_0058B208(addr);
    if (p) result = p->value;
    return result;
}
