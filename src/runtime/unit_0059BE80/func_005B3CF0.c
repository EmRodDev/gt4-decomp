/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Sema { int a,max,init,d,e; const char *opt; };
struct Blk { int sema; int *res; int n8; int fd,request; char data[0x400]; void *buf; u32 buflen,arglen; };
struct Entry { int fd,used; };
extern struct Blk D_008882C0;
extern int D_0065833C;
extern char D_008899C0[],D_00888F00[],D_006D2730[];
extern int func_005ADCA0(struct Sema *);
extern void func_005ADCB0(int);
extern int func_005ADCE0(int);
extern void *func_005A4724(void *,const void *,u32);
extern void func_005B0F78(void *,int);
extern u32 func_005B2258(int,int,int,int,int,int,int,int,int,int);
extern struct Entry *func_005B2348(u32);
extern int func_005B27C8(int);
extern void func_005B27F8(void),func_005B28F0(void);
int func_005B3CF0(u32 fd,int request,const void *argp,u32 arglen,void *bufp,u32 buflen) {
 struct Blk *b=&D_008882C0;
 struct Entry *e;
 int sema,res,ok;
 struct Sema sp;
 e=func_005B2348(fd);
 func_005B27C8(0x1a);
 if(D_0065833C==0) func_005B28F0();
 if(e==0 || e->used==0) { func_005B27F8(); return -9; }
 if(arglen>0x400 || buflen>0x400) { func_005B27F8(); return -22; }
 if(argp==0) b->arglen=0;
 else func_005A4724(b->data,argp,arglen);
 b->fd=e->fd; b->request=request; b->arglen=arglen;
 sp.max=1; sp.init=0; sp.opt=D_006D2730;
 sema=func_005ADCA0(&sp);
 b->buflen=buflen; b->res=&res; b->n8=4; b->buf=bufp; b->sema=sema;
 func_005B0F78(&D_008882C0,0x420);
 if((int)func_005B2258((int)D_008899C0,0x1a,0,(int)&D_008882C0,0x420,(int)D_00888F00,4,0,0,0)<0) {
 func_005ADCB0(sema); func_005B27F8(); return -11; }
 ok=*(int *)((u32)D_00888F00|0x20000000);
 func_005B27F8();
 if(ok==0) {func_005ADCB0(sema); return -11;}
 func_005ADCE0(sema); func_005ADCB0(sema); return res;
}
