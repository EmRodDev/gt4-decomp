/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
struct Msg {
    int a;
    int b;
    int len;
    char data[1];
} __attribute__((packed));
struct Port {
    char pad0[0x10];
    Msg *msg;
    int ready;
    char pad18[0x2C - 0x18];
    int sem;
};
extern "C" {
void func_00577F80();
void *func_005A4724(void *, const void *, unsigned);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);
int func_005B1BB0(void *);
}
extern "C" int func_00565C30(Port *p, int op, const void *data, int len, int val, int block) {
    int *sem = &p->sem;
    Msg *m = p->msg;
    if (p->ready == 0 || m == 0) return 3;
    int busy = 1;
    while (func_005B1BB0(sem) == busy) {
        if (block == 0) return 5;
        func_00577F80();
    }
    m->a = op;
    m->b = val;
    m->len = len;
    if (data != 0) {
        if (len != 0) func_005A4724(m->data, data, m->len);
    }
    len += 0xC;
    int r;
    while ((r = func_005B19B0(sem, m->b, 0, m, len, 0, 0, 0, 0)) != 0) {
        if (block == 0) return 2;
        func_00577F80();
    }
    return r;
}
