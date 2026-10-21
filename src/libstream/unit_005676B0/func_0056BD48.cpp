/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Coeff { char pad[0x30]; short a,b,c; };
struct Audio {
    char pad0[8]; int n8, nC; char pad10[8]; int n18, n1C;
    char pad20[4]; int n24; char pad28[4]; int *p2C;
    char pad30[4]; int *p34; void *p38, *p3C, *p40, *p44;
    int *p48; char pad4C[12]; short *p58; int *p5C;
    char pad60[8]; Coeff **p68; int n6C;
};
extern "C" void func_0056BA50(void *,void *,void *,int) throw();
extern "C" void func_0056DD70(short,short *,short *,int);
extern "C" void func_0056DF58(int *,short *,short *,int *,int,int,int *);
extern "C" void func_0056E170(int *,short *,int *,int,int,int *);
extern "C" void func_0056E2C0(int *,void *,void *,int,int,void *,int);
extern "C" void *func_005A48D8(void *,int,unsigned int);
extern char D_006CAE80[], D_006CAF00[];
extern "C" void func_0056BD48(Audio *h, void *out, int flag, int scratch) {
    int old = 0;
    if (flag) { old = h->n6C; h->n6C = 1; }
    else func_0056DD70(0x7eb8,h->p58,h->p58,h->n18);
    int n = h->n18;
    int active = h->n24;
    int bytes = n*2;
    int span = bytes+2;
    scratch += (16-scratch)&15;
    scratch += span;
    h->n1C = 1;
    short *b1 = (short *)(scratch-bytes-2);
    scratch += (16-scratch)&15;
    scratch += span;
    short *b2 = (short *)(scratch-bytes-2);
    scratch += (16-scratch)&15;
    scratch += span;
    short *b3 = (short *)(scratch-bytes-2);
    if (active) {
        Coeff *c = h->p68[h->n6C];
        short x,y,z;
        if (c) { x=c->a; y=c->b; z=c->c; }
        else { y = 0x5999; x = 0x5999; z = 0; }
        func_0056DD70(x,h->p58,b1,n);
        func_0056DD70(y,h->p58,b2,h->n18);
        func_0056DD70(z,h->p58,b3,h->n18);
    }
    int i;
    if (!flag) {
        for (i=0;i<h->nC;i++)
            h->p48[i] = (int)((float)h->p48[i]*0x1.ccccccp-1f);
    }
    for (i=0;i<h->nC;i++) h->p34[i]=h->p48[i];
    if (h->n24) {
        func_0056DF58(h->p34,b2,b1,h->p34,h->nC,h->n18,h->p5C+h->n18);
        func_0056DF58(h->p34,b3,h->p58,h->p34,h->nC,h->n18,h->p5C);
    } else {
        func_005A48D8((void *)(h->n18*4 + (int)h->p5C),0,h->n18*4);
        func_0056E170(h->p34,h->p58,h->p34,h->nC,h->n18,h->p5C);
    }
    func_0056E2C0(h->p2C,D_006CAE80,h->p38,h->n8,64,h->p40,scratch);
    func_0056E2C0(h->p34,D_006CAF00,h->p3C,h->n8,64,h->p44,scratch);
    func_0056BA50(h->p38,h->p3C,out,h->n8);
    if (flag) h->n6C = old;
}
