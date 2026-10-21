/* compiler: ee-gcc2.96-g */
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned int u32;
struct Field { char pad[12]; u32 type; int other; int mode; float threshold; };
#define SQR(x) ((x)*(x))
extern "C" int func_00517CE0(Field *f, void *a, void *b) {
 if (!f) return 0;
 if (!a) return 0;
 if (!b) return 0;
 switch(f->type) {
 case 0: {
  s8 x=*(s8 *)a, y=*(s8 *)b;
  s8 d=x-y<0?y-x:x-y;
  if(f->mode==1) return d!=0;
  return d>(s8)f->threshold;
 }
 case 1: {
  u8 x=*(u8 *)a, y=*(u8 *)b;
  u8 d=x-y<0?y-x:x-y;
  if(f->mode==1) return d!=0;
  return d>(u8)f->threshold;
 }
 case 2: {
  s16 x=*(s16 *)a, y=*(s16 *)b;
  s16 d=x-y<0?y-x:x-y;
  if(f->mode==1) return d!=0;
  return d>(s16)f->threshold;
 }
 case 3: {
  u16 x=*(u16 *)a, y=*(u16 *)b;
  s16 t=x-y;
  u16 d=t<0?-t:t;
  if(f->mode==1) return d!=0;
  return d>(u16)f->threshold;
 }
 case 4: {
  int x=*(int *)a, y=*(int *)b;
  int d=x-y<0?y-x:x-y;
  if(f->mode==1) return d!=0;
  return d>(int)f->threshold;
 }
 case 5: {
  int x=*(u32 *)a, y=*(u32 *)b;
  u32 d=x-y<0?y-x:x-y;
  if(f->mode==1) return d!=0;
  return d>(u32)f->threshold;
 }
 case 6: {
  float d=*(float *)a-*(float *)b;
  if(d<0.0f) d=-d;
  if(f->mode==1) return d!=0.0f;
  return d>f->threshold;
 }
 case 7: {
  double d=*(double *)a-*(double *)b;
  if(d<0.0) d=0.0-d;
  if(f->mode==1) return d!=0.0;
  return d>(double)f->threshold;
 }
 case 8: {
  s16 *x=(s16 *)a,*y=(s16 *)b;
  return !(SQR(x[0]-y[0])+SQR(x[1]-y[1])<=SQR(f->threshold));
 }
 case 9: {
  s16 *x=(s16 *)a,*y=(s16 *)b;
  return !(SQR(x[0]-y[0])+SQR(x[1]-y[1])+SQR(x[2]-y[2])<=SQR(f->threshold));
 }
 case 10: {
  int *x=(int *)a,*y=(int *)b;
  return !(SQR(x[0]-y[0])+SQR(x[1]-y[1])<=SQR(f->threshold));
 }
 case 11: {
  int *x=(int *)a,*y=(int *)b;
  return !(SQR(x[0]-y[0])+SQR(x[1]-y[1])+SQR(x[2]-y[2])<=SQR(f->threshold));
 }
 case 12: {
  float *x=(float *)a,*y=(float *)b;
  return !(SQR(x[0]-y[0])+SQR(x[1]-y[1])<=SQR(f->threshold));
 }
 case 13: {
  float *x=(float *)a,*y=(float *)b;
  return !(SQR(x[0]-y[0])+SQR(x[1]-y[1])+SQR(x[2]-y[2])<=SQR(f->threshold));
 }
 case 14: {
  double *x=(double *)a,*y=(double *)b;
  return !(SQR(x[0]-y[0])+SQR(x[1]-y[1])<=SQR(f->threshold));
 }
 case 15: {
  double *x=(double *)a,*y=(double *)b;
  return !(SQR(x[0]-y[0])+SQR(x[1]-y[1])+SQR(x[2]-y[2])<=SQR(f->threshold));
 }
 default: return 0;
 }
}
