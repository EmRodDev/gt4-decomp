/* compiler: ee-gcc2.96-no-strict-aliasing */
extern unsigned char D_00620DD9;
extern int D_00620CB0;
extern float D_00620CB8[2],D_00620CC0[2],D_00620CC8[2],D_00620CD0[2];
struct S {char p[0x18];float nlow,nbase,nhigh,plow,pbase,phigh;char p30[0x18];float nmax,pmax;};
static inline float root(float v){float r;__asm__("sqrt.s %0,%1":"=f"(r):"f"(v));return r;}
extern "C" float func_00369B48(S *s,int i,float v){
 if(D_00620DD9){
  if(v<0.0f){
   float hi=s->nhigh;
   if(v<=-hi)return s->nmax;
   float lo=s->nlow;
   float result;
   if(-lo<=v)result=(-v*s->nbase)/lo;
   else {result=s->nbase+((-v-lo)*(s->nmax-s->nbase))/(hi-lo);}
   return result;
  }
  if(v>0.0f){
   float hi=s->phigh;
   if(hi<=v)return -s->pmax;
   float lo=s->plow;
   float result;
   if(v<=lo) result=(-v*s->pbase)/lo;
   else result=-(s->pbase+((v-lo)*(s->pmax-s->pbase))/(hi-lo));
   return result;
  }
  return 0.0f;
 }
 if(v<0.0f){
  if(v<-1.0f)v=-1.0f;
  float lo=s->nlow,hi=s->nhigh,b=s->nbase;
  float out=b+hi*root(-v-lo);
  if(D_00620CB0){
   float t=D_00620CB8[i];float neg=-t;
   if(neg<v){float h=b+hi*root(t-lo);float w=D_00620CC0[i];h=h*(v*v)/(neg*neg);out=(1.0f-w)*out+w*h;}
  }
  return out;
 }
 if(v>1.0f)v=1.0f;
 float lo=s->plow,base=s->pbase;
 float z=root(v-lo);
 float b=-base;
 float out=b-s->phigh*z;
 if(D_00620CB0){
  float t=D_00620CC8[i];
  if(v<t){float h=b-s->phigh*root(t-lo);float w=D_00620CD0[i];h=h*(v*v)/(t*t);out=(1.0f-w)*out+w*h;}
 }
 return out;
}
