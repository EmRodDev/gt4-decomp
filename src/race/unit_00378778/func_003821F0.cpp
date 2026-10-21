struct V { float x,y,z; float &X() { return x; } float &Y() { return y; } float &Z() { return z; } };
struct Obj { char pad[8]; float dist,range; char pad10[0x18]; V trans, angles; char pad40[0x140]; void *rng; void *scene; };
extern "C" {
float func_00344720(void *);
float func_00344748(void *);
float func_00344770(void *);
float func_00344798(void *,float);
float func_003447F8(void *,float);
float func_00344828(void *,float);
float func_0036EA98(void *) throw();
float func_003F3708(void *);
float func_003F3720(void *);
float func_003F3738(void *);
void func_003FCE70(void *);
void func_003FCEA8(void *,void *,void *,float);
float func_003FE358(void *,void *,int *);
int func_003FE7B0(void *,void *,void *,void *,int *,float);
void func_004A0690();
void func_004A06F0();
void func_004A53F8();
void func_004A5400();
void func_004A7454();
void func_004A7550(void *);
void func_004A7844(float,float,float);
void func_004A7988(float);
void func_004A79B0(float);
void func_004A79D8(float);
float func_00578598(void *);
float func_005F5010(void *);
void func_005F5040(void *,void *);
void func_005F5268(void *,void *);
}
static inline float absf(float x) { float r; asm("abs.s %0,%1":"=f"(r):"f"(x)); return r; }
static inline float sqr(float x) { float r; asm("sqrt.s %0,%1":"=f"(r):"f"(x)); return r; }
static inline void set(V *p,float x,float y,float z) {p->x=x;p->y=y;p->z=z;}
static inline float *data(V *v) {return &v->x;}
extern "C" void *func_005A48D8(void *,int,unsigned);
static inline void clear(V *v) {func_005A48D8(v,0,sizeof(V));}
static inline void copy(V *out,V *in) {func_005F5040(&in->x,&out->x);}
extern "C" float func_003447C8(void *,float);
extern "C" int func_0034C518(void *,unsigned,int,void *,float);
extern "C" float func_0036EB98(float,float) throw();
extern "C" int func_003FCB20(void *,void *);
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" void func_005F5230(void *,void *);
static inline int negative(int n) { if(n<0) return 1; return 0; }
extern "C" int func_003821F0(Obj *self,void *car,void *track,float t) {
 V pos,rot,origin,dir,tmp,a,b,off,start,hit;
 int id;
 V *pd=&dir,*pv=&tmp;
 V *pr=&rot;
 void *rng=self->rng;
 clear(&pos);
 clear(&rot);
 float factor=t*(func_00578598(rng)*0.35f+0.5f);
 float x=func_00344798(car,0.0f);
 float y=func_003447F8(car,0.0f);
 float z=func_00344828(car,0.0f);
 origin.x=x;origin.y=y;origin.z=z;
 copy(pd,&origin);
 float tx=func_00344720(car);
 float ty=func_00344748(car);
 float tz=func_00344770(car);
 pv->X()=tx; pv->Y()=ty;pv->Z()=tz;
 func_005F5268(pd,pv);
 float base=func_003447C8(car,0.0f);
 float speed=base-func_003447C8(car,1.0f);
 float rr=func_00578598(rng);
 float advance=speed*factor*60.0f;
 float range=rr*30.0f+50.0f;
 float u=base+advance;
 float prev=u-1.0f;
 clear(pv);
 int bad=negative(func_0034C518(track,6,0,&a,u));
 int ok=!bad;
 if(func_0034C518(track,6,0,&b,prev)<0)ok=false;
 float dist=100.0f;
 float *ry,*rz;
 if(ok) {
  V *po=&off;
  float dx=b.x-a.x,dy=b.y-a.y,dz=b.z-a.z;
  pv->X()=dx;pv->Y()=dy;pv->Z()=dz;
  float angle=func_0036EA98(pv);
  dist=sqr(func_005F5010(pv));
  float shift=func_00578598(rng)*5.0f+2.0f;
  if(func_00578598(rng)<0.5f)shift=-shift;
  set(&pos,a.x,a.y,a.z);
  float sx=-func_0057D2B8(angle);
  float sz=func_0057D1F0(angle)*shift;
  set(po,sx*shift,0.0f,sz);
  func_005F5230(&pos,po);
  void *scene=self->scene;
  V *ps=&start,*ph=&hit;
  set(ps,a.x,a.y,a.z);
  id=func_003FCB20(scene,ps);
  if(id<0) ok=false;
  else {
   func_003FE7B0(scene,ps,&pos,ph,&id,1.2f);
   id=-1;
   float ground=func_003FE358(scene,ph,&id);
   if(id<0) ok=false;
   else {
    float *hy=&hit.Y();
    float h=ground+0x1.999998p-4f;
    *hy=h+func_00578598(rng)*0x1.333332p-1f;
    func_005F5040(ph,&pos);
   }
  }
  ry=&rot.y;
  *ry=func_00578598(rng)*20.0f-15.0f;
  pr->x=angle+func_00578598(rng)*20.0f-10.0f;
  rz=&rot.z;
  *rz=func_00578598(rng)*30.0f-15.0f;
 }
 else {ry=&rot.y;rz=&rot.z;}
 copy(pv,&origin);
 func_005F5268(pv,&pos);
 float diff=absf(func_0036EB98(func_0036EA98(pv),pr->x));
 if(diff>range*0.5f)ok=false;
 self->dist=dist;self->range=range;
 func_005F5040(&pos,(char*)self+0x190);
 func_004A0690();func_004A53F8();func_004A7454();
 func_004A79D8(*rz);func_004A7988(*ry);func_004A79B0(pr->x);
 func_004A7844(-pos.x,-pos.y,-pos.z);
 func_004A7550((char*)self+0x100);func_004A5400();func_004A06F0();
 return ok;
}
