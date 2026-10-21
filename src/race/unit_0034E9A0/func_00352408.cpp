typedef unsigned char u8;
#define F(p,o) (*(float *)((char *)(p)+(o)))
struct Info { u8 pad0; u8 count; u8 pad2[0x1a]; u8 mode[0x20]; signed char signs[8]; signed char kind[8]; };
extern "C" float func_00352218(float,float *) throw();
extern "C" Info *func_00359510(void *);
extern "C" float func_00359830(void *,float);
extern "C" u8 *func_00360F80(void *,int,int);
extern "C" float func_0036CC40(float,float);
extern "C" int func_003F7C80();
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
extern float D_00620764, D_00620768;
extern u8 D_00623E52;
inline bool positive(Info *info,int i) { if(i >= info->count) return false; return info->signs[(unsigned long)i]>0; }
extern "C" void func_00352408(u8 *self) {
 int i=0;
 u8 *s=self+0x104;
 int count=0;
 float total=0;
 u8 *data=*(u8 **)(self+0x10);
 Info *info=func_00359510(data);
 if(info->count) {
  do {
   u8 *w=self+0x164+i*0xec;
   float *forces=(float *)(self+0x534+i*4);
   u8 *item=func_00360F80(data,i,w[0x89]);
   F(w,0x34)=0;
   if(F(w,0x60)==0) { F(w,0x68)=0; F(w,0x6c)=0; }
   else {
    float speed=F(w,0x28);
    float angle=F(w,0x30);
    float old=F(w,0);
    if(func_003F7C80()==1) F(w,0)=F(w,0)+F(w,0x1c);
    else if(func_003F7C80()==2) F(w,0)=F(w,0x1c);
    float a=F(w,0);
    if(speed<0) a+=0x1.921fb4p+1f;
    a = func_0036CC40(a,angle);
    F(w,0x34)=a;
    float sign;
    float force;
    if(item[0x1d9]) {
     float theta=F(w,0);
     float v=func_0057D1F0(theta)*F(w,0x2c);
     force=(v+func_0057D2B8(theta)*F(w,0x28))*F(data,0xfcc);
     sign=1;
     if(force<0) { force=-force; sign=-1; }
     if(item[0x1da]==0) { if(F(w,0x20)<0) sign=-sign; }
    } else {
     force=func_00352218(a,&sign);
     if(item[0x1da]==1) { if(F(w,0x20)<0) sign=-sign; }
    }
    if(positive(info,i)) { total+=force; count++; }
    float f=func_00359830(item+0x6c,force);
    F(w,0x5c)=f;
    float extra=0;
    float x=sign*f;
    if(info->kind[i]==2) {
     float delta=F(s,0x56c)-F(s,0x578);
     int mode=*(u8 *)(i+(unsigned)info+0x1c);
     float offset=F(w,4);
     if(mode==0) delta-=offset;
     else if((mode^1)==0) delta+=offset;
     else delta-=offset;
     delta/=D_00620764*0x1.1df468p-6f;
     if(delta>1) delta=1;
     else if(delta< -1) delta=-1;
     extra=delta*-D_00620768;
    }
    if(item[0x1d9]==0) { x*=F(w,0x60); extra*=F(w,0x60); }
    if(item[0x1da]==1) {
     float limit=F(w,0x58);
     if(x>limit) x=limit;
     else if(x< -limit) x=-limit;
     F(w,0x68)=x*F(w,0x4c);
     *forces=extra*F(w,0x4c);
     F(w,0x6c)=0;
    } else {
     float z=func_00359830(item+0xbc,force);
     if(item[0x1d9]==0) z*=F(w,0x60);
     float sum=x*x+z*z;
     float norm;
     __asm__("sqrt.s %0, %1":"=f"(norm):"f"(sum));
     float limit=F(w,0x58);
     if(limit<norm) { float ratio=limit/norm; x*=ratio; z*=ratio; }
     F(w,0x68)=x*F(w,0x4c);
     *forces=extra*F(w,0x4c);
     F(w,0x6c)=z*F(w,0x4c);
    }
    F(w,0)=old;
   }
   i++;
  } while((unsigned)i<info->count);
 }
 if(D_00623E52) { if(count>=2) total/=count; F(s,0x46c)=total; }
}
