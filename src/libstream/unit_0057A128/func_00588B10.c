/* compiler: ee-gcc2.9-991111 */
struct Ops {
    int (*open)(int, const char *, int);
    int (*other[5])(void);
    int (*size)(int, int);
};
int func_005B3080(int);
int func_00588B10(struct Ops *ops, int dev, const char *name, int *out) __attribute__((register_precision (s0, 128)));
int func_00588B10(struct Ops *ops, int dev, const char *name, int *out) {
    int fd = ops->open(dev, name, 1);
    if (fd < 0) return fd;
    {
        int size = ops->size(dev, fd);
        if (size <= 0) {
            func_005B3080(fd);
            return size ? size : 0x8105902c;
        }
        *out = size;
    }
    return fd;
}
