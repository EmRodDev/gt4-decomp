/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {
 u128 q;
 V() {} V(const V &v) {q=v.q;}
 V &operator=(const V &v) {q=v.q;return *this;}
};
extern "C" char *func_0041A8C0(char *, unsigned int) throw();
extern "C" char *func_0041AA50(char *,const V *,const V *) throw();
extern "C" V func_0048D530(const V *,const V *);
struct Segment { V first, pos; };
extern "C" void func_0041AD60(char *self,const V *v,const V *w) {
 V tmp;
 for(int i=0;i<20;i++) {
  Segment *dst=(Segment *)func_0041A8C0(self,i);
  tmp=func_0048D530(&v[i],&w[1]);
  dst->pos=tmp;
 }
 func_0041AA50(self,v,w);
}
