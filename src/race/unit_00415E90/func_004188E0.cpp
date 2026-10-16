/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct Mat;
struct V {
 float x,y,z,w;
 V() {}
 V(float a,float b,float c,float d):x(a),y(b),z(c),w(d) {}
 V(const V&o) { *(u128*)this=*(const u128*)&o; }
 void make(Mat *);
} __attribute__((aligned(16)));
struct Row {float *p; Row(float*q):p(q){} Row(const Row&r):p(r.p){} float&operator[](int n){return p[n*4];}};
struct Mat {
 float v[16];
 Mat() {}
 Mat(const Mat&o) { ((u128*)this)[0]=((const u128*)&o)[0];((u128*)this)[1]=((const u128*)&o)[1];((u128*)this)[2]=((const u128*)&o)[2];((u128*)this)[3]=((const u128*)&o)[3]; }
 Row operator[](int n){return Row(v+n);}
} __attribute__((aligned(16)));
struct Obj { V pos,q; };
extern "C" void func_00421D30(V*, Mat*, float,float,float);
inline void V::make(Mat *m) { func_00421D30(this,m,0.0f,0.0f,0.0f); }
static inline V conjugate(float x,float y,float z,float w) { V r(-x,-y,-z,w); return r; }
extern "C" Mat func_004188E0(Obj *o) {
 Mat m;
 conjugate(o->q.x,o->q.y,o->q.z,o->q.w).make(&m);
 m[0][3]=-m[0][0]*o->pos.x-m[0][1]*o->pos.y-m[0][2]*o->pos.z;
 m[1][3]=-m[1][0]*o->pos.x-m[1][1]*o->pos.y-m[1][2]*o->pos.z;
 m[2][3]=-m[2][0]*o->pos.x-m[2][1]*o->pos.y-m[2][2]*o->pos.z;
 return m;
}
