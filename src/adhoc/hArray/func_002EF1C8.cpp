struct Rep { int len,cap,ref,sel; };
struct Info { const char *name; };
extern Rep D_00659FA8;
extern unsigned char D_006D0E79[];
extern char D_0069D598[];
extern "C" char *func_005C2560(Rep *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
struct Str;
extern "C" Str *func_005CB368(Str *,unsigned,unsigned,unsigned,char);
struct Str {
 char *p;
 Rep *rep() const { return (Rep *)p-1; }
 static char *grab(Rep *r) { if(r->sel) return func_005C2560(r); ++r->ref; return (char *)(r+1); }
 Str() { p=grab(&D_00659FA8); }
 Str(const Str &s) { p=grab(s.rep()); }
 ~Str() { Rep *q=rep(); if(--q->ref==0) { int n=q->cap+16; func_00326798(q,n,4,func_005C11A8()->name); } }
 void push(char c) { func_005CB368(this,rep()->len,0,1,c); }
 const char *c_str() const { if(rep()->len==0) return D_0069D598; p[rep()->len]=0; return p; }
};
struct Reader { Str s; int pos; Reader(const Str &) __asm__("func_0032B8C8"); };
struct Writer { Str s; Writer() __asm__("func_0032B5C0"); };
extern "C" int func_0032B928(Reader *);
extern "C" Str &func_0032B8C0(Writer *);
extern "C" int func_005A2F88(const char *) throw();
extern "C" void func_002EF070(int,void **,Writer *) throw();
struct Vec { int alloc; void **begin,**end,**cap; };
struct Obj { char pad[16]; Vec v; };
static inline bool not_eof(int c) { return c!=-1; }
extern "C" Str func_002EF1C8(Obj *self,const Str &fmt) {
 Reader r(fmt);
 Vec *v=&self->v;
 Writer w;
 if(v->begin!=v->end) {
  void **it=v->begin;
  int c=func_0032B928(&r);
  int type;
  while((type=c)!=-1 && it!=v->end) {
   c=func_0032B928(&r);
   if(c==-1) {
    func_002EF070(type,it++,&w);
    if(it==v->end) return func_0032B8C0(&w);
    break;
   }
   if(*(unsigned char *)((int)D_006D0E79+c)&4) {
    Str count;
    do { count.push((char)c); c=func_0032B928(&r); } while(not_eof(c) && (*(unsigned char *)((int)D_006D0E79+c)&4));
    int n=func_005A2F88(count.c_str());
    for(int i=0;i<n;++i) {
     func_002EF070(type,it++,&w);
     if(it==v->end) return func_0032B8C0(&w);
    }
   } else if(c=='*') {
    do { func_002EF070(type,it++,&w); } while(it!=v->end);
    return func_0032B8C0(&w);
   } else {
    func_002EF070(type,it++,&w);
    if(it==v->end) return func_0032B8C0(&w);
   }
  }
 }
 return func_0032B8C0(&w);
}
