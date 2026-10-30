/* compiler: ee-gcc2.96-nosib */
extern char D_00655340[];
extern void func_00576100(char *);
extern void func_00576140(char *);

struct Cb { void (*fn)(int); int pad[2]; };

void func_0055C860(char *self, int v) {
    char *p;
    struct Cb *cb, *q;
    int i;
    func_00576100(D_00655340);
    if (*(int *)self != v) {
        *(int *)self = v;
        p = self + 0xA8;
        for (i = 0; i < 48; i++) {
            if (*(int *)(p + i * 0xE0 + 0x30) != 0) {
                p[i * 0xE0 + 0x1F] = 1;
            }
        }
        cb = (struct Cb *)(self + 0x54);
        i = 6;
        q = cb;
        do {
            if (cb->fn != 0) {
                q->fn(v);
            }
            cb += 1;
            i -= 1;
            q += 1;
        } while (i >= 0);
    }
    func_00576140(D_00655340);
}
