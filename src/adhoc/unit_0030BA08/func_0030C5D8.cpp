/* compiler: ee-gcc2.96-stl */
/* SGI STL (include/stl/stl_vector.h) instantiated by tools/stl_vector.py: vector<T_005DBC00, GameAlloc> copy_ctor */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

extern "C" void *func_00326750(int size, int align, const char *name);
extern "C" void func_00326798(void *p, int size, int align, const char *name);
extern "C" void *func_00575E60(int heap, int size);


/* gcc 2.96's type_info: the name first, the vtable pointer after it */
struct TypeInfo {
    const char *name;
};

/* typeid(T).name() without typeid: the game's own __tf getter */
template <class T> struct TypeTag;

template <class T>
class GameAlloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef GameAlloc<U> other; };
    GameAlloc() throw() {}
    GameAlloc(const GameAlloc &) throw() {}
    template <class U> GameAlloc(const GameAlloc<U> &) throw() {}
    ~GameAlloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return (T *)func_00326750(n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    void deallocate(T *p, size_type n) {
        func_00326798(p, n * sizeof(T), 4, ((TypeInfo *)TypeTag<T>::tf())->name);
    }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef unsigned int u32;
struct Rep {
 u32 len, cap, ref, sel;
 char *data() { return (char *)(this+1); }
 char *grab();
 void release();
};
struct Str;
extern Rep D_00659FA8;
extern char D_0069DEC0[], D_0069DEC8[], D_0069DED0[], D_0069DED8[];
extern "C" char *func_005C2560(Rep *);
extern "C" TypeInfo *func_005C11A8() throw();
extern "C" TypeInfo *func_005DC030();
extern "C" u32 func_0057F260(const char *) throw();
extern "C" Str *func_005C2630(Str *,u32,u32,const char *,u32);
extern "C" Str *func_005CE388(Str *,u32,u32,const Str *,u32,u32);
extern "C" int func_005CD320(const Str *,const char *,u32,u32);
extern "C" char *func_005A609C(char *,const char *);
inline char *Rep::grab() { if(sel) return func_005C2560(this); ++ref; return data(); }
inline void Rep::release() { if(--ref==0) { int size=cap+16; func_00326798(this,size,4,func_005C11A8()->name); } }
struct Str {
 char *p;
 Rep *rep() const { return (Rep *)p-1; }
 u32 size() const { return rep()->len; }
 Str() { p=D_00659FA8.grab(); }
 Str(const char *s,u32 n) { p=D_00659FA8.grab(); func_005C2630(this,0,-1,s,n); }
 Str(const Str &s) { p=s.rep()->grab(); }
 ~Str() { rep()->release(); }
 int compare(const char *s) const { return func_005CD320(this,s,0,func_0057F260(s)); }
 Str &append(const char *s,u32 n) { return *func_005C2630(this,size(),0,s,n); }
 Str &append(const char *s) { return append(s,func_0057F260(s)); }
 Str &append(const Str &s) { return *func_005CE388(this,size(),0,&s,0,-1); }
 const char *c_str() const { if(size()==0) return D_0069DED8; rep()->data()[size()]=0; return rep()->data(); }
};
inline bool operator==(const Str &s,const char *p) { return s.compare(p)==0; }
inline bool operator!=(const Str &s,const char *p) { return s.compare(p)!=0; }
template <> struct TypeTag<Str> { static void *tf() { return func_005DC030(); } };
typedef vector<Str,GameAlloc<Str> > Vec;
extern "C" void func_005DC070(Vec *,Str *,const Str *);
template<> inline void Vec::_M_insert_aux(Vec::iterator p,const Str &s) { func_005DC070(this,p,&s); }
#define CT(c) (((unsigned char *)0x6D0E79)[c])
static inline int upper(int c) { return CT(c)&2?c-32:c; }
extern "C" void func_0030C5D8(char *dst,const char *path) {
 char *out=dst;
 const char *p=path;
 int c=*p;
 unsigned char flags=CT(c);
 if ((flags&3) && p[1]==':') { *out++=upper(c); p++; *out++=*p++; }
 Vec parts;
 Vec filtered;
 const char *start=p;
 while(*p) {
  if(*p=='/') { while(*p=='/') p++; }
  else { const char *s=p; while(*p && *p!='/') p++; parts.push_back(Str(s,p-s)); }
 }
 u32 i;
 for(i=0;i<parts.size();i++) {
  if(parts[i]==D_0069DEC0 && filtered.size()!=0 && filtered.back()!=D_0069DEC0) { filtered.pop_back(); continue; }
  if(parts[i]==D_0069DEC8) { if(filtered.size()==0) filtered.push_back(parts[i]); }
  else filtered.push_back(parts[i]);
 }
 Str result;
 if(*start=='/') result.append(D_0069DED0);
 u32 n=filtered.size();
 for(i=0;i<n;i++) { result.append(filtered[i]); if(i<n-1) result.append(D_0069DED0); }
 func_005A609C(out,result.c_str());
}
