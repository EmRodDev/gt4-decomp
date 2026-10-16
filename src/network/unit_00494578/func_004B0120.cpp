/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x1c]; int begin,cur,end; void *vptr; char pad2c[0x14]; int f40; char pad44[0xc]; char f50[1]; };
extern char D_00634B90[], D_00897FC0[];
extern "C" void func_00576788(int);
extern "C" void func_005767C0(int);
extern "C" void func_00572D48(Obj *, int, int);
extern "C" int func_00573898(Obj *);
extern "C" int setjmp(void *) __asm__("func_005A58D8");
extern "C" int func_004B0120(Obj *p, int a, int b, int c, int d, int e) {
 func_00576788((int)D_00634B90);
 p->f40=e;
 p->vptr=D_00897FC0;
 func_00572D48(p,c,d);
 p->begin=a; p->cur=a; p->end=a+b;
 int r=setjmp(p->f50);
 if (r==0) func_00573898(p);
 func_005767C0((int)D_00634B90);
 return p->end-p->begin;
}
