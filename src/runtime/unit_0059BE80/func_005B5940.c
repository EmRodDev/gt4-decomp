/* compiler: ee-gcc2.9-991111 */
typedef unsigned int u32;
struct Sema { int a,max,init,d,e; const char *opt; };
struct Blk { int sema; int *res; int n8; char path[0x400]; char newname[0x400]; };
extern struct Blk D_008882C0;
extern int D_0065833C;
extern char D_008899C0[], D_00888F00[], D_006D2880[];
extern int func_005ADCA0(struct Sema *);
extern void func_005ADCB0(int);
extern int func_005ADCE0(int);
extern u32 func_005B2258(int,int,int,int,int,int,int,int,int,int);
extern int func_005B27C8(int);
extern void func_005B27F8(void),func_005B28F0(void);
int func_005B5940(const char *path, const char *newname) {
 struct Blk *b=&D_008882C0;
 int i,sema,res,ok;
 struct Sema sp;
 func_005B27C8(0x11);
 if (D_0065833C==0) func_005B28F0();
 for(i=0;i<0x400;i++) { if((b->path[i]=path[i])==0) break; }
 if(i==0x400) b->path[0x3ff]=0;
 for(i=0;i<0x400;i++) { if((b->newname[i]=newname[i])==0) break; }
 if(i==0x400) b->newname[0x3ff]=0;
 sp.max=1; sp.opt=D_006D2880; sp.init=0;
 sema=func_005ADCA0(&sp);
 b->res=&res; b->sema=sema; b->n8=4;
 if((int)func_005B2258((int)D_008899C0,0x18,0,(int)&D_008882C0,0x80c,(int)D_00888F00,4,0,0,0)<0) {
 func_005ADCB0(sema); func_005B27F8(); return -11; }
 ok=*(int *)((u32)D_00888F00|0x20000000);
 func_005B27F8();
 if(ok==0) { func_005ADCB0(sema); return -11; }
 func_005ADCE0(sema); func_005ADCB0(sema); return res;
}
