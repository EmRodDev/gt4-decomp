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

typedef unsigned char u8;
typedef vector<u8, Alloc<u8> > Vec;
extern "C" u8 *func_005CDDB8(u8 *, unsigned int, const u8 *);
template <> inline u8 *fill_n<u8 *, unsigned int, u8>(u8 *p, unsigned int n, const u8 &v) { return func_005CDDB8(p,n,&v); }
struct Image { int f0; u8 *data; int f8, fC, width, height, cols, rows, channels; float aspect; };
extern "C" int func_00331A28(int, int) throw() __attribute__((const));
extern "C" void func_00331520(Image *, int, int) throw();
extern "C" void func_00331A58(Image *, int, int) throw();
extern "C" void func_00331608(Image *) throw();
extern "C" void func_00331B40(Image *img) {
    int cols=img->cols;
    if(cols!=1) return;
    if(img->rows!=cols) return;
    int w=img->width, h=img->height;
    int g=func_00331A28(w,h);
    int nx=w/g, ny=h/g;
    unsigned int stride=img->channels;
    int channels=stride;
    bool split=g!=w;
    if(split) func_00331520(img,nx,ny);
    for(int y=0;y<ny;++y)
        for(int x=0;x<nx;++x)
            func_00331A58(img,x,y);
    if(split) {
        int row=img->width*img->channels;
        int tile=row*img->height;
        int copySkip=tile*nx-channels;
        int writeSkip=tile-channels;
        Vec tmp((Vec::size_type)(nx*ny*stride));
        for(int y=0;y<g;++y) {
            for(int x=0;x<g;++x) {
                u8 *out=&tmp[0];
                u8 *block=img->data+(y*row+x*stride);
                for(int a=0;a<nx;++a) {
                    u8 *p=block;
                    for(int b=0;b<ny;++b) {
                        for(int c=0;c<channels;++c) *out++=*p++;
                        p+=copySkip;
                    }
                    block+=tile;
                }
                u8 *in=&tmp[0];
                u8 *p=img->data+(y*row+x*stride);
                for(int a=0;a<nx*ny;++a) {
                    for(int c=0;c<channels;++c) *p++=*in++;
                    p+=writeSkip;
                }
            }
        }
        swap(img->width,img->height);
        swap(img->cols,img->rows);
        img->aspect=1.0f/img->aspect;
        func_00331608(img);
    }
}
