typedef int s32;
struct Img { int w,h,pitch,unk,dst,src,extra; };
struct Rec { int n; float threshold; char pad[0x14]; int dst; int x,y,w,h; int unused; int ax,ay,bx,by; char pad44[8]; };
extern "C" int func_001C1D00(int,int,int,int,int,int,int,int*,int*) throw();
extern "C" int func_001C1DF8(int,int,int,int,int,int,int,int*,int*) throw();
extern "C" void func_001C1B78(int,int,int,int,int,int,int,int,int,int) throw();
extern "C" void func_001C1C50(int,int,int,int,int) throw();
extern "C" int func_001C1EF8(int,int,int) throw();
static inline int source(Img *a) { return a->src; }
extern "C" int func_001C3F50(char *self,int y,int x) {
 int x0,y0,x1,y1;
 char *v=self+y*0x4c;
 Img *a=(Img*)(self+x*0x1c+0x10);
 Rec *r=(Rec*)(v+0x10c);
 int *rect=(int*)(v+0x12c);
 Img *b=(Img*)(self+y*0x1c+0x80);
 func_001C1D00(source(a),a->w,a->h,rect[0],rect[1],rect[2],rect[3],&x0,&y0);
 func_001C1DF8(source(a),a->w,a->h,rect[0],rect[1],rect[2],rect[3],&x1,&y1);
 int w=x1-x0+1,h=y1-y0+1;
 int rw=r->bx-r->ax+1,rh=r->by-r->ay+1;
 int ox=r->ax*w/rw,oy=r->ay*h/rh;
 float ratio=((float)w/(float)rw)/((float)h/(float)rh);
 if(ratio<0.75f || ratio>1.25f) return 0;
 *(int*)(self+0x2d8)=h;
 *(int*)(self+0x2d0)=y0;
 *(int*)(self+0x2d4)=w;
 *(int*)(self+0x2cc)=x0;
 int yy=y0-oy;
 int xx=x0-ox;
 if(yy<0) yy=0;
 if(xx<0) xx=0;
 func_001C1B78(r->dst,b->w,b->h,rw,rh,source(a)+(a->pitch*yy+xx),a->w,a->h,w,h);
 func_001C1C50(r->dst,r->dst,b->src,b->w,b->h);
 float f=(float)func_001C1EF8(r->dst,b->w,b->h)/(float)(b->w*b->h);
 return f<r->threshold ? 1 : 0;
}
