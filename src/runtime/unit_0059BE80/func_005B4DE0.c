/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Sema { int a; int max; int init; int d; int e; const char *opt; };
struct Blk { int sema; int *res; int n8; char path[0x400]; char path2[0x400]; char data[0x400]; int flags; int size; };
extern struct Blk D_008882C0;
extern int D_0065833C;
extern char D_008899C0[];
extern char D_00888F00[];
extern char D_006D2808[];
extern int func_005ADCA0(struct Sema *);
extern void func_005ADCB0(int);
extern int func_005ADCE0(int);
extern u32 func_005B2258(int, int, int, int, int, int, int, int, int, int);
extern int func_005B27C8(int);
extern void func_005B27F8(void);
extern void func_005B28F0(void);

extern void func_005B0F78(void *, int);

int func_005B4DE0(const char *path, const char *path2)
{
    struct Blk *b = &D_008882C0;
    int i;
    int sema;
    int res;
    int ok;
    struct Sema sp;
    func_005B27C8(17);
    if (D_0065833C == 0)
        func_005B28F0();
    for (i = 0; i < 0x400 && (b->path[i] = path[i]); i++);
    if (i == 0x400) {
        b->path[0x3FF] = 0;

    }
    {
        for (i=0; i<0x400 && (b->path2[i]=path2[i]); i++);
        if(i==0x400) b->path2[0x3ff]=0;
    }
    sp.max = 1;
    sp.init = 0;
    sp.opt = D_006D2808;
    sema = func_005ADCA0(&sp);
    b->res = &res;
    b->sema = sema;
    b->n8 = 4;
    func_005B0F78(&D_008882C0,0x80C);
    if ((int)func_005B2258((int)D_008899C0, 17, 0, (int)&D_008882C0, 0x80C, (int)D_00888F00, 4, 0, 0, 0) < 0) {
        func_005ADCB0(sema);
        func_005B27F8();
        return -0xB;
    }
    ok = *(int *)((u32)D_00888F00 | 0x20000000);
    func_005B27F8();
    if (ok == 0) {
        func_005ADCB0(sema);
        return -0xB;
    }
    func_005ADCE0(sema);
    func_005ADCB0(sema);
    return res;
}