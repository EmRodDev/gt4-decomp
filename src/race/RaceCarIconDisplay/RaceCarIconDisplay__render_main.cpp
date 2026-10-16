/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p0; unsigned char xf,yf,p3; short x,y,dx,dy; float alpha; char p10[8]; void **tex; char p1c[12]; float fade; char p2c[24]; float osc; };
extern "C" int func_003A6610(Obj*) throw();
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" int func_004997B0(int,int,int,void*);
extern "C" void func_004A4810(int,unsigned,unsigned);
extern "C" void func_004A4550(int,int);
extern "C" int func_003AFD78(int,int,int);
extern "C" void func_003AF7C8(int,float,float,float,float,float,float,float,float);
inline unsigned leadingSigns(unsigned x){ unsigned r; asm("plzcw %0, %1":"=r"(r):"r"(x)); return r; }
inline unsigned extentPower(unsigned n){ return 1U<<(31^(leadingSigns(n-1)&31)); }
extern "C" void RaceCarIconDisplay__render_main(Obj*self){
 if(self->tex && func_003A6610(self)){
 float alpha=self->fade*self->osc*self->alpha;
 if(!(alpha<=0.0f)){
 func_004AA1D8(1,1,1,alpha);
 func_004997B0(2,96,64,*self->tex);
 func_004A4810(0,0,95);func_004A4810(1,0,63);
 func_004A4550(4,2);func_004A4550(5,2);func_004A4550(2,1);func_004A4550(3,1);
 float x=func_003AFD78(self->x+self->dx,64,self->xf);
 float y=func_003AFD78(self->y+self->dy,32,self->yf);
 float right=x+64.0f,bottom=y+32.0f;
 float uw=(float)extentPower(96);
 unsigned vh=extentPower(64);
 float u=96.0f/uw,v=64.0f/(float)vh;
 func_003AF7C8(3,x,y,right,bottom,0,0,u,v);
 }
 }
}
