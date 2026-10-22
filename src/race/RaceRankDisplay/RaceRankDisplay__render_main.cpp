/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { unsigned char p0,fx,fy,p3; short x,y,w,h; float alpha; void *tex; int p14,rank; float line,current,fade; };
struct Ctx { char p[0x38]; int half; };
struct Vec { float x,y,z,w; } __attribute__((aligned(16)));
struct Font { int p0,flags; };
extern Font D_00623838;
extern char D_006A1400[],D_006A1408[];
extern "C" {
void func_001056A0(void *);
void func_003A3EF0(void *);
void func_003AF108(void *,float,float,float,float,int,int);
float func_003AFD18(int,float,float);
unsigned int func_003AFEC8(unsigned int,float);
void func_0044D920(void *,void *);
void func_0044D988(void *);
void func_0044DDF8(void *,float,float,float);
void func_0044DE80(void *,unsigned int);
void func_0044E088(void *,const char *,...);
unsigned char func_0044E3F8(void *);
void func_0049E2D8(Vec *,Vec *);
void func_004A1638(int);
void func_004A2E68(int,int,int,int);
void func_004AA1D8(float,float,float,float);
void func_004AB040(int);
}
static inline float maxf(float a,float b) { float r; __asm__("max.s %0,%1,%2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline float minf(float a,float b) { float r; __asm__("min.s %0,%1,%2":"=f"(r):"f"(a),"f"(b)); return r; }
static inline void approach(Self *const s,float target,float delta) {
 if (delta>0.0f) { delta=maxf(delta,0.01f); s->current=minf(s->current+delta,target); }
 else if (delta<0.0f) { delta=minf(delta,-0.01f); s->current=maxf(s->current+delta,target); }
}
extern "C" void RaceRankDisplay__render_main(Self *s,Ctx *ctx) {
 if (!s->tex) func_003A3EF0(s);
 float alpha=s->alpha*s->fade;
 func_004AA1D8(1.0f,1.0f,1.0f,alpha);
 func_0044DE80(&D_00623838,func_003AFEC8(0x80c8c8c8,alpha));
 float x=func_003AFD18(s->fx,(float)s->x,(float)s->w);
 float y=func_003AFD18(s->fy,(float)s->y,(float)s->h);
 func_003AF108(s->tex,x,y,(float)s->w,(float)s->h,0,0);
 Vec a,b,c,d;
 a.x=0; a.y=y+8.0f; a.z=0;
 b.x=0; b.y=y+(float)s->h-3.0f; b.z=0;
 func_0049E2D8(&a,&c); func_0049E2D8(&b,&d);
 int top=(int)c.y; int height=(int)d.y-top;
 if (ctx->half) { top>>=1; height>>=1; }
 func_004A2E68(0,top,640,height); func_004A1638(18);
 func_0044D920(&D_00623838,D_006A1400); D_00623838.flags=15;
 int lines=func_0044E3F8(&D_00623838);
 float factor=0.2f;
 float target=(float)s->rank;
 float current=s->current;
 s->line=(float)lines;
 approach(s,target,(target-current)*factor);
 float cur=s->current;
 int rank=(int)cur;
 float frac=cur-(float)rank;
 float cx=x+(float)s->w*0.5f-1.0f;
 float py=y+(float)s->h-19.0f-frac*s->line;
 float next=py+s->line;
 Font *font=&D_00623838;
 float px;
 if (rank==1) px=cx+4.0f; else px=cx+0.0f;
 func_0044DDF8(font,px,py,0.0f);
 func_0044E088(&D_00623838,D_006A1408,rank+0x30);
 if (frac!=0.0f) { func_0044DDF8(&D_00623838,cx,next,0.0f); func_0044E088(&D_00623838,D_006A1408,rank+0x31); }
 D_00623838.flags=0; func_0044D988(&D_00623838);
 func_004AB040(18); func_001056A0(ctx);
}
