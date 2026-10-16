/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct __attribute__((aligned(16))) Vec {
 union { u128 bits; struct {float x,y,z,w;}; };
 Vec() {} Vec(const Vec &v) {bits=v.bits;} Vec(float a,float b,float c) { x=a;y=b;z=c; }
 void multiply(float f) {x*=f;y*=f;z*=f;}
 Vec operator*(float f) const { Vec v(*this); v.multiply(f); return v; }
 Vec &operator=(const Vec &v) {bits=v.bits;return *this;}
};
extern Vec D_00622B10;
extern "C" void func_00423AA0(Vec*,Vec*,Vec*,Vec*);
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
extern "C" int func_00415828(float *outx,float *outy,float ax,float ay,float az,float bx,float by,float bz,float cx,float cy,float cz) {
 Vec delta(cx-ax,cy-ay,cz-az);
 Vec direction(bx,by,bz);
 int result=0;
 float squared=delta.x*delta.x+delta.y*delta.y+delta.z*delta.z;
 if(squared<0.0001f) return result;
 {
  float length; asm("sqrt.s %0, %1":"=f"(length):"f"(squared));
  delta=delta*(1.0f/length);
  Vec angles; float &anglevalue=angles.x;
  func_00423AA0(&angles,&delta,&D_00622B10,&direction);
  Vec angle; float &value=angle.x;
  value=anglevalue;
  *outx=length*func_0057D2B8(value);
  value=anglevalue;
  *outy=length*func_0057D1F0(value);
  return 1;
 }
 return result;
}
