/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Fills a placement record for entry index of the table at context+0xDA50 (read through 0046BEC0): position with the y/z axes swapped
 * (x, z, -y; inferred as a change of up axis), the heading, a 2x3 transform built from sin/cos of the heading and the position, and its
 * inverse (translation = minus the rotated position), plus a target. The target is the point of pointSet nearest to the entry (squared distance
 * over x, y, z; its fourth value gets pi added, 0x1.921cacp+1) or, when the set is missing or empty, the entry itself. The stored state value
 * comes from 0046BEC0. What the placement is used for is purpose unknown. */
struct V3 { float x,y,z; };
struct Point { float x,y,z,a; };
struct O { char pad[8]; int i8; float x,y,z; int i18; float angle; int i20; Point target; char pad34[0xC]; float m40,m44,m48,m4c,m50,m54,m58,m5c,m60,m64,m68,m6c; };
struct Data { char pad[0x52]; unsigned short count; char pad54[0x3C]; Point *points; };
extern "C" void func_0046BEC0(void *,int,float *,float *,int *);
extern "C" void func_0057D8A0(float *,float *,float);
static inline Point *get(Data *d,int i) { Point *point=d->points; point+=i; return point; }
static inline void set2(float *a,float *b,float v0,float v1) { *a=v0; *b=v1; }
static inline int getcount(Data *d) { return d->count; }
static inline float read(float *point) { return *point; }
static inline void invert(O *out,float *a,float *b,float *c,float *d,float *e,float *f) {
 out->m58=read(a); out->m5c=read(d);
 out->m60=-read(a)*read(c)-read(d)*read(f);
 out->m64=read(b); out->m68=read(e);
 out->m6c=-read(b)*read(c)-read(e)*read(f);
}
extern "C" void func_003CB070(O *placement,int index,char *context,Data *pointSet) {
 int state;
 V3 positionVec,rotationVec;
 float sinCos[2];
 float *p40=&placement->m40;
 func_0046BEC0(context+0xDA50,index,&positionVec.x,&rotationVec.x,&state);
 placement->i18=0;
 placement->x=positionVec.x; placement->y=positionVec.z; placement->z=-positionVec.y;
 placement->angle=rotationVec.z; placement->i20=0;
 func_0057D8A0(&sinCos[0],&sinCos[1],rotationVec.z);
 float *p44=&placement->m44, *p4c=&placement->m4c, *p50=&placement->m50, *p54=&placement->m54, *p48=&placement->m48;
 *p40=sinCos[1]; *p44=sinCos[0]; *p4c=-sinCos[0]; *p50=sinCos[1];
 set2(p48,p54,placement->x,placement->z);
 invert(placement,p40,p44,p48,p4c,p50,p54);
 int foundTarget=0;
 if(pointSet) {
  
  int nearestIndex=0; float nearestDistSq=-1.0f;
  int i=0;
  if(pointSet->count!=0) {
  float ox=placement->x, oy=placement->y, oz=placement->z;
  Point *point=pointSet->points;
  do {
   float dx=point->x-ox;
   float dy=point->y-oy;
   float dz=point->z-oz;
   float d=dx*dx+dy*dy+dz*dz;
   point++;
   if(i==0 || d<nearestDistSq) { nearestDistSq=d; nearestIndex=i; }
   i++;
  } while(i<(int)pointSet->count);
  }
  if(nearestDistSq>=0.0f) {
   foundTarget=1;
   placement->target.x=get(pointSet,nearestIndex)->x;
   placement->target.y=get(pointSet,nearestIndex)->y;
   placement->target.z=get(pointSet,nearestIndex)->z;
   placement->target.a=get(pointSet,nearestIndex)->a+0x1.921cacp+1f;
  }
 }
 if(foundTarget==0) {
  placement->target.x=placement->x; placement->target.y=placement->y; placement->target.z=placement->z; placement->target.a=placement->angle;
 }
 placement->i8=state;
}
