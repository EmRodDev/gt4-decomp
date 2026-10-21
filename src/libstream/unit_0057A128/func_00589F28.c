/* compiler: ee-gcc2.9-991111 */
struct Ops {
    char pad[0x20];
    int (*read)(int, void *, int);
    int spare;
    int (*sync)(int, int *, int *);
    int (*error)(int, int);
};
extern struct Ops D_0087E1C0;
int __attribute__((register_precision (s0, 128))) func_00589F28(void *unused, int fd, void *buffer, int count) {
    int r, result;
    do {
        r = D_0087E1C0.read(fd, buffer, count);
    } while (r < 0);
    D_0087E1C0.sync(0, 0, &r);
    result = r;
    if (r < 0) { r = D_0087E1C0.error(5, r); return r; }
    return result;
}
