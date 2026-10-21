/* compiler: ee-gcc2.9-as296 */
typedef unsigned int u32;
struct Packet { unsigned short a; unsigned short n; unsigned short id; unsigned char e; unsigned char h; int zero; };
struct Tty { volatile int id; volatile int a; volatile int b; volatile int c; struct Packet *tx; volatile char *rx; volatile void *queue; };
extern struct Tty D_00886410;
extern char D_00886440[];
extern char D_00886580[];
extern void func_005AF028(void);
extern void func_005ADF20(int);
extern int func_005B95A0(unsigned short, int, int);
extern void *func_005AEF80(int);
int func_005AF408(void) {
    struct Tty *t;
    struct Packet *tx;
    char *rx;
    func_005ADF20(0);
    t = &D_00886410;
    t->id = func_005B95A0(0x210, (int)t, (int)func_005AF028);
    if (t->id < 0) return 0;
    rx = (char *)((u32)D_00886580 | 0x20000000);
    tx = (struct Packet *)((u32)D_00886440 | 0x20000000);
    t->c = 0;
    t->a = 0;
    t->b = 0;
    t->rx = rx;
    t->tx = tx;
    tx->n = 0;
    tx->id = 0x210;
    tx->e = 0x45;
    tx->h = 0x48;
    tx->zero = 0;
    t->queue = func_005AEF80(0x100);
    return 1;
}
