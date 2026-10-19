/* compiler: ee-gcc2.96-no-strict-aliasing */
struct H { void *p; char pad[12]; };
struct Rep { int len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Heap { const char *name; };
struct Ctx { char pad[76]; void *vt; };
struct Entry { short delta,idx; int (*fn)(void *); };
extern Rep D_00659FA8;
extern "C" void func_00312318(void *,int);
extern "C" void func_00314B20(void *,void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" Heap *func_005C11A8();
extern "C" char *func_005C2560(Rep *);
extern "C" Str *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
extern "C" int func_0057F260(const char *) throw();
static inline void assign(H *d,H *s) {
 if(d!=s) { void *v=s->p; if(v)func_003285A8(v); if(d->p)func_003285F8(d->p); d->p=v; }
}
static inline void init(Str *s,const char *text) {
 Rep *r=&D_00659FA8; char *q;
 if(r->sel) q=func_005C2560(r); else { q=(char *)(r+1); r->ref=r->ref+1; }
 s->p=q;
 func_005C2630(s,0,-1,text,func_0057F260(text));
}
static inline void release(Str *s) {
 Rep *r=(Rep *)(s->p-16); if(--r->ref==0) { int n=r->cap+16; func_00326798(r,n,4,func_005C11A8()->name); }
}
extern "C" void func_002EFBF0(H *);
extern "C" int func_00460BF0();
extern "C" int func_00460C18(int,const char **,const char **,const char **);
extern "C" void func_002EEEB0(H *,void *,H *);
extern "C" void func_00309378(H *,int);
extern "C" void func_003122E8(H *,int *);
extern "C" void func_002FE278(H *,int);
extern "C" void func_002FC870(H *,int);
extern "C" void func_002ED5C0(H *,int);
extern "C" void MGame__getAllMusicList(H *out) {
 H list;
 const char *name,*maker,*country;
 H row;
 H res;
 H value;
 Str s1;
 H null1;
 H value2;
 Str s2;
 H null2;
 H value3;
 Str s3;
 int z1,z2,z3;
 func_002EFBF0(&list);
 int i=0;
 int count=func_00460BF0();
 for(;i<count;i++) {
  name=0; maker=0; country=0;
  if(func_00460C18(i,&name,&maker,&country)) {
   H *r=&row; func_002EFBF0(r);
   if(name) {
    H *pr=&res; void *p=r->p; Str *s=&s1; init(s,name);
    func_00314B20(&value,s); func_002EEEB0(pr,p,&value); func_00309378(pr,2); func_00312318(&value,2); release(s);
   } else {
    H *pr=&res; void *p=r->p; z1=0; func_003122E8(&null1,&z1); func_002EEEB0(pr,p,&null1); func_00309378(pr,2); func_00312318(&null1,2);
   }
   if(maker) {
    H *pr=&res; void *p=r->p; Str *s=&s2; init(s,maker);
    func_00314B20(&value2,s); func_002EEEB0(pr,p,&value2); func_00309378(pr,2); func_00312318(&value2,2); release(s);
   } else {
    H *pr=&res; void *p=r->p; z2=0; func_003122E8(&null2,&z2); func_002EEEB0(pr,p,&null2); func_00309378(pr,2); func_00312318(&null2,2);
   }
   if(country) {
    H *pr=&res; void *p=r->p; Str *s=&s3; init(s,country);
    func_00314B20(&value3,s); func_002EEEB0(pr,p,&value3); func_00309378(pr,2); func_00312318(&value3,2); release(s);
   } else {
    H *pr=&res; void *p=r->p; z3=0; func_003122E8(&value,&z3); func_002EEEB0(pr,p,&value); func_00309378(pr,2); func_00312318(&value,2);
   }
   H *pr=&res; void *p=r->p; func_002FE278(&value,i); func_002EEEB0(pr,p,&value); func_00309378(&res,2); func_002FC870(&value,2);
   func_002EEEB0(&res,list.p,r); func_00309378(&res,2); func_002ED5C0(r,2);
  }
 }
 assign(out,&list); func_002ED5C0(&list,2);
}
