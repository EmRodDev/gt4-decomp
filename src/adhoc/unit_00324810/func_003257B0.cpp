/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00325860(void *);
extern "C" void func_00323B60(void *, int);
extern "C" void func_00574DA8(void *, int);
extern "C" void func_005C1628(void *) throw();

struct E { int a, b, c; };

/* Layout backed by ContextTable (0x800 entries at offset 0x30):
 *   0x00..0x2F: base
 *   0x30: entries[0x800]
 *   0x6030: end of entries
 */
struct ContextTable {
    char pad0[0x30];
    E entries[0x800];
};

extern "C" void func_003257B0(void *arg0, int flags) {
    func_00325860(arg0);
    if ((char *)arg0 != (char *)-0x30) {
        ContextTable *ctx = (ContextTable *)arg0;
        E *p = &ctx->entries[0x800];
        E *begin = ctx->entries;
        while (begin != p) {
            --p;
            func_00323B60(&p->c, 2);
        }
    }
    func_00574DA8(arg0, 2);
    if (flags & 1) return func_005C1628(arg0);
}
