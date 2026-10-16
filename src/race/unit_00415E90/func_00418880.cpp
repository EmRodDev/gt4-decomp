/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int U128 __attribute__((mode(TI)));
struct Matrix {U128 a,b,c,d;};
struct Obj {float x,y,z,pad;U128 q;};
extern "C" void func_00421D30(const U128 *, Matrix *, float,float,float);
extern "C" Matrix *func_00418880(Matrix *out,const Obj *o) {
 Matrix tmp;
 func_00421D30(&o->q,&tmp,o->x,o->y,o->z);
 out->a=tmp.a;
 out->b=tmp.b;
 out->c=tmp.c;
 out->d=tmp.d;
 return out;
}
