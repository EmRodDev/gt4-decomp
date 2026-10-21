/* compiler: ee-gcc2.9-991111 */
typedef unsigned long u64;
struct Slot { struct Slot *next; char pad[0x3C]; };
struct Timers {
    u64 f0;
    int f8;
    int pad;
    int f10;
    struct Slot *pool;
};
extern struct Timers D_006592F0;
extern struct Slot D_00889F40[0x80];
extern void *func_005A48D8(void *, int, unsigned int);
extern int func_005AD990(int, void *, int, int);
extern int func_005AE7E8(int);
extern int func_005B72A8(void);
extern int func_005B72F8(void);
extern void func_005B7B88(int);
extern void func_005B7B98(unsigned);
extern void func_005B7BA8(int);
extern int func_005B8E88(void);
extern int func_005B8158(int);

int func_005B7BB8(unsigned int arg0)
{
    int i;
    int id;
    int intr;
    unsigned mode;
    if (D_006592F0.f8 >= 0)
        return 0x80008001;
    D_006592F0.f0 = 0;
    D_006592F0.f10 = 0;
    func_005A48D8(D_00889F40, 0, 0x2000);
    D_006592F0.pool = D_00889F40;
    for (i = 0; i < 0x80; i++)
        D_00889F40[i].next = &D_00889F40[i + 1];
    D_00889F40[0x7F].next = 0;
    func_005B8E88();
    id = func_005AD990(0xB, (void *)func_005B8158, 0, 0);
    if (id < 0)
        return 0x80009021;
    D_006592F0.f8 = id;
    intr = func_005B72A8();
    mode = *(volatile unsigned *)0x10001010;
    mode = (mode & 0xFFFFFFFCU) | arg0;
    mode |= 0x300;
    if (!(mode & 0x80)) {
        mode |= 0xC80;
        func_005B7B88(0);
        func_005B7BA8(0xFFFF);
    }
    func_005B7B98(mode);
    func_005AE7E8(0xB);
    if (intr)
        func_005B72F8();
    return 0;
}
