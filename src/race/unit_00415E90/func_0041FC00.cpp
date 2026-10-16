/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V { float x,y,z,w; V() {} V(const V &v) {*(u128 *)this=*(const u128 *)&v;} V &operator=(const V &v) {*(u128 *)this=*(const u128 *)&v;return *this;} float &X(){return x;} float &Y(){return y;} float &Z(){return z;} } __attribute__((aligned(16)));
static inline float maxf(float a,float b){float r;__asm__("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b));return r;}
static inline float minf(float a,float b){float r;__asm__("min.s %0, %1, %2":"=f"(r):"f"(a),"f"(b));return r;}
static inline float clamp(const float &a,float lo,float hi){return minf(maxf(a,lo),hi);}
static inline float rsqrt(float a){float r;__asm__("rsqrt.s %0, %1, %2":"=f"(r):"f"(1.0f),"f"(a));return r;}
static inline void scale(float &a,const float &b){a*=b;}
static inline void scaled(V *r,const V &v,float k){*r=v;r->x*=k;r->y*=k;r->z*=k;}
static inline float &value(float *p){return *p;}
static inline void angle_set(float a,float *const p){*p=a;}
extern "C" float func_0057D118(float,float);
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
extern "C" float func_0059D2A0(float);
extern "C" void func_0048D4C0(V *,const V *,const V *);
extern "C" void func_00487830(V *,const V *,float);
extern "C" void Numerical_Math__Quaternion__rotate(V *,const V *,const V *);
extern "C" int func_0041F9C0(void *,float *,int,float) throw();
extern "C" int func_0041FA68(void *,float *,int) throw();
extern V D_00622B20;
static inline void angle_calc(float *p,float a) {*p=0x1.921fb4p+0f-func_0059D2A0(a);}
extern "C" int func_0041FC00(void *self,const V *in,V *out,float p){
 V axis,work;
 float angle[4],arg[4];
 V temp,norm;
 int ok=1;
 float limit=0x1.69e954p+0f;
 float threshold=func_0057D1F0(limit);
 float z=in->z;
 *out=*in;
 if(z<threshold){
  func_0048D4C0(&work,in,&D_00622B20);
  axis=work;
  float len=axis.x*axis.x+axis.y*axis.y+axis.z*axis.z;
  if(len!=0.0f){
   arg[0]=z;
   angle_calc(angle,clamp(value(arg),-1.0f,1.0f));
   float inv=rsqrt(len);
   scaled(&norm,axis,inv);
   axis=temp=norm;
   float delta=value(angle)-limit;
   temp.X()=delta;
   func_00487830(&work,&axis,delta);
   Numerical_Math__Quaternion__rotate(&temp,&work,in);
   *out=temp;
  }else{
   float s=func_0057D2B8(limit);
   work.X()=0.0f;work.Y()=s;work.Z()=0.0f;
   *out=work;
  }
  ok=0;
 }
 float x=out->x,zz=out->z;
 if(x*x+zz*zz!=0.0f){
  temp.X()=func_0057D118(x,zz);
  func_0041F9C0(self,&temp.x,1,p);
 }else{
  temp.X()=0.0f;
  func_0041F9C0(self,&temp.x,0,1.0f);
 }
 arg[0]=out->y;
 float a=func_0059D2A0(clamp(value(arg),-1.0f,1.0f));
 temp.X()=a;
 norm.X()=a;
 func_0041FA68(self,&norm.x,1);
 return ok;
}
