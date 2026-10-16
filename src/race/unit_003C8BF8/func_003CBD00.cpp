/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { char pad[0x50]; int busy[6]; int other[6]; };
struct V3 { float x,y,z; };
struct Status { char pad[0x170]; int a,b; };
extern "C" void func_0046BEC0(void *,int,float *,float *,int *);
extern "C" void *func_0034C190(void *,int);
extern "C" float func_00344798(void *,float);
extern "C" float func_003447F8(void *,float);
extern "C" float func_00344828(void *,float);
extern "C" int func_003D29B0(void *,int,int);
static inline int active(void *p,int i,int offset,int stride) {
 Status *s=(Status *)(i*stride+(int)p+offset);
 int a=0;
 if(s->a!=0 || s->b!=0) a=1;
 return a;
}
extern "C" int func_003CBD00(O *o,char *ctx,int i,void *data,int old,int state,int *changed) {
 int sp0;
 V3 v;
 V3 v2;
 int result=-1;
 func_0046BEC0(ctx+0xDA50,i,&v.x,&v2.x,&sp0);
 void *p=func_0034C190(ctx,i);
 if(changed) *changed=0;
 if(o->busy[i]==0 && state>0) {
  if(state<2) {
   if(o->other[i]!=0) result=8;
   else {
    float x; float z;
    x=func_00344798(p,0.0f)-v.x;
    z=func_003447F8(p,0.0f)-v.z;
    float y=func_00344828(p,0.0f)+v.y;
    float sum=(x*x)+(z*z)+(y*y);
    if(old!=4 || !(sum<=25.0f)) {
     result=4;
     if(old==8) result=8;
    } else result=8;
   }
  } else if(state<5) {
   bool all=false;
   if(active(data,i,0x3E4,0x8D0)) {
    if(active(data,i,0x55C,0x8D0)) {
     if(active(data,i,0x6D4,0x8D0)) {
      if(active(data,i,0x84C,0x8D0)) all=true;
     }
    }
   }
   if(func_003D29B0(data,i,-1)!=0 || (result=state<3?12:14, all)) result=16;
   if(changed && result!=old) {
    if(all) *changed=1;
   }
  } else {
   float x; float z;
    x=func_00344798(p,0.0f)-v.x;
    z=func_003447F8(p,0.0f)-v.z;
    float y=func_00344828(p,0.0f)+v.y;
    float sum=(x*x)+(z*z)+(y*y);
   if(old==-1 || (result=20, !(sum<=900.0f))) result=-1;
  }
 }
 return result;
}
