/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Values { int brightness, contrast, c, d; };
struct Global { char pad[0x39e34]; Values normal, other; };
extern Global *D_00622F4C;
struct Nav { char pad[20]; int a,b; };
struct Pause { char pad[12]; int c; int d; Nav *nav; int x; int state; int y,z; int retry,confirm,screen,mode; };
struct Stack { int a,b; char *end; };
struct Result { int type; float value; Result() : type(1) {} Result(int v) { value=(float)v; type=6; } Result(float v) { value=v; type=6; } };
extern "C" int func_003C3238(const char *) throw();
extern "C" char *strobe__Any__toString(void *);
extern "C" float func_00477460(void *);
extern "C" void func_00480F78(void *);
extern "C" void func_00480FA0(void *,int);
extern "C" void func_004857C8(const char *);
extern "C" int func_0057F238(const char *,const char *) throw();
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_005FBDD0(void *,const char *,unsigned,unsigned);
static inline bool eq(void *s,const char *t) { return func_005FBDD0(s,t,0,func_0057F260(t))==0; }
extern "C" Result RacePause__callFunction(Pause *p,void *name,int n,Stack *stack) {
 if(eq(name,"PLAY_SOUND")) { func_004857C8(strobe__Any__toString(stack->end-8)); }
 else if(eq(name,"SETVAL")) {
  --n;
  int which=func_003C3238(strobe__Any__toString(stack->end-8));
  func_00480F78(stack);
  int value=(int)func_00477460(stack->end-8);
  func_00480FA0(stack,n);
  Values v;
  if(p->mode) v=D_00622F4C->other; else v=D_00622F4C->normal;
  switch(which) { case 0:v.brightness=value;break;case 1:v.contrast=value;break; }
  if(p->mode) D_00622F4C->other=v; else D_00622F4C->normal=v;
  return Result();
 } else if(eq(name,"DEFAULTVAL")) {
  int which=func_003C3238(strobe__Any__toString(stack->end-8));
  func_00480FA0(stack,n);
  Values v;
  if(p->mode) v=D_00622F4C->other; else v=D_00622F4C->normal;
  return Result(which==0 ? (float)v.brightness : (float)v.contrast);
 } else if(eq(name,"EXIT_MENU")) {
  const char *s=strobe__Any__toString(stack->end-8);
  if(func_0057F238(s,"exit")==0) p->state=4;
  else if(func_0057F238(s,"retry")==0) p->state=5;
  else if(func_0057F238(s,"continue")==0) p->state=3;
  if(p->state!=4) p->c=0;
 } else if(eq(name,"RETRYENABLE")) {
  func_00480FA0(stack,n); return Result(p->retry ? 1.0f:0.0f);
 } else if(eq(name,"SCREENSETTINGENABLE")) {
  func_00480FA0(stack,n); return Result(p->screen ? 1.0f:0.0f);
 } else if(eq(name,"CONFIRMEXIT")) {
  func_00480FA0(stack,n); return Result(p->confirm ? 1.0f:0.0f);
 } else if(eq(name,"NAVIGATEVERTICAL")) {
  Nav *nav=p->nav; if(nav) {nav->a=0;nav->b=1;}
 } else if(eq(name,"NAVIGATEALL")) {
  Nav *nav=p->nav; if(nav) {nav->a=1;nav->b=1;}
 }
 func_00480FA0(stack,n); return Result();
}
