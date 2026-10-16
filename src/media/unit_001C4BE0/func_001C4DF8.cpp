/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
 char pad0[0x10]; int id; char pad14[0x260-0x14];
 int f260,f264,f268; void (*callback)(int,int); int f270,f274,f278,f27c,f280,f284,f288,f28c,f290,f294;
};
extern char D_008286F0[];
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" int func_0058C740(int);
extern "C" int func_0058C7F0(int);
extern "C" int func_0058C810(int);
extern "C" int func_0058CA18(int,int);
extern "C" int func_0054C8F0(int,int,int);
extern "C" int func_005B72A8();
extern "C" void func_001C5178(void *);
extern "C" void func_001C5320(void *);
extern "C" void func_001C52E8(void *);
extern "C" void func_001C49A0(int,int,int,int) throw();
extern "C" void func_001C4DF8(Obj *p) {
 func_00576788(D_008286F0);
 int notify;
 if(p->f274) {
  notify=1;
  int ready=0, idle=0;
  switch(func_0058C740(p->id)) {
  case 0: p->f28c=0; idle=1; break;
  case 1: if(p->f274) func_001C5178(p); break;
  case 2: if(p->f278) func_001C5320(p); break;
  case 3:
   func_001C52E8(p);
   p->f284=func_0058CA18(p->id,p->f260);
   if(p->f284>=0) {
    p->f290=func_0058C7F0(p->id);
    p->f294=func_0058C810(p->id);
    if(p->f264) {
     if(func_0054C8F0(1,p->f264,p->f260)!=-1) {
      p->f288=1;
      if(p->f268) {
       ready=1; notify=1;
       func_001C49A0(p->f268,p->f264,p->f290,p->f294);
       p->f28c=1;
      } else notify=0;
     } else { p->f288=0; notify=0; }
    } else notify=0;
   } else notify=0;
   break;
  }
  p->f280=idle;
  if(notify) {
   int intr=func_005B72A8();
   void (*cb)(int,int)=p->callback;
   int arg=p->f270;
   if(intr) __asm__ volatile("ei");
   if(cb) cb(arg,ready?p->f268:0);
  }
 }
 func_005767C0(D_008286F0);
}
