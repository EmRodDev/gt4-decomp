/* compiler: ee-gcc2.9-991111 */
struct Module { char pad[0xa]; unsigned short flags; char pad2[0x18]; char *base; unsigned size, bss, extra; };
int func_005B72A8(unsigned short);
int func_005B72F8(void);
void *func_005A48D8(void *, int, unsigned);
int func_0058B1D0(struct Module *);
void func_00589A70(struct Module *, unsigned short);
int func_00588878(struct Module *m) __attribute__((register_precision (s0, 128)));
int func_00588878(struct Module *m) {
    unsigned short flags = m->flags;
    int state = flags & 15;
    int intr;
    if (!(flags & 16) && state != 1) return 0x81059035;
    if ((unsigned)(state - 6) >= 2 && state != 1) return 0x81059033;
    intr = func_005B72A8(flags);
    if (m->flags & 64) {
        func_005A48D8(m->base, 0x4d, m->size);
        func_005A48D8(m->base + m->size, 0xff, m->bss + m->extra);
    }
    func_0058B1D0(m);
    func_00589A70(m, m->flags);
    if (intr) func_005B72F8();
    return 0;
}
