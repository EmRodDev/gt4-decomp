/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Handler { void (*fn)(void); void *arg; int pad; };
struct Cmd { void *packet,*unused; void *iop; struct Handler *sys; int nsys; struct Handler *usr; int nusr; int *regs; };
struct Packet { int hdr[3]; int zero; void *buf; };
extern int D_006582B0,D_00886814;
extern char D_00886740[],D_008867C0[];
extern struct Cmd D_00886818;
extern struct Handler D_00886840[32];
extern int D_008869C0[32];
extern struct Packet D_00886800;
int func_005B72A8(void),func_005B72F8(void);
void func_005ADF20(int),func_005AE080(void);
int func_005AD9B0(int,void (*)(void),int);
int func_005AE8B8(int),func_005AE0B0(unsigned int);
int func_005AE0A0(int,int);
int func_005B0DB0(int,void *,int,int,int,int);
void func_005B0870(void),func_005B0850(void),func_005B0E30(void);
void func_005B08C8(void) {
    struct Cmd *c;
    struct Handler *h;
    int i,addr;
    void *p1,*p2;
    struct Cmd *cmd;
    func_005B72A8();
    if(D_006582B0) { func_005B72F8(); return; }
    p2=(void *)((u32)D_00886740|0x20000000);
    p1=(void *)((u32)D_008867C0|0x20000000);
    D_006582B0=1;
    D_00886818.packet=p2;
    D_00886818.unused=p1;
    D_00886818.iop=0;
    D_00886818.sys=D_00886840;
    D_00886818.nsys=32;
    D_00886818.usr=0;
    D_00886818.nusr=0;
    D_00886818.regs=D_008869C0;
    h=D_00886840;
    do { h->fn=0; h->arg=0; h++; } while((int)h<(int)(D_00886840+32));
    for(i=31;i>=0;i--) D_008869C0[i]=0;
    c=&D_00886818;
    i=32;
    D_00886840[0].fn=func_005B0870;
    D_00886840[0].arg=c;
    D_00886840[1].fn=func_005B0850;
    D_00886840[1].arg=c;
    func_005B72F8();
    func_005ADF20(0);
    if(*(volatile int *)0x1000e010&32) *(volatile int *)0x1000e010=i;
    if(!(*(volatile int *)0x1000c000&0x100)) func_005AE080();
    D_00886814=func_005AD9B0(5,func_005B0E30,0);
    func_005AE8B8(5);
    addr=func_005AE0B0(0x80000000);
    c->iop=(void *)addr;
    if(addr) {
        D_00886800.buf=D_00886740;
        func_005B0DB0(0x80000000,&D_00886800,20,0,0,0); return;
    }
    while(!(func_005AE0B0(4)&0x20000)) {}
    addr=func_005AE0B0(2);
    cmd=&D_00886818;
    cmd->iop=(void *)addr;
    func_005AE0A0(0x80000000,addr);
    func_005AE0A0(0x80000001,(int)cmd);
    D_00886800.buf=D_00886740;
    D_00886800.zero=0;
    func_005B0DB0(0x80000002,&D_00886800,20,0,0,0);
}
