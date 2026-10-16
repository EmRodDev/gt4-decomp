/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Heap { const char *name; };
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *, u32, int, const char *);
struct Rep {
 u32 len, res, ref, selfish;
 char *data() { return (char *)(this + 1); }
 inline char *grab();
 static void operator delete(void *p, u32 n) { func_00326798(p,n,4,func_005C11A8()->name); }
 void release() { if (--ref == 0) operator delete(this, sizeof(Rep) + res); }
};
extern "C" char *func_005C2560(Rep *) throw();
extern Rep D_00659FA8;
inline char *Rep::grab() {
 if (selfish) return func_005C2560(this);
 ++ref;
 return data();
}
struct VEntry { short delta,index; void *fn; };
struct String;
struct Obj { int ref; virtual void v0(); virtual void v1(); virtual String toString() throw(); };
extern "C" String *func_005CE388(String *,u32,u32,const String *,u32,u32);
struct String {
 char *dat; char pad[12];
 Rep *rep() const { return (Rep *)dat - 1; }
 String() : dat(D_00659FA8.grab()) {}
 String(const String &s) : dat(s.rep()->grab()) {}
 ~String() { rep()->release(); }
 u32 length() const { return rep()->len; }
 String &append(const String &s) { return *func_005CE388(this,length(),0,&s,0,(u32)-1); }
 String &operator=(const String &s) {
  if (&s != this) { rep()->release(); dat = s.rep()->grab(); }
  return *this;
 }
};
inline String operator+(const String &a,const String &b) { String s(a); s.append(b); return s; }
static inline bool isNull(Obj *o) { return o == 0; }
struct Items { char pad[20]; int *list; char pad2[8]; int count; };
struct Owner { char pad[44]; Items *items; };
struct Self { char pad[8]; int count; };
extern "C" void func_00314B20(void *,void *);
extern "C" void func_00312318(void *,int);
extern "C" void func_003285A8(int);
extern "C" void func_003285F8(int);
static inline void assign(int *dst, int *src) {
 if (dst != src) {
  int n = *src;
  if (n) func_003285A8(n);
  int old = *dst;
  if (old) func_003285F8(old);
  *dst = n;
 }
}
extern "C" void mStringPush__execute(Self *self,Owner *owner) {
 String s;
 for (int i = 0; i < self->count; ++i) {
  Items *it = owner->items;
  int idx = it->count - 1;
  it->count = idx;
  int *slot = it->list + idx;
  Obj *o = (Obj *)*slot;
  if (!isNull(o)) {
   s = o->toString() + s;
  }
 }
 int h[4];
 func_00314B20(h,&s);
 Items *it = owner->items;
 int *dst = it->list + it->count;
 assign(dst,h);
 it->count = it->count + 1;
 func_00312318(h,2);
}
