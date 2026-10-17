/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32; typedef unsigned long u64;
struct Reg { char pad[0x20]; u64 value; };
struct Tex { char pad[0x18]; Reg *reg; };
struct Rect { char pad[4]; short x,y; char rest[0x54]; };
struct Self { char pad[0xc]; float alpha; Tex *tex; char pad14[7]; unsigned char a,b; char pad1d[7]; float right,left,num1,den1,num2,den2; char pad3c[4]; Tex *t40,*t44,*t48,*t4c; char pad50[0x1c]; Rect r1,r2; };
extern "C" int func_00499728(Tex*);
extern "C" void func_0049CC48(Reg*);
extern "C" void func_004A2808(int,float);
extern "C" void func_004A4550(int,int);
extern "C" int func_003AFEC8(u32,float);
extern "C" void func_004AA168(int);
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" void func_003AF108(Tex*,int,int,float,float,float,float);
extern "C" void func_003AF6E0(float,float,float,float,float,float,float,float);
static inline u32 pow2(u32 n) { int r; n--; __asm__("plzcw %0, %1":"=r"(r):"r"(n));return 1U<<((r&31)^31); }
static inline float ratio(u32 n) { float f=(float)n;return f/(float)pow2(n); }
static inline float clamp(float f) { float z=0.0f,o=1.0f; __asm__("max.s %0, %1, %2":"=f"(f):"f"(f),"f"(z)); __asm__("min.s %0, %1, %2":"=f"(f):"f"(f),"f"(o)); return f; }
extern "C" void func_003A8968(Self *s) {
 if(s->tex) {
 func_00499728(s->tex); func_0049CC48(s->tex->reg);
 func_004A2808(0x44,0.0f);func_004A4550(2,1);func_004A4550(3,1);
 func_004AA168(func_003AFEC8(0x800000f0,s->alpha));
 u64 r=s->tex->reg->value; u32 w=((r>>14)&1023)+1,h=((r>>34)&1023)+1;
 float u=ratio(w),v=ratio(h);
 Rect *rect=&s->r1;
 float x=(float)rect->x, y=(float)rect->y+23.0f-1.5f+58.0f;
 float f=clamp(s->left);
 float left=x+121.0f;
 u32 color=0x80e3b896;
 func_003AF6E0(left,y-f*58.0f,left+20.0f,y,0.0f,v*(1.0f-f),u,v);
 func_004AA168(func_003AFEC8(color,s->alpha));
 x+=195.0f; f=clamp(s->right);
 func_003AF6E0(x,y-f*58.0f,x+20.0f,y,u,v*(1.0f-f),0.0f,v);
 if(s->a) {
 func_004AA1D8(1.0f,1.0f,1.0f,s->alpha);
 float x1=(float)(rect->x-22),y1=(float)(rect->y+19);
 float x2=x1+38.0f,y2=y1+64.0f;
 func_003AF108(s->t40,0,0,x1,y1,38.0f,64.0f);
 func_00499728(s->t44);func_0049CC48(s->t44->reg);
 int n=(int)(clamp(s->num1/s->den1)*10.0f+0.5f);
 if(n>0) {
 func_004AA168(func_003AFEC8(n>=3?color:0x800000c8,s->alpha));
 float d=60.0f-(float)n*52.0f*0x1.999998p-4f;
 if(n>=6)d-=4.0f;
 func_003AF6E0(x1,y1+d,x2,y2,0.0f,d*0.015625f,0.59375f,1.0f);
 }
 }
 if(s->b) {
 func_004AA1D8(1.0f,1.0f,1.0f,s->alpha);
 Rect *rect2=&s->r2;
 float x1=(float)(rect2->x-16),y1=(float)(rect2->y+19);
 float x2=x1+38.0f,y2=y1+64.0f;
 func_003AF108(s->t48,0,0,x1,y1,38.0f,64.0f);
 func_00499728(s->t4c);func_0049CC48(s->t4c->reg);
 int n=(int)(clamp(s->num2/s->den2)*10.0f+0.5f);
 if(n>0) {
 func_004AA168(func_003AFEC8(0x800000f0,s->alpha));
 float d=60.0f-(float)n*52.0f*0x1.999998p-4f;
 if(n>=6)d-=4.0f;
 func_003AF6E0(x1,y1+d,x2,y2,0.0f,d*0.015625f,0.59375f,1.0f);
 }
 }
 }
}
