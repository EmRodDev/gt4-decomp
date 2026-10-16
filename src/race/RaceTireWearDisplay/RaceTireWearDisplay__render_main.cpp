struct State { unsigned long words[5]; };
struct Texture { char pad[24]; State *state; };
struct Obj { char p0; unsigned char xf,yf,p3; short x,y,w,h; float alpha; Texture *tex; int p14; int enabled,color; int colors[4]; };
extern char D_006A1510[];
extern int D_006A1520[4][2];
extern "C" Texture *func_003A1E10(const char*);
extern "C" int func_001052E0(void*,int,int,int);
extern "C" void func_001056A0(void*);
extern "C" void func_00105728(void*);
extern "C" void func_00105280(void*,int);
extern "C" void func_004AA168(int);
extern "C" void func_004A2980(int);
extern "C" void func_004AB040(unsigned);
extern "C" void func_004A4550(int,int);
extern "C" int func_00499728(Texture*);
extern "C" void func_0049CC48(State*);
extern "C" void func_004A6498(int,int,int,int,int,int,int,int);
extern "C" int func_003AFEC8(int,float);
extern "C" void func_004A6140(int,int,int,int);
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" void func_004A1638(unsigned);
extern "C" void func_004A2808(int,float);
extern "C" int func_003AFD78(int,int,int);
extern "C" void func_003AF6E0(float,float,float,float,float,float,float,float);
inline unsigned leadingSigns(unsigned x){unsigned r;asm("plzcw %0, %1":"=r"(r):"r"(x));return r;}
inline unsigned extentPower(unsigned n){return 1U<<(31^(leadingSigns(n-1)&31));}
extern "C" void RaceTireWearDisplay__render_main(Obj*self,void*ctx){
 int buf[16];
 if(self->enabled){
 Texture *t=self->tex;
 if(!t){t=func_003A1E10(D_006A1510);self->tex=t;}
 unsigned long bits=t->state->words[4];
 unsigned width=(bits>>14&1023)+1,height=(bits>>34&1023)+1;
 func_001052E0(buf,0,width,height);func_001056A0(buf);
 func_004AA168(self->color);func_004A2980(-1);func_004AB040(6);
 func_004A4550(2,0);func_004A4550(3,0);
 func_00499728(self->tex);func_0049CC48(self->tex->state);
 func_004A6498(0,0,width,height,0,0,width,height);
 for(int i=0;i<4;i++){
 func_004AA168(func_003AFEC8(self->colors[i],self->alpha));
 int x=D_006A1520[i][0],y=D_006A1520[i][1];
 func_004A6140(x,y,x+6,y+11);
 }
 func_001056A0(ctx);func_00105728(buf);
 func_004AA1D8(1,1,1,self->alpha);func_004A1638(6);func_004A2808(0x44,0);
 func_004A4550(2,1);func_004A4550(3,1);
 float u=(float)width/(float)extentPower(width),v=(float)height/(float)extentPower(height);
 float x=func_003AFD78(self->x,self->w,self->xf);
 float y=func_003AFD78(self->y,self->h,self->yf);
 func_003AF6E0(x,y,x+(float)self->w,y+(float)self->h,0,0,u,v);
 func_00105280(buf,2);
 }
}
