/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;
struct StringRep { u32 len,res,ref,selfish; };
struct String { char *dat; };
struct Heap { const char *name; };
struct Cb { void *vtbl; void *p; };
union Vec2 { float a[2]; };
struct Vec { int alloc; Vec2 *start,*finish,*end; };
struct Face { char pad[0xc8]; u32 flags; Vec2 uv[4]; };
extern StringRep D_00659FA8;
extern char D_0069B770[],D_0069B790[],D_0069B798[],D_0069B7A8[],D_0069B7F0[],D_0069B800[],D_0069B810[];
extern char MstringReader__vtable[], MboolReader__vtable[], D_0066CC48[];
extern "C" char *func_005C2560(StringRep *);
extern "C" String *func_005C2630(String *,u32,u32,const char *,u32);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *,u32,u32,const char *);
extern "C" int MfloatReader__structor_6(void *,void *);
extern "C" int func_0020FD38(void *,String *,void *);
extern "C" void MReaderBase__structor_0(void *,int);
extern "C" String *func_0020FE28(String *,void *,String *);
extern "C" void func_002A35F8(void *,String *);
extern "C" int MVectorReader__structor_0(void *,void *);
extern "C" void MVectorReader__structor_1(void *,int);
extern "C" void func_002A39F0(void *,int,int);
extern "C" void func_002A3A30(void *,int,int);
extern "C" void func_00575DA0(void *) throw();
union Slot { String s; Cb cb; Vec vec; Vec2 v; int n; char pad[16]; };
struct Frame { Slot path,a,b,c,flag,d,e,f,g,h,i; };
static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline String &assign(String *str, const char *s, u32 n) {
    return *func_005C2630(str, 0, (u32)-1, s, n);
}

static inline String &assign(String *str, const char *s) {
    return assign(str, s, func_0057F260(s));
}

static inline void construct(String *str, const char *s, u32 n) {
    str->dat = grab(&D_00659FA8);
    assign(str, s, n);
}

static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_00659FA8);
    assign(str, s);
}

static inline void construct(String *str) {
    str->dat = grab(&D_00659FA8);
}

static inline StringRep *rep(const String *str) { return (StringRep *)str->dat - 1; }
static inline void copy(String *str, const String *src) { str->dat = grab(rep(src)); }
static inline void deallocate(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
static inline void rep_delete(void *ptr) { deallocate(ptr, sizeof(StringRep) + ((StringRep *)ptr)->res); }
static inline void release(StringRep *r) { if (--r->ref == 0) rep_delete(r); }
static inline void destroy(String *str) { release(rep(str)); }

static inline Vec2 *value_type(Vec2 **) { return 0; }
static inline void destroy_elems(Vec2 *first,Vec2 *last,Vec2 *) { for(;first!=last;++first) first->~Vec2(); }
static inline void destroy_range(Vec2 *first,Vec2 *last) { destroy_elems(first,last,value_type(&first)); }
static inline void destroy_vec(Vec *v) { destroy_range(v->start,v->finish); if(v->start) func_00575DA0(v->start); }
static inline void setflag(Face *p,bool b,unsigned shift) { unsigned v=b; p->flags=(p->flags & ~(1u<<shift)) | (v<<shift); }
static inline void assign_vec(Vec2 *dst,const float &x,const float &y) { dst->a[0]=x; dst->a[1]=y; }
static inline float get_x(const Vec2 *p) { return p->a[0]; }
static inline float get_y(const Vec2 *p) { return p->a[1]; }
extern "C" int MboolReader__structor_11(Face *self, void *reader) {
 if(MfloatReader__structor_6(self,reader)) return 1;
 Frame f;
 construct(&f.path.s);

 int result1;
 { construct(&f.a.s,D_0069B770); Cb *cb=&f.b.cb; cb->vtbl=MstringReader__vtable; cb->p=&f.path.s;
 result1=func_0020FD38(reader,&f.a.s,cb); cb->vtbl=MstringReader__vtable; MReaderBase__structor_0(cb,0); destroy(&f.a.s); }
 if(result1) { String *p=&f.c.s; func_0020FE28(p,reader,&f.path.s); func_002A35F8(self,p); destroy(p); destroy(&f.path.s); return 1; }
 int result2;
 { construct(&f.a.s,D_0069B790); Cb *cb=&f.d.cb; cb->vtbl=MboolReader__vtable; cb->p=&f.flag.n;
 result2=func_0020FD38(reader,&f.a.s,cb); cb->vtbl=MboolReader__vtable; MReaderBase__structor_0(cb,0); destroy(&f.a.s); }
 if(result2) { setflag(self,f.flag.n!=0,0); destroy(&f.path.s); return 1; }
 int result3;
 { construct(&f.d.s,D_0069B798); Cb *cb=&f.a.cb; cb->vtbl=MboolReader__vtable; cb->p=&f.flag.n;
 result3=func_0020FD38(reader,&f.d.s,cb); cb->vtbl=MboolReader__vtable; MReaderBase__structor_0(cb,0); destroy(&f.d.s); }
 if(result3) { setflag(self,f.flag.n!=0,1); destroy(&f.path.s); return 1; }
 int result4;
 { construct(&f.d.s,D_0069B7A8); Cb *cb=&f.a.cb; cb->vtbl=MboolReader__vtable; cb->p=&f.flag.n;
 result4=func_0020FD38(reader,&f.d.s,cb); cb->vtbl=MboolReader__vtable; MReaderBase__structor_0(cb,0); destroy(&f.d.s); }
 if(result4) { setflag(self,f.flag.n!=0,2); destroy(&f.path.s); return 1; }
 Vec *v=&f.a.vec; v->start=0; v->finish=0; v->end=0;
 int result5;
 { construct(&f.d.s,D_0069B7F0); Cb *cb=&f.e.cb; cb->vtbl=D_0066CC48; cb->p=v;
 result5=func_0020FD38(reader,&f.d.s,cb); cb->vtbl=D_0066CC48; MReaderBase__structor_0(cb,0); destroy(&f.d.s); }
 if(result5) { assign_vec(&self->uv[0],f.a.vec.start[0].a[0],f.a.vec.start[0].a[1]); assign_vec(&self->uv[1],f.a.vec.start[1].a[0],f.a.vec.start[1].a[1]); assign_vec(&self->uv[2],f.a.vec.start[2].a[0],f.a.vec.start[2].a[1]); assign_vec(&self->uv[3],f.a.vec.start[3].a[0],f.a.vec.start[3].a[1]); destroy_vec(&f.a.vec); destroy(&f.path.s); return 1; }

 int result6;
 { construct(&f.f.s,D_0069B800); Cb *cb=&f.g.cb; MVectorReader__structor_0(cb,&f.d.v);
 result6=func_0020FD38(reader,&f.f.s,cb); MVectorReader__structor_1(cb,2); destroy(&f.f.s); }
 if(result6) { func_002A39F0(self,(int)get_x(&f.d.v),(int)get_y(&f.d.v)); destroy_vec(&f.a.vec); destroy(&f.path.s); return 1; }

 int result7;
 { construct(&f.h.s,D_0069B810); Cb *cb=&f.i.cb; MVectorReader__structor_0(cb,&f.f.v);
 result7=func_0020FD38(reader,&f.h.s,cb); MVectorReader__structor_1(cb,2); destroy(&f.h.s); }
 if(result7) { func_002A3A30(self,(int)get_x(&f.f.v),(int)get_y(&f.f.v)); destroy_vec(&f.a.vec); destroy(&f.path.s); return 1; }
destroy_vec(&f.a.vec); destroy(&f.path.s); return 0; }
