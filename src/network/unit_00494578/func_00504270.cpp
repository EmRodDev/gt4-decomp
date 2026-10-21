struct Obj { char p[4]; };
struct Node { char p[0x18]; int ready; };
struct S { Obj *obj; Node *node; };
extern Obj D_006497B0;
extern "C" void func_00503A90(Obj*) throw();
extern "C" Node *func_00503D80(Obj*,int,int) throw();
extern "C" void func_00504528(S*);
extern "C" long func_00578560();
extern "C" void func_00578B10(int);
extern "C" int func_00504270(S *s,int a,int b) {
 Obj *o=s->obj;
 if(!o) {
  Obj *global=&D_006497B0;
  func_00503A90(global);
  s->obj=global;
  o=global;
 }
 Node *n=func_00503D80(o,a,b);
 s->node=n;
 if(n) {
  long start=func_00578560();
  int v = 0x055d4a7f;
  while(!s->node->ready) {
   func_00504528(s);
   func_00578B10(10000);
   if(func_00578560()-start>v) return 0;
  }
  return 1;
 }
 return (int)n;
}
