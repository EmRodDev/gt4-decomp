/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Loads and runs a script file once: unless func_002EB758 reports it already handled, `name`
 * is resolved against the context's current directory (ctx->path) unless it is absolute, the
 * directory part (with its trailing '/') becomes the current directory while the file is
 * compiled (func_002EA7D0, from the name with its extension replaced by D_0069D298) and, when
 * the compiled code is not empty, executed (func_002EC430); the old directory is restored.
 * The strings are gcc 2.96's bastring.h basic_string with its members inline; Handle is the
 * script's ref-counted code holder, initialised through func_00309348 (which returns this). */
typedef unsigned int u32;

struct Heap { const char *name; };

extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *ptr, int size, int align, const char *name);
extern "C" u32 func_0057F260(const char *s) throw();

struct Rep {
    u32 len;
    u32 res;
    u32 ref;
    u32 selfish;
    char *data() { return (char *)(this + 1); }
    inline char *grab();
    static void operator delete(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
    void release() {
        if (--ref == 0)
            operator delete(this, sizeof(Rep) + res);
    }
};

extern "C" char *func_005C2560(Rep *r);
extern Rep D_00659FA8;

inline char *Rep::grab() {
    if (selfish)
        return func_005C2560(this);
    ++ref;
    return data();
}

struct String;
extern "C" String *func_005CE388(String *, u32, u32, const String *, u32, u32);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);

struct String {
    char *dat;
    Rep *rep() const { return (Rep *)dat - 1; }
    String() : dat(D_00659FA8.grab()) {}
    String(const String &str) : dat(str.rep()->grab()) {}
    ~String() { rep()->release(); }
    u32 length() const { return rep()->len; }
    String &replace(u32 pos, u32 n1, const char *s, u32 n2) { return *func_005C2630(this, pos, n1, s, n2); }
    String &append(const char *s, u32 n) { return replace(length(), 0, s, n); }
    String &append(const char *s) { return append(s, func_0057F260(s)); }
    String &assign(const String &s, u32 pos, u32 n) { return *func_005CE388(this,0,-1,&s,pos,n); }
    String(const String &s, u32 pos, u32 n) : dat(D_00659FA8.grab()) { assign(s,pos,n); }
    String &append(const String &s) { return *func_005CE388(this,length(),0,&s,0,-1); }
    String substr(u32 pos, u32 n) const { return String(*this,pos,n); }
    String &operator=(const String &str) {
        if (&str != this) {
            rep()->release();
            dat = str.rep()->grab();
        }
        return *this;
    }
};

inline String operator+(const String &lhs, const char *rhs) {
    String str(lhs);
    str.append(rhs);
    return str;
}


inline String operator+(const String &a, const String &b) { String s(a); s.append(b); return s; }
extern char D_0069D298[], D_0069D2A8[];
struct Alloc { Alloc() {} Alloc(const Alloc &) {} ~Alloc() {} };
struct Sym {int x; ~Sym() {}};
struct Vec { int unused; Sym *begin, *end, *cap; Vec(const Alloc &a = Alloc()) : begin(0), end(0), cap(0) {} ~Vec(); };
extern "C" void *func_00326750(u32,int,const char *);
struct Code { char pad[0x2c]; Vec v;
 Code(const Vec &v = Vec()) __asm__("func_002F45F8");
 static void *operator new(u32 n) {return func_00326750(n,4,D_0069D2A8);}
 static Code *create(const Vec &v = Vec()) { return new Code(v); }
};
struct CodePtr { Code *p; CodePtr(Code *q) : p(q) {} };
extern "C" void *func_00309348(void *, const void *);
struct Handle { Code *p; Handle(const Handle &); Handle(const CodePtr &r) { func_00309348(this, &r); } ~Handle(); Handle &operator=(const Handle &); };
struct Context { char pad[0x38]; int value; int spare; String path; };
extern "C" int func_00305620(int);
extern "C" void func_00305678(int,int);
extern "C" int func_002EB758(Context *, String *, int *) throw();
extern "C" int func_0030D8E0(String *);
extern "C" u32 func_005DACE0(const String *,char,u32);

extern "C" Heap *HSymID__tf();
extern "C" Handle func_002EA7D0(Context *,String *) throw();
extern "C" void func_002F4210(Handle *,int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct Value { int p; Value(const Value &); ~Value(); };
extern "C" Value func_002EC430(Context *,Handle *,int *);
extern "C" void func_00309378(Value *,int);
inline Value::~Value() {func_00309378(this,2);}

inline Handle::~Handle() {func_002F4210(this,2);}
inline Handle &Handle::operator=(const Handle &s) {
 if(this!=&s) { Code *q=s.p; if(q)func_003285A8(q); if(p)func_003285F8(p); p=q; } return *this;
}
static inline Sym *value_type(Sym **) {return 0;}
static inline void destroy_aux(Sym *p,Sym *last,Sym *) { for(;p!=last;++p) {p->~Sym();} }
static inline void destroy(Sym *p,Sym *last) {destroy_aux(p,last,value_type(&p));}
static inline void destroy_vec(Vec *v) {
 destroy(v->begin,v->end);
 Sym *b=v->begin; int n=v->cap-b;
 if(b) func_00326798(b,n*4,4,HSymID__tf()->name);
}
inline Vec::~Vec() {destroy_vec(this);}
extern "C" int func_002EB7A0(Context *ctx, String *name, int *env) {
 if(!func_00305620(*env)) func_00305678(*env,ctx->value);
 int result=func_002EB758(ctx,name,env);
 if(result==0) {
  String old(ctx->path);
  String path(*name);
  if(!func_0030D8E0(name)) path=ctx->path + *name;
  u32 pos=func_005DACE0(&path,'/',-1);
  if(pos!=u32(-1)) {
   u32 dirLen;
   pos=dirLen=pos+1;
   ctx->path=path.substr(0,dirLen);
  } else pos=0;
  String base=path.substr(pos,-1);
  u32 ext=func_005DACE0(&base,'.',-1);
  Handle code(Code::create());
  Handle *pc=&code;
  { String file;
    if(ext==u32(-1)) file=path+D_0069D298;
    else file=path.substr(0,ext)+D_0069D298;
    *pc=func_002EA7D0(ctx,&file);
  }
  int valid=0;
  if(pc->p) { Vec *v=&pc->p->v; valid=(v->end-v->begin)!=0; }
  if(valid) { func_002EC430(ctx,pc,env); result=1; }
  ctx->path=old;
 }
 return result;
}
