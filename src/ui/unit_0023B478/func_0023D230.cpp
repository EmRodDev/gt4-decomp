/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Str {char *p;};
struct Info {const char *name;};
struct Vec {int pad;Str *begin,*end,*limit;};
extern Rep D_00659FA8;
extern char D_00698DB0[],D_00698DB8[];
extern "C" int func_0057F260(const char *) throw();
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
extern "C" void func_005DC070(Vec *,Str *,Str *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
static inline Rep *rep(Str *s) {return (Rep *)s->p-1;}
static inline char *data(Rep *r) {return (char *)(r+1);}
static inline const char *cstr(Str *s) {if(rep(s)->len==0)return D_00698DB0;data(rep(s))[rep(s)->len]=0;return data(rep(s));}
static inline char *grab(Rep *r) {if(r->sel)return func_005C2560(r);++r->ref;return data(r);}
static inline void init(Str *s,const char *text) {s->p=grab(&D_00659FA8);func_005C2630(s,0,-1,text,func_0057F260(text));}
static inline void release(Str *s) {Rep *r=rep(s);if(--r->ref==0){int size=r->cap+16;func_00326798(r,size,4,func_005C11A8()->name);}}
extern "C" void func_0023D230(void *unused,Str *arg1,Vec *arg2) {
 Str temp;
 char buf[64];
 const char *text=cstr(arg1);
 int n=rep(arg1)->len;
 if(n>0) {
  if(*text!='/') {
   init(&temp,D_00698DB8);
   if(arg2->end!=arg2->limit){Str *e=arg2->end;if(e)e->p=grab(rep(&temp));++arg2->end;}else func_005DC070(arg2,arg2->end,&temp);
   release(&temp);
   if(arg2->end!=arg2->limit){Str *e=arg2->end;if(e)e->p=grab(rep(arg1));++arg2->end;}else func_005DC070(arg2,arg2->end,arg1);
  } else {
   int start=1;
   int pos;
   for(;;) {
    pos=start;
    while(text[pos]!=' ' && text[pos]!='\t' && pos<n) {
     int off=pos-start;
     if(off>=63)return;
     buf[off]=text[start+off];
     pos++;
    }
    buf[pos-start]=0;
    init(&temp,buf);
    if(arg2->end!=arg2->limit){Str *e=arg2->end;if(e)e->p=grab(rep(&temp));++arg2->end;}else func_005DC070(arg2,arg2->end,&temp);
    release(&temp);
    while((text[pos]==' ' || text[pos]=='\t') && pos<n) pos++;
    if(pos>=n)break;
    start=pos;
   }
  }
 }
}
