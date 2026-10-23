/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Vec {
 union { u128 q; struct { float x, y, z, w; }; };
 Vec() {}
 Vec(float a, float b, float c) { x = a; y = b; z = c; }
 Vec(const Vec &v) { q = v.q; }
 Vec &operator=(const Vec &v) { q = v.q; return *this; }
 float &at(int i) { return (&x)[i]; }
 const float &at(int i) const { return (&x)[i]; }
 float &operator[](int i) { return at(i); }
 const float &operator[](int i) const { return at(i); }
 Vec &operator+=(const Vec &v) { (*this)[0] = (*this)[0] + v[0]; (*this)[1] = (*this)[1] + v[1]; (*this)[2] = (*this)[2] + v[2]; return *this; }
 Vec operator+(const Vec &v) const { Vec r(*this); r += v; return r; }
};
extern "C" void func_00419D80(void*,const Vec*) throw();
extern "C" void func_00419F80(void *self,float a,float b,float c,float d,float e,float f,float g,float h,float i,float j,float k,float l,float m,float n,float o,float p) {
 Vec v[26];
 v[0]=Vec(0,0,0);
 v[1]=v[0]+Vec(a*0.5f,p,0);
 v[5]=v[0]+Vec(-a*0.5f,p,0);
 v[2]=v[1]+Vec(0,-b,0);
 v[6]=v[5]+Vec(0,-b,0);
 v[3]=v[2]+Vec(0,-c,0);
 v[7]=v[6]+Vec(0,-c,0);
 v[4]=v[3]+Vec(0,0,d);
 v[8]=v[7]+Vec(0,0,d);
 v[9]=v[0]+Vec(0,e,0);
 v[10]=v[9]+Vec(0,f,0);
 v[11]=v[10]+Vec(0,g,0);
 v[12]=v[11]+Vec(0,h,0);
 v[13]=v[12]+Vec(l*0.02f,0,0);
 v[14]=v[12]+Vec(-l*0.02f,0,0);
 v[15]=v[12]+Vec(0,i,0);
 v[16]=v[15]+Vec(0,j,0);
 v[17]=v[16]+Vec(0,0,k);
 v[18]=v[13]+Vec(l*0.48f,0,0);
 v[22]=v[14]+Vec(-l*0.48f,0,0);
 v[19]=v[18]+Vec(m,0,0);
 v[23]=v[22]+Vec(-m,0,0);
 v[20]=v[19]+Vec(n,0,0);
 v[24]=v[23]+Vec(-n,0,0);
 v[21]=v[20]+Vec(o,0,0);
 v[25]=v[24]+Vec(-o,0,0);
 func_00419D80(self,v);
}
