/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Q {u128 q;Q(){}Q(const Q&o):q(o.q){}Q &operator=(const Q&o){q=o.q;return *this;}};
struct Obj {Q pos,rot;};
struct V3 {float x,y,z;};
extern "C" void func_004887D8(Q *,V3 *,V3 *);
extern "C" void func_0048D530(Q *,Q *,Q *);
static inline Q mul(Q *a,Q *b){Q t;func_0048D530(&t,a,b);return t;}
extern "C" void func_00418B90(Obj *self,V3 *a,V3 *b){
 Q q;
 func_004887D8(&q,a,b);
 self->rot=mul(&q,&self->rot);
}
