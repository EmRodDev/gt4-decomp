/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned int u32;

struct SemaParam {
    int count;
    int max_count;
    int init_count;
    int wait_threads;
    u32 attr;
    u32 option;
};

struct DevctlArg {
    int pad0;
    int size;
    int addr;
    int count;
};

struct DevctlBuf {
    int sema;
    int *result;
    int rsize;
    char name[0x400];
    char arg[0x400];
    int cmd;
    u32 arglen;
    void *bufp;
    u32 buflen;
};

extern int D_0065833C;
extern struct DevctlBuf D_008882C0;
extern char D_008899C0[];
extern char D_00888F00[];
extern char D_006D2868[];

extern int func_005B27C8(int);
extern void func_005B28F0(void);
extern void func_005B27F8(void);
extern int func_005ADCA0(struct SemaParam *);
extern int func_005ADCB0(int);
extern int func_005ADCE0(int);
extern void func_005B0F78(void *, int);
extern int func_005B2258(void *, int, int, void *, int, void *, int, void *, void *, int);

int func_005B5698(const char *name, int cmd, struct DevctlArg *arg, u32 arglen, void *bufp, u32 buflen)
{
    struct SemaParam sp;
    int result;
    int sema;
    int rpc;
    int i;
    u32 j;
    int stat;
    struct DevctlBuf *b;

    func_005B27C8(0x17);
    b = &D_008882C0;
    if (D_0065833C == 0) {
        func_005B28F0();
    }
    for (i = 0; i < 0x400; i++) {
        if ((b->name[i] = name[i]) == 0) {
            break;
        }
    }
    if (i == 0x400) {
        b->name[0x3FF] = 0;
    }
    if (arglen > 0x400 || buflen > 0x400) {
        goto inval;
    }
    if (cmd == 0x4601) {
        if (arg->size == 0) {
            func_005B27F8();
            return 0;
        }
        if (arg->count == 0) {
        inval:
            func_005B27F8();
            return -22;
        }
    }
    for (j = 0; j < arglen; j++) {
        b->arg[j] = ((char *)arg)[j];
    }
    b->arglen = arglen;
    b->cmd = cmd;
    sp.init_count = 0;
    sp.max_count = 1;
    sp.option = (u32)D_006D2868;
    sema = func_005ADCA0(&sp);
    b->buflen = buflen;
    b->result = &result;
    b->rsize = 4;
    b->bufp = bufp;
    b->sema = sema;
    if (cmd == 0x4601) {
        rpc = 0x1C;
        func_005B0F78((void *)arg->addr, arg->size * arg->count);
    } else {
        rpc = 0x17;
    }
    func_005B0F78(&D_008882C0, 0x81C);
    if (func_005B2258(D_008899C0, rpc, 0, &D_008882C0, 0x81C, D_00888F00, 4, 0, 0, 0) < 0) {
        func_005ADCB0(sema);
        func_005B27F8();
        return -11;
    }
    stat = *(int *)((u32)D_00888F00 | 0x20000000);
    func_005B27F8();
    if (stat == 0) {
        func_005ADCB0(sema);
        return -11;
    }
    func_005ADCE0(sema);
    func_005ADCB0(sema);
    return result;
}
