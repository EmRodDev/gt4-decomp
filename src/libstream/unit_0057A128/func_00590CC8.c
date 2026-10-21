/* compiler: ee-gcc2.9-991111 */
typedef int s32;
struct Srv { int p0; int p4; int p8; int pc; int p10; struct Srv *self; int p18; struct Cl *cl; int a; int b; int c; int d; };
struct Cl { struct Srv *srv; int v4; volatile int sema8; int pc; int v10; int p14; int p18; int p1c; int p20; int v24; volatile int sema; int p2c; int v30; int v34; int v38; };
struct Sema { int a; int max; int init; int d; int e; const char *opt; };
extern void func_005B0750(const char *, ...);
extern int func_005ADCA0(struct Sema *);
extern int func_005ADCB0(int);
extern int func_005ADCE0(int);
extern char D_00885AC0[];
extern struct Srv *func_00590AB8(char *);
extern void func_00590B60(struct Srv *);
extern s32 func_005B0DB0(s32, struct Srv *, s32, s32, s32, s32);

int func_00590CC8(struct Cl *cl, int a1, int mode, int a3, int a4, int a5) {
    struct Sema sp;
    struct Srv *s;
    int sem;
    if (mode != 0) {
        func_005B0750("mode must be 0 in this version.\n");
        return -1;
    }
    sp.init = 1; sp.max = 1; sp.opt = "SceMrpcBind0";
    cl->sema = func_005ADCA0(&sp);
    if (cl->sema < 0) return -3;
    func_005ADCE0(cl->sema);
    cl->v10 = a1;
    cl->v24 = 0;
    cl->v30 = a3;
    cl->v34 = a4;
    cl->v38 = a5;
    s = func_00590AB8(D_00885AC0);
    if (s == 0) {
        func_005ADCB0(cl->sema);
        return -1;
    }
    cl->srv = s;
    cl->v4 = s->p18;
    s->a = a1;
    s->b = a3;
    s->c = a4;
    s->d = a5;
    s->self = s;
    s->cl = cl;
    sp.init = 0; sp.max = 1; sp.opt = "SceMrpcBind1";
    cl->sema8 = func_005ADCA0(&sp);
    sem = cl->sema8;
    if (sem < 0) {
        func_00590B60(s);
        func_005ADCB0(cl->sema);
        return -3;
    }
    if (func_005B0DB0(0x80000019, s, 0x40, 0, 0, 0) == 0) {
        func_00590B60(s);
        func_005ADCB0(sem);
        func_005ADCB0(cl->sema);
        return -2;
    }
    func_005ADCE0(sem);
    func_005ADCB0(sem);
    if (cl->v24 == 0) func_005ADCB0(cl->sema);
    return 0;
}
