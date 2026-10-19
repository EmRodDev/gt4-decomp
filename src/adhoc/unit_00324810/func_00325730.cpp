/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_00841B80;
extern "C" void func_00323D08(void *);
extern "C" int func_00325860(void *);
extern "C" void func_00574D78(void *);

struct E { int a, b, c; };

/* Layout backed by ContextTable (0x800 entries at offset 0x30):
 *   0x00..0x2F: base
 *   0x30: entries[0x800]
 */
struct ContextTable {
    char pad0[0x30];
    E entries[0x800];
};

extern "C" int func_00325730(void *arg0) {
    ContextTable *ctx = (ContextTable *)arg0;
    E *p = ctx->entries;
    int n = 0x7ff;
    func_00574D78(arg0);
    do {
        p->a = 0;
        void *h = &p->c;
        --n;
        p->b = D_00841B80;
        ++p;
        func_00323D08(h);
    } while (n != -1);
    return func_00325860(arg0);
}
