/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { float x,y,z; float &X() {return x;} float &Y() {return y;} float &Z() {return z;} };
struct EulerAngles { float heading, pitch, roll; };
struct Obj { char pad[8]; float dist,range; char pad10[0x18]; V trans; EulerAngles angles; char pad40[0x140]; void *rng; void *scene; };
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
float fabsf(float);
}
static inline float sqr(float x) { float r; asm("sqrt.s %0,%1":"=f"(r):"f"(x)); return r; }
static inline void set(V *p,float x,float y,float z) {p->X()=x;p->Y()=y;p->Z()=z;}
static inline void copy(V *out,V *in) {func_005F5040(&in->X(),&out->X());}
static inline void madd(V *out,V *a,float *b,float scale) {out->X()=a->X()+b[0]*scale;out->Y()=a->Y()+b[1]*scale;out->Z()=a->Z()+b[2]*scale;}
extern "C" int func_00382708(Obj *self, void *car) {
 V pos; EulerAngles rot; V origin;
 float dir[4];
 V tmp;
 char cb[16];
 V delta,start,hit;
 int id;
 V side;
 int ok=0;
 V *pt=&tmp;
 void *rng=self->rng;
 float x=func_00344798(car,0.0f);
 float y=func_003447F8(car,0.0f);
 float z=func_00344828(car,0.0f);
 set(&origin,x,y,z);
 copy((V*)dir,&origin);
 float tx=func_00344720(car); float ty=func_00344748(car); float tz=func_00344770(car);
 set(pt,tx,ty,tz);
 func_005F5268(dir,pt);
 float sign=1.0f;
 float range=func_00578598(rng)*30.0f+50.0f;
 char *pcb=cb;
 float length=func_003F3708(car); length+=func_003F3720(car);
 float width=func_003F3738(car);
 func_003FCE70(pcb); *(int *)cb=3;
 pos.X()=width*(func_00578598(rng)*1.5f+0.7f);
 pos.Y()=origin.Y()+3.0f;
 float *pz=&pos.Z();
 *pz=length*func_00578598(rng);
 if(func_00578598(rng)<0.5f) pos.X()=-pos.X();
 if(func_00578598(rng)<0.5f) *pz=-*pz;
 func_003FCEA8(pcb,&pos,car,0.0f);
 void *scene=self->scene;
 id=*(int *)((char *)car+0x5ac);
 V *ps=&start, *ph=&hit;
 x=func_00344798(car,0.0f); y=func_003447F8(car,0.0f); z=func_00344828(car,0.0f);
 set(ps,x,y,z);
 func_003FE7B0(scene,ps,&pos,ph,&id,0x1.333332p-2f);
 id=-1;
 float ground=func_003FE358(scene,ph,&id);
 if(id>=0) {
  ok=1;
  float *hy=&hit.Y();
  float height=ground+0x1.999998p-4f;
  *hy=height+func_00578598(rng)*0x1.333332p-1f;
  func_005F5040(ph,&pos);
 }
 if(fabsf(func_003447F8(car,0.0f)-pos.Y())>5.0f) ok=0;
 float scale=(2.0f*func_00578598(rng)+1.0f)*60.0f;
 V *pd=&delta, *pv=&side;
 madd((V*)pcb,&origin,dir,scale);
 func_005F5040(pcb,pd);
 func_005F5268(pd,&pos);
 func_005F5040(&origin.X(),pv);
 func_005F5268(pv,&pos);
 float dist=sqr(func_005F5010(pd));
 if(side.Z()*pd->X()-pv->X()*delta.Z()<0.0f) sign=-1.0f;
 float *ry=&rot.pitch;
 *ry=func_00578598(rng)*20.0f-15.0f;
 rot.heading=func_0036EA98(pd)+range*sign*0.5f;
 float *rz=&rot.roll;
 *rz=func_00578598(rng)*30.0f-15.0f;
 self->dist=dist;
 self->range=range;
 func_005F5040(&pos,(char*)self+0x190);
 float nx=-pos.X(),ny=-pos.Y(),nz=-*pz;
 self->angles.heading=rot.heading; self->angles.pitch=*ry; self->angles.roll=*rz;
 self->trans.X()=nx; self->trans.Y()=ny; self->trans.Z()=nz;
 func_004A0690();func_004A53F8();func_004A7454();
 func_004A79D8(*rz);func_004A7988(*ry);func_004A79B0(rot.heading);
 func_004A7844(-pos.X(),-pos.Y(),-*pz);
 func_004A7550((char*)self+0x100);func_004A5400();func_004A06F0();
 return ok;
}
