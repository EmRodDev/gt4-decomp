/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Sema { int a; int max; int init; int d; int e; const char *opt; };
struct Ent { int p0; int p4; int p8; int pc; };
struct Blk { int sema; int *res; int n8; int pc; int p10; };
extern struct Blk D_008882C0;
extern struct Ent D_008897C0[];
extern int D_0065833C;
extern char D_008899C0[];
extern char D_00888F00[];
extern char D_006D26B8[];
extern int func_005ADCA0(struct Sema *);
extern void func_005ADCB0(int);
extern int func_005ADCE0(int);
extern u32 func_005B2258(int, int, int, int, int, int, int, int, int, int);
extern struct Ent *func_005B2348(unsigned int);
extern int func_005B27C8(int);
extern void func_005B27F8(void);

static inline int clamp_result(int x, int limit) { return x > limit ? 0 : x; }

int func_005B3080(unsigned int fd)
{
    struct Blk *b = &D_008882C0;
    struct Ent *e;
    int sema;
    int res;
    int ok;
    struct Sema sp;
    e = func_005B2348(fd);
    func_005B27C8(1);
    if (D_0065833C == 0 || e == 0 || e->p4 == 0) {
        func_005B27F8();
        return -9;
    }
    b->pc = e->p0;
    b->p10 = e - D_008897C0;
    sp.max = 1;
    sp.init = 0;
    sp.opt = D_006D26B8;
    sema = func_005ADCA0(&sp);
    b->sema = sema;
    b->res = &res;
    b->n8 = 4;
    if ((int)func_005B2258((int)D_008899C0, 1, 0, (int)&D_008882C0, 0x14, (int)D_00888F00, 4, 0, 0, 0) < 0) {
        func_005ADCB0(sema);
        func_005B27F8();
        return -0xB;
    }
    e->p4 = 0;
    ok = *(int *)((u32)D_00888F00 | 0x20000000);
    func_005B27F8();
    if (ok == 0) {
        func_005ADCB0(sema);
        return -0xB;
    }
    func_005ADCE0(sema);
    func_005ADCB0(sema);
    return clamp_result(res, -1);
}
