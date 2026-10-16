/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct V {float x,y,z,w; V(){} V(float a,float b,float c):x(a),y(b),z(c){} V(const V &v){*(u128*)this=*(const u128*)&v;} V &operator=(const V &v){*(u128*)this=*(const u128*)&v;return *this;} } __attribute__((aligned(16)));
struct Q:V { Q(){} Q(float a,float b,float c,float d){x=a;y=b;z=c;w=d;} Q operator=(const Q &v){*(u128*)this=*(const u128*)&v;return *this;} };
struct Scalar { float v; Scalar(float f):v(f){} } __attribute__((aligned(16)));
static inline float scalar(const Scalar &s) {return s.v;}
struct Car {char p[0x54c];float dt;char p2[0x648-0x550];float pos[3];};
struct Entry {short delta,index;float (*fn)(void*,float);};
struct Virt {Entry *vt;};
struct Self {int a,b;void *c,*d,*e;Virt *f;Car *car;int pad;Q q,inv;V v40,v50,v60,v70,v80,v90,a0,b0,c0,d0,e0,f0,v100;float dt,idt,avg;int flag,ready;};
extern "C" float func_00344858(Car*,float);
extern "C" float func_003448B8(Car*,float);
extern "C" float func_00344888(Car*,float);
extern "C" float func_00344798(Car*,float);
extern "C" float func_003447F8(Car*,float);
extern "C" float func_00344828(Car*,float);
extern "C" float func_00344DA8(Car*,int,float);
extern "C" int func_00343B30(Car*);
extern "C" int func_00385F20(void*);
extern "C" float func_00386160(void*);
extern "C" float func_00386170(void*);
extern "C" float func_00386180(void*);
extern "C" float func_00386190(void*);
extern "C" float func_003861A0(void*);
extern "C" float func_003861B0(void*);
extern "C" V Numerical_Math__Quaternion__rotate(Q*,const V&);
extern "C" void func_00488528(Q*,float,float,float);
extern V D_00622B50,D_00622B20,D_00622B00,D_00622B30,D_00622B10,D_00622B40;
static inline float virt(Virt*p,int n){Entry*e=p->vt+n;return e->fn((char*)p+e->delta,0.0f);}
static inline void angles(Q*q,const float &x,const float &y,const float &z){func_00488528(q,x,y,z);}
static inline Q conjugate(Q*q){return Q(-q->x,-q->y,-q->z,q->w);}
extern "C" void func_0040D0A0(Self*s,Car*car,int a,int b,void*c,void*d,void*e,Virt*f,int flag){
s->flag=flag;s->a=a;s->b=b;s->c=c;s->d=d;s->e=e;s->f=f;s->car=car;
V *a0,*c0,*e0; Q *q,*inv; V *v40,*v50,*v60,*v70,*v80,*v90;
q=&s->q; inv=&s->inv;
v40=&s->v40;v50=&s->v50;v60=&s->v60;v70=&s->v70;v80=&s->v80;v90=&s->v90;e0=&s->e0;
{
const Scalar &ax=Scalar(func_00344858(car,0.0f));
const Scalar &ay=Scalar(func_003448B8(car,0.0f));
const Scalar &az=Scalar(-func_00344888(car,0.0f));
func_00488528(q,scalar(ax),scalar(ay),scalar(az));
*inv=Q(-s->q.x,-s->q.y,-s->q.z,s->q.w);
}
a0=&s->a0; V *b0=&s->b0; c0=&s->c0;
float *bx=&b0->x,*by=&b0->y,*bz=&b0->z;
s->dt=car->dt;s->idt=1.0f/s->dt;
*v40=Numerical_Math__Quaternion__rotate(q,D_00622B50);*v50=Numerical_Math__Quaternion__rotate(q,D_00622B20);*v60=Numerical_Math__Quaternion__rotate(q,D_00622B00);*v70=Numerical_Math__Quaternion__rotate(q,D_00622B30);*v80=Numerical_Math__Quaternion__rotate(q,D_00622B10);*v90=Numerical_Math__Quaternion__rotate(q,D_00622B40);
s->e0.x=virt(f,2);s->e0.y=virt(f,3);s->e0.z=virt(f,4);
*b0=*a0=Numerical_Math__Quaternion__rotate(q,*e0);
*bx+=func_00344798(car,0.0f);*by+=func_003447F8(car,0.0f);*bz+=func_00344828(car,0.0f);
V v;
float *cx,*cy,*cz;
if(func_00385F20(d)==1){cx=&s->c0.x;cy=&s->c0.y;cz=&s->c0.z;float *p=car->pos; v.x=p[0];v.y=p[2];v.z=-p[1];float x=v.x,y=v.y,z=v.z;*cx=x;*cy=y;*cz=z;}
else {cx=&s->c0.x;cy=&s->c0.y;cz=&s->c0.z;*cx=(*bx-func_00386160(c))*s->idt;*cy=(*by-func_00386170(c))*s->idt;*cz=(*bz-func_00386180(c))*s->idt;}
V *d0=&s->d0,*f0=&s->f0,*v100=&s->v100;
s->d0.x=(*cx-func_00386190(c))*s->idt;s->d0.y=(*cy-func_003861A0(c))*s->idt;s->d0.z=(*cz-func_003861B0(c))*s->idt;
*f0=Numerical_Math__Quaternion__rotate(inv,*c0);*v100=Numerical_Math__Quaternion__rotate(inv,*d0);
float k=func_00344DA8(s->car,0,0.0f);k+=func_00344DA8(s->car,1,0.0f);s->avg=k*0.5f;s->ready=func_00343B30(s->car)!=0;
}
