/* Per-wheel force step: for each wheel the car has (count from func_00359510, stride 0xEC from self+0x164) it works out
 * a steering/slip angle (func_0036CC40 on the wheel angle at +0, optionally advanced by +0x1C depending on
 * func_003F7C80), a force magnitude from sin/cos of that angle and the wheel velocities (+0x28, +0x2C) or from
 * func_00352218, looks the force up in two curves (item+0x6C and item+0xBC, func_00359830) and limits the vector
 * (x, z) to the radius at +0x58 using an inline sqrt.s. Outputs: +0x68 and +0x6C (two components), +0x5C (curve value)
 * and one entry of the force array at self+0x534. The sum over wheels flagged positive in the info record is averaged
 * and stored at dyn+0x46C when D_00623E52 is set. The wheel angle is restored at the end. Which physical forces these
 * are (tyre lateral/longitudinal, inferred from the shape only) is purpose unknown. */
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
 u8 *dyn=self+0x104;
 int positiveCount=0;
 float positiveTotal=0;
 u8 *engineData=*(u8 **)(self+0x10);
 Info *info=func_00359510(engineData);
 if(info->count) {
  do {
   u8 *wheel=self+0x164+i*0xec;
   float *forceSlot=(float *)(self+0x534+i*4);
   u8 *wheelItem=func_00360F80(engineData,i,wheel[0x89]);
   F(wheel,0x34)=0;
   if(F(wheel,0x60)==0) { F(wheel,0x68)=0; F(wheel,0x6c)=0; }
   else {
    float velA=F(wheel,0x28);
    float slipAngleInput=F(wheel,0x30);
    float savedAngle=F(wheel,0);
    if(func_003F7C80()==1) F(wheel,0)=F(wheel,0)+F(wheel,0x1c);
    else if(func_003F7C80()==2) F(wheel,0)=F(wheel,0x1c);
    float slipAngle=F(wheel,0);
    if(velA<0) slipAngle+=0x1.921fb4p+1f;
    slipAngle = func_0036CC40(slipAngle,slipAngleInput);
    F(wheel,0x34)=slipAngle;
    float forceSign;
    float forceMagnitude;
    if(wheelItem[0x1d9]) {
     float wheelAngle=F(wheel,0);
     float lateralPart=func_0057D1F0(wheelAngle)*F(wheel,0x2c);
     forceMagnitude=(lateralPart+func_0057D2B8(wheelAngle)*F(wheel,0x28))*F(engineData,0xfcc);
     forceSign=1;
     if(forceMagnitude<0) { forceMagnitude=-forceMagnitude; forceSign=-1; }
     if(wheelItem[0x1da]==0) { if(F(wheel,0x20)<0) forceSign=-forceSign; }
    } else {
     forceMagnitude=func_00352218(slipAngle,&forceSign);
     if(wheelItem[0x1da]==1) { if(F(wheel,0x20)<0) forceSign=-forceSign; }
    }
    if(positive(info,i)) { positiveTotal+=forceMagnitude; positiveCount++; }
    float curveValue=func_00359830(wheelItem+0x6c,forceMagnitude);
    F(wheel,0x5c)=curveValue;
    float extraForce=0;
    float outX=forceSign*curveValue;
    if(info->kind[i]==2) {
     float angleDelta=F(dyn,0x56c)-F(dyn,0x578);
     int deltaMode=*(u8 *)(i+(unsigned)info+0x1c);
     float angleOffset=F(wheel,4);
     if(deltaMode==0) angleDelta-=angleOffset;
     else if((deltaMode^1)==0) angleDelta+=angleOffset;
     else angleDelta-=angleOffset;
     angleDelta/=D_00620764*0x1.1df468p-6f;
     if(angleDelta>1) angleDelta=1;
     else if(angleDelta< -1) angleDelta=-1;
     extraForce=angleDelta*-D_00620768;
    }
    if(wheelItem[0x1d9]==0) { outX*=F(wheel,0x60); extraForce*=F(wheel,0x60); }
    if(wheelItem[0x1da]==1) {
     float radiusLimit=F(wheel,0x58);
     if(outX>radiusLimit) outX=radiusLimit;
     else if(outX< -radiusLimit) outX=-radiusLimit;
     F(wheel,0x68)=outX*F(wheel,0x4c);
     *forceSlot=extraForce*F(wheel,0x4c);
     F(wheel,0x6c)=0;
    } else {
     float outZ=func_00359830(wheelItem+0xbc,forceMagnitude);
     if(wheelItem[0x1d9]==0) outZ*=F(wheel,0x60);
     float radiusSquared=outX*outX+outZ*outZ;
     float radius;
     __asm__("sqrt.s %0, %1":"=f"(radius):"f"(radiusSquared));
     float radiusLimit=F(wheel,0x58);
     if(radiusLimit<radius) { float scaleFactor=radiusLimit/radius; outX*=scaleFactor; outZ*=scaleFactor; }
     F(wheel,0x68)=outX*F(wheel,0x4c);
     *forceSlot=extraForce*F(wheel,0x4c);
     F(wheel,0x6c)=outZ*F(wheel,0x4c);
    }
    F(wheel,0)=savedAngle;
   }
   i++;
  } while((unsigned)i<info->count);
 }
 if(D_00623E52) { if(positiveCount>=2) positiveTotal/=positiveCount; F(dyn,0x46c)=positiveTotal; }
}
