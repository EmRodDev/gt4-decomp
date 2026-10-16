/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Cubic {
 union {float v[4];u128 q;};
 Cubic() {} Cubic(const Cubic &p) {q=p.q;}
 Cubic &operator=(const Cubic &p) {q=p.q;return *this;}
};
extern "C" Cubic func_00421B48(const Cubic *,float);
extern "C" int func_00421768(Cubic *p,float a,float b,float c,float d,float t0,float t1) {
 if(t0!=t1) {
  float b3=b*3.0f;
  p->v[0]=a;
  float c3=c*3.0f;
  float inv=1.0f/(t1-t0);
  float a3=a*3.0f;
  float inv2=inv*inv;
  p->v[1]=(b3-a3)*inv;
  p->v[2]=(a3-(b3+b3)+c3)*inv2;
  p->v[3]=((b3-a)-c3+d)*(inv2*inv);
  *p=func_00421B48(p,t0);
  return 1;
 }
 return 0;
}
