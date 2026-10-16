/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec { int alloc; char *b; char *e; char *cap; };
struct Blob { int a,b; unsigned n; int c; char *data; int d,e,f; };
struct Image { char *data; int *parsed; int compressed; };
struct Pic { int a; char *data; char p[8]; int w,h; char q[8]; int depth; };
struct Self { char pad[0x4C]; char *vt; char pad50[0x10]; char *image; };
struct VE { short delta,index; void *fn; };
extern "C" int func_004AE230(Blob *, int, int);
extern "C" int *func_001D3B20(Image *);
extern "C" unsigned func_001D3E08(Image *);
extern "C" unsigned func_001D3E20(Image *, char *, char *);
extern "C" void free(void *) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void *func_005A47D4(void *, const void *, unsigned) throw();
extern "C" void func_005D0F50(Vec *, char *, unsigned, const char *);
static inline char *begin(Vec *v) { return v->b; }
static inline char *end(Vec *v) { return v->e; }
static inline unsigned size(Vec *v) { return end(v)-begin(v); }
static inline void erase(Vec *v, char *first, char *last) {
    func_005A47D4(first,last,end(v)-last);
    v->e -= last-first;
}
static inline void resize(Vec *v, unsigned n, const char &x) {
    if(n < size(v)) erase(v,begin(v)+n,end(v));
    else func_005D0F50(v,end(v),n-size(v),&x);
}
extern "C" void func_001CF8D0(Self *self, int arg1, Vec *v) {
    Blob blob;
    VE *e1 = (VE *)(self->vt + 0xF8);
    Pic *pic = ((Pic *(*)(void *))e1->fn)((char *)self+e1->delta);
    VE *e2 = (VE *)(self->vt + 0x88);
    func_004AE230(&blob,*((int *(*)(void *))e2->fn)((char *)self+e2->delta),1);
    if (pic == 0 || pic->w * pic->depth * pic->h == 0) {
        resize(v,blob.n,char());
        func_005A4724(v->b,blob.data,blob.n);
    } else {
        Image img;
        Image *pi = &img;
        pi->data = blob.data;
        pi->parsed = 0;
        pi->compressed = 0;
        pi->parsed = func_001D3B20(pi);
        resize(v,func_001D3E08(pi),char());
        resize(v,func_001D3E20(pi,v->b,pic->data),char());
        self->image=pic->data;
    }
    free(blob.data);
}
