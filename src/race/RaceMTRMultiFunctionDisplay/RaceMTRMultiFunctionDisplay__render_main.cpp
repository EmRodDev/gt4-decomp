/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Display { char p0;unsigned char xf,yf,p3;short x,y,w,h;float alpha; };
struct Buffer { int head[2];unsigned w,h;char rest[48]; };
extern "C" void func_00105250(void*);
extern "C" void func_00105280(void*,int);
extern "C" void func_001056A0(void*);
extern "C" void func_00105728(void*);
extern "C" int RaceMTRMultiFunctionDisplay__render_buffer(Display*,void*);
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int,float);
extern "C" void func_004A4550(int,int);
extern "C" int func_003AFD78(int,int,int);
extern "C" void func_003AF6E0(float,float,float,float,float,float,float,float);
inline unsigned leadingSigns(unsigned x){unsigned r;asm("plzcw %0, %1":"=r"(r):"r"(x));return r;}
inline unsigned extentPower(unsigned n){return 1U<<(31^(leadingSigns(n-1)&31));}
extern "C" void RaceMTRMultiFunctionDisplay__render_main(Display*self,void*ctx){
 Buffer b;
 func_00105250(&b);RaceMTRMultiFunctionDisplay__render_buffer(self,&b);func_001056A0(ctx);func_00105728(&b);
 func_004AA1D8(1,1,1,self->alpha);func_004A1638(6);func_004A2808(0x44,0);func_004A4550(2,1);func_004A4550(3,1);
 unsigned width=b.w,height=b.h;
 float x=func_003AFD78(self->x,width,self->xf);
 float y=func_003AFD78(self->y,height,self->yf);
 float w=(int)width,h=(int)height;
 float u=(float)width/(float)extentPower(width),v=(float)height/(float)extentPower(height);
 func_003AF6E0(x,y,x+w,y+h,0,0,u,v);
 func_00105280(&b,2);
}
