/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct Image { int f0; u8 *pixels; int f8,width,height; int f14,f18,f1c,stride; };
struct Source { int data[3]; int width,height; int rest[3]; };
extern char D_00694BB0[];
extern "C" int func_001CB1D0(Source *,const char *);
extern "C" void func_001CB1E8(Source *,int);
extern "C" u8 *func_001CB340(Source *,int,int);
extern "C" void func_001CAB90(Image *p) {
 Source img;
 int y=0;
 func_001CB1D0(&img,D_00694BB0);
 int width=img.width;
 int height=img.height;
 int xoff=p->height*p->f18-width;
 int yoff=p->f14*p->f1c-height;
 for(;y<height;y++) {
  u8 *dst=(u8 *)(p->height*p->stride*(yoff+y)+xoff*p->stride+(int)p->pixels);
  for(int x=0;x<width;x++) {
   u8 *src=func_001CB340(&img,x,y);
   int alpha=src[3];
   int inv=255-alpha;
   int r=dst[0]*inv;
   int g=dst[1]*inv;
   int b=dst[2]*inv;
   dst[0]=(r+src[2]*alpha)>>8;
   dst[1]=(g+src[1]*src[3])>>8;
   dst[2]=(b+src[0]*src[3])>>8;
   dst+=3;
  }
 }
 func_001CB1E8(&img,2);
}
