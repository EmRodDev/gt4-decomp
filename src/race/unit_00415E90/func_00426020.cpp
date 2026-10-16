/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Row { float *p; Row(float *q):p(q){} Row(const Row&r):p(r.p){} float &operator[](int n){return p[n*4];} };
struct Row3 { float *p; Row3(float *q):p(q){} Row3(const Row3&r):p(r.p){} float &operator[](int n){return p[n*3];} };
struct Mat3 { union {u128 q[3]; float v[12];}; Mat3(){} Mat3(const Mat3 &r){q[0]=r.q[0];q[1]=r.q[1];q[2]=r.q[2];} Mat3 &operator=(const Mat3&r){q[0]=r.q[0];q[1]=r.q[1];q[2]=r.q[2];return *this;} Row3 operator[](int n){return Row3(v+n);} };
struct Mat { float v[16]; Row operator[](int n){return Row(v+n);} };
struct Vec3 {float x,y,z;};
extern "C" Mat3 func_00486B38(Mat3 *);
extern "C" void func_00425F50(Mat *,Vec3 *) throw();
static inline void convert(Mat *out,Mat3 &m,float zero,float one){
 (*out)[0][0]=m[0][0]; (*out)[0][1]=m[0][1]; (*out)[0][2]=m[0][2]; out->v[12]=zero;
 (*out)[1][0]=m[1][0]; (*out)[1][1]=m[1][1]; (*out)[1][2]=m[1][2]; out->v[13]=zero;
 (*out)[2][0]=m[2][0]; (*out)[2][1]=m[2][1]; (*out)[2][2]=m[2][2]; out->v[14]=zero;
 (*out)[3][0]=zero;(*out)[3][1]=zero;(*out)[3][2]=zero;(*out)[3][3]=one;
}
extern "C" void func_00426020(Mat *out,Vec3 *pos,Mat3 *rot){
 Mat3 m; m=func_00486B38(rot);
 convert(out,m,0.0f,1.0f);
 func_00425F50(out,pos);
}
