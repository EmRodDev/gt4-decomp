/* compiler: ee-gcc2.9-991111 */
struct S {
    char p[8]; int f8; char q[0x24]; int pos; int arg;
    char r[0x14]; int (*fn)(int, int, void *, int, int);
};
extern struct S D_0087E1C0;
int func_0058A1B0(int fd, void *unused, void *buf, int size) __attribute__((register_precision(s0, 128)));
int func_0058A1B0(int fd, void *unused, void *buf, int size) {
    struct S *p = &D_0087E1C0;
    fd = p->fn(p->arg, p->f8, buf, p->pos, size);
    if (fd < 0) return fd;
    p->pos += fd;
    return fd;
}
