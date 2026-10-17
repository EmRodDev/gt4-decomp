/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep {int len,cap,ref,sel;};
struct Str {char *p; char pad[12];};
struct H {void *p; char pad[12];};
struct Info {const char *name;};
struct Obj {int zero; char *vt;};
struct Ent {short d,i; void (*fn)(void *,void *);};
extern char D_00698CA0[],D_00698CA8[];
extern Rep D_00659FA8;
extern "C" void func_0023B1D8(void *,int) throw();
extern "C" void func_0023B230(void *,void *) throw();
extern "C" void func_0023CA78(void *,const char *,const char *);
extern "C" void func_002ED5C0(void *,int);
extern "C" void *func_002ED618(void *,void *);
extern "C" void *func_002EEEB0(void *,void *,void *);
extern "C" int hArray__size(void *);
extern "C" void func_002EFBF0(void *);
extern "C" void **HArray__operator_index(void *,int);
extern "C" void func_00309378(void *,int);
extern "C" void func_00312318(void *,int);
extern "C" void func_00312370(void *,void *);
extern "C" void func_00314B20(void *,void *);
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_00594470(const char *,const char *,unsigned);
extern "C" void func_005A6AB0(void *,const void *,int) throw();
extern "C" Info *func_005C11A8();
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline int str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *cstr(Str *s) {
    if (str_length(s) == 0) return D_00698CA0;
    str_terminate(s);
    return rep_data(str_rep(s));
}
static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) { int size = q->cap + 0x10; func_00326798(q, size, 4, func_005C11A8()->name); }
}
static inline void getstr(Str *s,void *p) {Obj *o=(Obj *)p;Ent *e=(Ent *)(o->vt+0x18);e->fn(s,(char *)o+e->d);}
static inline void assign(void **a,void **b) {if(a!=b){void *p=*b;if(p)func_003285A8(p);if(*a)func_003285F8(*a);*a=p;}}
extern "C" void MShell__getCandidates(void **out,void *arg1,int argc,void **args) {
 union {Str s; H h;} u0;
 H array;
 union {Str s; H h;} u20;
 H temp;
 H handle;
 char buf[256];
 union {Str s; H h;} u150;
 Str str;
 if(argc>=2) {
  getstr(&u0.s,args[0]);
  const char *prefix=cstr(&u0.s);
  release(&u0.s);
  int len=func_0057F260(prefix);
  func_002ED618(&u0.h,args+1);
  func_002EFBF0(&array);
  int n=hArray__size(u0.h.p);
  for(int i=0;i<n;++i) {
   H *pt=&temp;
   getstr(&u20.s,*HArray__operator_index(&u0.h,i));
   int cmp=func_00594470(prefix,cstr(&u20.s),len);
   release(&u20.s);
   if(cmp==0) {
    void *ap=array.p;
    func_00312370(&handle,HArray__operator_index(&u0.h,i));
    func_002EEEB0(pt,ap,&handle);
    func_00309378(pt,2);
    func_00312318(&handle,2);
   }
  }
  n=hArray__size(array.p);
  if(n==1) {assign(out,HArray__operator_index(&array,0));}
  else if(n>=2) {
   H *shell=&u20.h;
   func_0023B230(shell,arg1);
   buf[0]=0;
   for(int j=0;j<n;++j) {
    getstr(&u150.s,*HArray__operator_index(&array,j));
    const char *text=cstr(&u150.s);
    release(&u150.s);
    if(buf[0]==0) func_005A6AB0(buf,text,256);
    else {
     int k,blen=func_0057F260(buf);
     for(k=0;k<blen;++k) {if(buf[k]!=text[k])break;}
     buf[k]=0;
    }
    func_0023CA78(shell->p,text,D_00698CA8);
   }
   Str *ps=&str;
   char *p;
   if(D_00659FA8.sel)p=func_005C2560(&D_00659FA8);
   else {p=(char *)(&D_00659FA8+1);++D_00659FA8.ref;}
   ps->p=p;
   func_005C2630(ps,0,-1,buf,func_0057F260(buf));
   func_00314B20(&u150.h,ps);
   assign(out,&u150.h.p);
   func_00312318(&u150.h,2);
   release(ps);
   func_0023B1D8(shell,2);
  }
  func_002ED5C0(&array,2);
  func_002ED5C0(&u0.h,2);
 }
}
