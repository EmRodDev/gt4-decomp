/* compiler: ee-gcc2.9-991111 */
typedef struct N { struct N *next; char pad[0x20]; unsigned start; unsigned a; unsigned b; unsigned c; } N;
extern N *D_008758B0;
int func_005B72A8(void);
int func_005B72F8(void);

N *func_005859F8(unsigned addr) {
    int intr = func_005B72A8();
    N *n;
    for (n = D_008758B0; n != 0; n = n->next) {
        unsigned s = n->start;
        if (addr >= s) {
            unsigned c = n->c;
            unsigned b = n->b;
            unsigned a = n->a;
            unsigned t = s + c;
            unsigned u = b + a;
            if (addr < t + u) {
                if (intr) func_005B72F8();
                return n;
            }
        }
    }
    if (intr) func_005B72F8();
    return 0;
}
