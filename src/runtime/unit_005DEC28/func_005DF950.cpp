/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int size_t;
inline void *operator new(size_t, void *p) throw() { return p; }
struct Vec4 {
 float x,y,z,w;
 Vec4(const Vec4 &o):x(o.x),y(o.y),z(o.z),w(o.w) {}
 Vec4 &operator=(const Vec4 &o) {
  if(this!=&o) { x=o.x; y=o.y; z=o.z; w=o.w; }
  return *this;
 }
};
struct Heap { const char *name; };
extern "C" Heap *MRegion__tf() throw();
extern "C" void *func_00326750(unsigned int,int,const char *);
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" Vec4 *func_005E0D98(Vec4 *,Vec4 *,Vec4 *,int);
template<class I> inline Vec4 *value_type(const I &) { return 0; }
static inline void construct(Vec4 *p,const Vec4 &v) { new(p) Vec4(v); }
static inline Vec4 *copy_aux(Vec4 *a,Vec4 *b,Vec4 *r,Vec4 *) {
 return func_005E0D98(a,b,r,0);
}
static inline Vec4 *copy_range(Vec4 *a,Vec4 *b,Vec4 *r) {
 return copy_aux(a,b,r,value_type(r));
}
static inline void destroy_aux(Vec4 *a,Vec4 *b,Vec4 *) { for(;a!=b;++a) {} }
static inline void destroy_range(Vec4 *a,Vec4 *b) { destroy_aux(a,b,value_type(a)); }
static inline void dealloc(Vec4 *p,int n) {
 if(p) func_00326798(p,n*16,4,MRegion__tf()->name);
}
static inline Vec4 *copy_back(Vec4 *a,Vec4 *b,Vec4 *r) {
 for(int n=b-a;n>0;--n) *--r=*--b;
 return r;
}
struct Vector { int alloc; Vec4 *start,*finish,*cap; };
extern "C" void func_005DF950(Vector *v,Vec4 *pos,const Vec4 &x) {
 if(v->finish!=v->cap) {
  construct(v->finish,*(v->finish-1));
  ++v->finish;
  Vec4 x_copy=x;
  copy_back(pos,v->finish-2,v->finish-1);
  *pos=x_copy;
 } else {
  const size_t old_size=v->finish-v->start;
  const size_t len=old_size!=0?2*old_size:1;
  Vec4 *new_start=(Vec4 *)func_00326750(len*16,4,MRegion__tf()->name);
  Vec4 *new_finish=new_start;
  new_finish=copy_range(v->start,pos,new_start);
  construct(new_finish,x);
  ++new_finish;
  new_finish=copy_range(pos,v->finish,new_finish);
  destroy_range(v->start,v->finish);
  dealloc(v->start,v->cap-v->start);
  v->start=new_start;
  v->finish=new_finish;
  v->cap=new_start+len;
 }
}
