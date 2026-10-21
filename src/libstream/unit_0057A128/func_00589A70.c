/* compiler: ee-gcc2.9-991111 */
struct S { char pad[0x24]; int f24; };
void func_0058B140(int);
void func_0058B1C0(struct S *);
void func_00589A70(struct S *, int) __attribute__((register_precision(s0, 128)));
void func_00589A70(struct S *p, int flags) {
    if (!(flags & 0x20)) func_0058B140(p->f24);
    func_0058B1C0(p);
}
