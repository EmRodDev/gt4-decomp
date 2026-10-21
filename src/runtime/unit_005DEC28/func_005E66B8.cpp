/* compiler: ee-gcc2.96-stl */
#include <stl_algobase.h>
static inline void assign_pair(float *d,const float *s,int offset) {
    d[0]=s[0]; d[1]=*(const float *)((const char *)s+offset);
}
struct Pair {
    float x,y;
    Pair(const Pair &p) { const float *q=&p.y; x=p.x; y=*q; }
    void operator=(const Pair &p) { assign_pair(&x,&p.x,4); }
};
extern "C" void free(void *) throw();
extern "C" void *func_00575E60(int,int);
extern "C" void func_005E6938(Pair *,Pair *,const Pair *);
extern "C" Pair *func_005E6970(Pair *,Pair *,Pair *,int);
extern "C" Pair *func_005E69B0(Pair *,unsigned int,const Pair *,int);
static inline Pair *ucopy_aux(Pair *first,Pair *last,Pair *result,Pair *t) {
    return func_005E6970(first,last,result,(int)t);
}
static inline Pair *ucopy(Pair *first,Pair *last,Pair *result) {
    return ucopy_aux(first,last,result,value_type(result));
}
static inline Pair *ufill_aux(Pair *first,unsigned int n,const Pair &x,Pair *t) {
    return func_005E69B0(first,n,&x,(int)t);
}
static inline Pair *ufill(Pair *first,unsigned int n,const Pair &x) {
    return ufill_aux(first,n,x,value_type(first));
}
static inline void destroy_aux(Pair *first,Pair *last,Pair *) {
    for(;first!=last;++first) {}
}
static inline void destroy_range(Pair *first,Pair *last) {
    destroy_aux(first,last,value_type(first));
}
struct Vector { int alloc; Pair *begin,*end,*cap; };
extern "C" void func_005E66B8(Vector *v,Pair *pos,unsigned int n,const Pair &x) {
    if(n!=0) {
        if((unsigned int)(v->cap-v->end)>=n) {
            Pair xcopy=x;
            unsigned int after=v->end-pos;
            Pair *oldfinish=v->end;
            if(after>n) {
                ucopy(v->end-n,v->end,v->end);
                v->end+=n;
                copy_backward(pos,oldfinish-n,oldfinish);
                func_005E6938(pos,pos+n,&xcopy);
            } else {
                ufill(v->end,n-after,xcopy);
                v->end+=n-after;
                ucopy(pos,oldfinish,v->end);
                v->end+=after;
                func_005E6938(pos,oldfinish,&xcopy);
            }
        } else {
            unsigned int oldsize=v->end-v->begin;
            unsigned int len=oldsize+max(oldsize,n);
            Pair *start=(Pair *)func_00575E60(16,len*8);
            Pair *finish=start;
            finish=ucopy(v->begin,pos,start);
            finish=ufill(finish,n,x);
            finish=ucopy(pos,v->end,finish);
            destroy_range(v->begin,v->end);
            if(v->begin) free(v->begin);
            v->begin=start;
            v->end=finish;
            v->cap=start+len;
        }
    }
}
