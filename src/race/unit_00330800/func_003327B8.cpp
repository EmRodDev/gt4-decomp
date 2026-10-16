/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
#include <stl_alloc.h>
#include <stl_construct.h>
#include <stl_uninitialized.h>
#include <stl_vector.h>

typedef int s32;

extern "C" void *func_00575E60(int heap, int size);
extern "C" void free(void *) throw();

template <class T>
class Alloc {
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef const T *const_pointer;
    typedef T &reference;
    typedef const T &const_reference;
    typedef T value_type;
    template <class U> struct rebind { typedef Alloc<U> other; };
    Alloc() throw() {}
    Alloc(const Alloc &) throw() {}
    template <class U> Alloc(const Alloc<U> &) throw() {}
    ~Alloc() throw() {}
    T *allocate(size_type n, const void * = 0) {
        return n == 0 ? 0 : (T *)func_00575E60(0x10, n * sizeof(T));
    }
    void deallocate(T *p, size_type n) { free(p); }
    size_type max_size() const throw() { return size_t(-1) / sizeof(T); }
    void construct(T *p, const T &v) { new (p) T(v); }
    void destroy(T *p) { p->~T(); }
};

typedef vector<unsigned char, Alloc<unsigned char> > Vec;

extern "C" void func_005CD9E8(Vec*, Vec::iterator, Vec::size_type, const unsigned char &);
template <> inline void Vec::insert(Vec::iterator p, Vec::size_type n, const unsigned char &v) { func_005CD9E8(this,p,n,v); }
struct Image : Vec { int w,h,c,d,e; float scale; int row; };
extern "C" int func_00575D00();
extern "C" void func_005CD968(Vec*);
static inline int tilebytes(Image *p) { return p->w*p->e*p->h; }
extern "C" void func_003327B8(Image *self, unsigned char *src, int w, int h, int channels, int outw, int row, unsigned char *alpha) {
 if(outw<0) outw=w;
 int nchan=channels+(alpha!=0);
 int oh=self->h;
 int old=self->w*self->e;
 old*=oh;
 int cd=self->c*self->d;
 old*=cd;
 unsigned int size=outw*h*nchan;
 self->scale=1.0f;
 self->row=row<0?h:row;
 self->w=outw; self->h=h; self->c=nchan; self->d=1; self->e=1;
 unsigned int avail=func_00575D00();
 if(size!=old){
  func_005CD968(self);
  if(avail>=size) self->resize(size);
 }
 int pad=outw-w;
 int left=pad/2;
 int right=pad-left;
 for(int c=0;c<nchan;c++){
  unsigned char *dst=(unsigned char*)self->begin()+tilebytes(self)*c;
  for(int y=h-1;y>=0;y--){
   dst+=left;
   if(c==channels && alpha){
    unsigned char *p=alpha+y*w;
    for(int x=0;x<w;x++) *dst++=*p++;
   }else{
    unsigned char *p=src+c+y*w*channels;
    for(int x=0;x<w;x++){ *dst++=*p; p+=channels; }
   }
   dst+=right;
  }
 }
}
