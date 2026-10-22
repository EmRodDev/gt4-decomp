/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Type { const char *name; };
struct Str { char *p; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" Type *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" Str *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
static inline void construct(Str *str,const char *s) {
 Rep *r=&D_00659FA8;
 char *d;
 if(r->sel) d=func_005C2560(r);
 else { d=(char *)(r+1); int n=r->ref+1; r->ref=n; }
 str->p=d;
 func_005C2630(str,0,(unsigned)-1,s,func_0057F260(s));
}
static inline void destroy(Str *str) {
 Rep *r=(Rep *)(str->p-16);
 if(--r->ref==0) {
  int size=r->cap+16;
  func_00326798(r,size,4,func_005C11A8()->name);
 }
}
static inline void assign(Str *dst,const Str *src) {
 if(src!=dst) {
  destroy(dst);
  char *d=src->p;
  Rep *r=(Rep *)(d-16);
  if(r->sel) d=func_005C2560(r);
  else { int n=r->ref+1; r->ref=n; }
  dst->p=d;
 }
}
struct Node { char pad[0x30]; Str name; };
struct Handle { Node *p; char pad[12]; Node *get() { return p; } };
struct Pair { const char *key; const char *value; };
struct Vec { int alloc; Handle *start; Handle *finish; Handle *end; };
struct Obj { int state, flag; unsigned char byte; char pad[0x3ff]; Vec v; };
extern "C" void func_00208F00(void *,const void *);
extern "C" void func_00208F18(void *,int);
extern "C" void func_00209200(void *);
extern "C" void func_00209AB0(void *,const Str *,void *);
extern "C" void func_00209CA0(void *,const Str *,void *);
extern "C" void func_005D6130(void *,void *,const void *);
extern "C" void func_0026CD80(Obj *self,const char *text,Pair *pairs) {
 Handle old;
 Handle par;
 union { Handle h; struct { Str s; char pad[12]; } t; } u;
 struct { Str s; char pad[12]; } tmp;
 func_00208F00(&old,(char *)self->v.finish-4);
 Handle *parent=&par;
 func_00209200(parent);
 Node *n=old.p;
 construct(&u.t.s,text);
 func_00209AB0(n,&u.t.s,parent);
 destroy(&u.t.s);
 if(pairs->key) {
  Str *str=&tmp.s;
  int i=0;
  do {
   func_00209200(&u.h);
   Node *child=u.h.get();
   construct(str,pairs[i].value);
   assign(&child->name,str);
   destroy(str);
   Node *parentNode=parent->p;
   construct(str,pairs[i].key);
   func_00209CA0(parentNode,&tmp.s,&u.h);
   destroy(&tmp.s);
   func_00208F18(&u.h,2);
   i++;
  } while(pairs[i].key);
 }
 Vec *v=&self->v;
 if(v->finish!=v->end) {
  if(v->finish) func_00208F00(v->finish,parent);
  v->finish=(Handle *)((char *)v->finish+4);
 } else func_005D6130(v,v->finish,parent);
 self->state=1;
 self->flag=0;
 self->byte=0;
 func_00208F18(parent,2);
 func_00208F18(&old,2);
}
