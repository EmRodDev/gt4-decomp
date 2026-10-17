/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct State { float pos[2]; char p8[0x438]; u8 idx; char p441[0x1b]; float steerSin; char p460[8]; float steer; char p46c[0x1c]; float throttle, brake, u490, throttle2; char p498[0x7c]; float flag; char p518[10]; u8 flag2; char p523[0x21]; float vel[2]; char p54c[4]; float accel[2]; char p558[12]; float force; char p568[8]; float angle; char p574[8]; float angular; char p580[8]; float other; };
struct Car { char p0[16]; char *info; char p14[0xf0]; State state; };
struct Input { int t; u8 flags, throttle; signed char steer; char p7; float pos[2], angle, vel[2], angular, accel[2], other; short a[2]; };
struct Wheels { u8 u, count; char p2[6]; u8 divisors[0x24]; u8 map[1]; };
extern "C" u8 D_00845938[], D_00621FF8[];
extern "C" float D_00845940[],D_00845958[],D_00845954,D_0084596C;
extern "C" float func_00348800(float);
extern "C" Wheels *func_00359510(void *);
extern "C" void func_0036BEB8(void *,int);
extern "C" float func_0036CC40(float,float);
extern "C" int func_003F7EA8(void *);
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
static inline void approach(State *s,float target,float step) {
 if(s->steer<target) {s->steer+=step; if(target<s->steer)s->steer=target;}
 else if(target<s->steer) {s->steer-=step; if(s->steer<target)s->steer=target;}
}
extern "C" void func_003F05E0(Car *car, Input *in) {
 int i;
 State *s=&car->state;
 int fresh=D_00845938[s->idx]==0;
 D_00845938[s->idx]=1;
 if(in->flags&8) s->brake=1.0f; else s->brake=0.0f;
 if(in->flags&16) {s->flag2=1; s->flag=1.0f;} else {s->flag2=0;s->flag=0.0f;}
 func_0036BEB8(car,in->flags&7);
 float throttle=in->throttle*0.015625f;
 s->throttle2=throttle; s->throttle=throttle;
 float target=in->steer*0x1.1df468p-7f;
 approach(s,target,0x1.acee9ap-6f);
 s->steerSin=func_00348800(s->steer);
 func_003F7EA8(car);
 if(D_00621FF8[1]>=2 && !fresh) {
 float d=func_0036CC40(in->angle,s->angle);
 s->angular+=(D_00845954*d-D_0084596C*s->angular)*0x1.111110p-6f;
 s->angle+=s->angular*0x1.111110p-6f;
 } else {s->angle=in->angle;s->angular=in->angular;}
 if(D_00621FF8[1]>=2 && !fresh) {
 float sn=func_0057D2B8(s->angle),cs=func_0057D1F0(s->angle);
 float dx=in->pos[0]-s->pos[0],dy=in->pos[1]-s->pos[1];
 float vx=s->vel[0],vy=s->vel[1];
 float ns=-sn;
 float forward=cs*dx+sn*dy, side=ns*dx+cs*dy;
 float vf=cs*vx+sn*vy, vs=ns*vx+cs*vy;
 vf+=(D_00845940[4]*forward-D_00845958[4]*vf)*0x1.111110p-6f;
 if(D_00621FF8[1]==2) vs+=(D_00845940[3]*side-D_00845958[3]*vs)*0x1.111110p-6f;
 else vs=side/0x1.111110p-6f;
 float newx=ns*vs+cs*vf;
 float newy=cs*vs+sn*vf;
 s->vel[1]=newy; s->vel[0]=newx;
 for(i=0;i<2;i++) s->pos[i]+=s->vel[i]*0x1.111110p-6f;
 } else {for(i=0;i<2;i++){s->pos[i]=in->pos[i];s->vel[i]=in->vel[i];}}
 s->accel[0]=in->accel[0];s->accel[1]=in->accel[1];
 s->force=in->accel[0]* *(float *)(car->info+0x48);
 s->other=in->other;
 Wheels *w=func_00359510(car->info);
 float a[2]; a[0]=in->a[0]*0x1.399998p+3f;a[1]=in->a[1]*0x1.399998p+3f;
 for(i=0;i<w->count;i++) {char *wheel=(char *)car+0x164+i*0xec; int idx=w->map[i]; *(float *)(wheel+0x70)=a[idx]/w->divisors[idx];*(float *)(wheel+0x74)=0;}
}
