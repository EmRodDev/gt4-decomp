/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Advances two coupled spring-damper axes (inferred from the stiffness/damping constants and the static helpers
 * spring/friction/fix): the primary axis is driven by an input force and clamped to [0, limit]; the secondary axis
 * is a tilt held to +-0.2618 rad (15 degrees). The input force is first limited to dt*4000 per call, and the excess
 * is carried over in a stored remainder capped at +-2000 (via func_00386358); the function returns 1 when the limit
 * was hit. The "motorist dynamic parameter" calls add offsets to the goal and the limit. The two axes' game meaning is
 * purpose unknown. min.s/max.s are inline asm helpers because the original used those instructions. */
struct W { int a0; int pad4; int a8; char pad[0xfc]; float force; int pad10c; float dt; };
extern "C" float *func_00385AE8(int);
extern "C" float *func_00385B08(int);
extern "C" float *func_003861C8(int);
extern "C" float *func_003861E8(int);
extern "C" float *func_00386358(int);
extern "C" void *DRIVERSUPPORT_NAME__GetMotoristDynamicParameter();
extern "C" float func_0044F8B0(void *);
extern "C" float func_0044F8C0(void *);
struct St { float acc; float *vel; float *pos; };
static inline float minimum(float a,float b) { float r; asm("min.s %0,%1,%2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline float maximum(float a,float b) { float r; asm("max.s %0,%1,%2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline void friction(St *s,float f) { float a=s->acc; if(a*a<f*f) s->acc=0.0f; else s->acc=a>0.0f?a-f:a+f; }
static inline void advance(St *s,float dt) { *s->pos+=*s->vel*dt; s->acc=0.0f; }
static inline void spring(St *s,float target,float dt,float k,float d,float vmax) {
 s->acc += (target-*s->pos)*k;
 s->acc -= *s->vel*d;
 *s->vel += s->acc*dt;
 float v=*s->vel;
 if(v*v>vmax*vmax) { if(v>0.0f) *s->vel=vmax; else *s->vel=-vmax; }
 advance(s,dt);
}
static inline void fix(St *s,float p) { s->acc=0.0f; *s->vel=0.0f; *s->pos=p; }
extern "C" int func_004043C8(W *w,float limit,float target) {
 int result=0;
 float zero=0.0f, damping=20.0f, stiffness=0x1.67fffep+6f;
 St primary,secondary;
 float *velocityRef=func_003861E8(w->a8); float *positionRef=func_00385B08(w->a0);
 primary.vel=velocityRef; primary.pos=positionRef; primary.acc=zero;
 St *secondaryRef=&secondary;
 velocityRef=func_003861C8(w->a8); positionRef=func_00385AE8(w->a0);
 secondaryRef->acc=zero; secondary.vel=velocityRef; secondary.pos=positionRef;
 func_00385B08(w->a0);
 float force=w->force; float maxForce=w->dt*4000.0f;
 float goal=target+func_0044F8C0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
 float carryCap=2000.0f;
 float forceWithCarry=force+*func_00386358(w->a8);
 if(maxForce<forceWithCarry) {
  result=1; *func_00386358(w->a8)=forceWithCarry-maxForce; force=maxForce;
  float *carryRef=func_00386358(w->a8); *carryRef=minimum(carryCap,*func_00386358(w->a8));
 } else if(forceWithCarry < -maxForce) {
  force=-maxForce; result=1; *func_00386358(w->a8)=forceWithCarry+maxForce;
  float *carryRef=func_00386358(w->a8); *carryRef=maximum(-carryCap,*func_00386358(w->a8));
 } else { force=forceWithCarry; *func_00386358(w->a8)=zero; }
 limit+=func_0044F8B0(DRIVERSUPPORT_NAME__GetMotoristDynamicParameter());
 primary.acc+=force; friction(&primary,3.0f); spring(&primary,goal,w->dt,stiffness,damping,0x1.f6a7ap+4f);
 if(limit<*primary.pos) fix(&primary,limit); else if(*primary.pos<0.0f) fix(&primary,0.0f);
 if(limit*0.25f<=*primary.pos || *primary.pos==0.0f) secondaryRef->acc+=force;
 friction(secondaryRef,3.0f); spring(&secondary,0.0f,w->dt,stiffness,damping,0x1.f6a7ap+4f);
 float tiltMin=-0.26179934f, tiltMax=0.26179934f;
 if(*secondary.pos>tiltMax) fix(&secondary,tiltMax); else if(*secondary.pos<tiltMin) fix(&secondary,tiltMin);
 return result;
}
