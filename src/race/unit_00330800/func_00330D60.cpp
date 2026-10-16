/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Image { int x; char *data; int p8, pc; int w,h,stride,p1c,bpp; };
extern "C" int func_004997B0(int,int,int,void*);
extern "C" void func_004A4550(int,int);
extern "C" void func_004A4810(int,unsigned int,unsigned int);
extern "C" void func_004AB040(unsigned int);
extern "C" void func_004A29A8(int);
extern "C" void func_004A1638(unsigned int);
extern "C" void func_004A2808(signed char,float);
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" void func_004A6498(int,int,int,int,int,int,int,int);
extern "C" void func_00330D60(Image *p,int x,int y,float alpha) {
 int w=p->w; int h=p->h;
 int size=w*p->bpp;
 size *= h;
 int index=y*p->stride+x;
 func_004997B0(1,w,h,p->data+size*index);
 func_004A4550(4,2); func_004A4550(5,2);
 func_004A4810(0,0,w-1); func_004A4810(1,0,h-1);
 func_004A4550(3,0); func_004A4550(2,0);
 func_004AB040(5); func_004AB040(4);
 func_004A29A8(0); func_004A1638(6);
 func_004A2808(100,alpha);
 func_004AA1D8(1.0f,1.0f,1.0f,1.0f);
 func_004A6498(0,0,w,h,0,0,w,h);
}
