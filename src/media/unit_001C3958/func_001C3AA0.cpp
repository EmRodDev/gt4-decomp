/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Img { s32 w,h,pitch,unk,dst,src,extra; };
struct Rect { s32 x,y,w,h,px,py; };
struct Rec { char pad[0x34]; Rect bounds; };
struct Obj { char pad[0x10]; Img img[4]; Img small[4]; Img work; Rec rec[4]; s32 value, value2; char pad244[0x2c]; s32 w,h; char pad278[0x1c]; s32 result,flag,x,y,rw,rh; char pad2ac[0x18]; s32 level,levy,x0,y0,w0,h0; };
extern "C" void func_001C1678(s32,s32,s32,s32) throw();
extern "C" void func_001C1760(s32,s32,s32,s32) throw();
extern "C" void func_001C1850(s32,s32,s32,s32,s32) throw();
extern "C" void func_001C18B0(s32,s32,s32,s32,s32) throw();
extern "C" void func_001C1910(s32,s32,s32,s32) throw();
extern "C" void func_001C1A50(s32,s32,s32,s32,s32,s32) throw();
extern "C" void func_001C1CA8(s32,s32,s32,s32) throw();
extern "C" s32 func_001C1F50(s32,s32,s32,s32,s32,s32,s32) throw();
extern "C" s32 func_001C27C0(Rec*,Img*,s32,s32) throw();
extern "C" s32 func_001C3DE0(Obj*,s32,s32);
extern "C" s32 func_005B72A8();
extern "C" void func_001C3AA0(Obj *self, s32 input) {
 func_001C1678(self->img[0].dst,input,self->w,self->h);
 for(int i=1;i<4;i++) { Img *a=&self->img[i]; Img *b=&self->img[i-1]; func_001C1A50(a->dst,a->w,a->h,b->dst,b->w,b->h); }
 for(int i=0;i<4;i++) func_001C18B0(self->img[i].src,self->img[i].dst,self->img[i].w,self->img[i].h,self->value);
 func_001C1910(self->img[0].extra,self->img[0].src,self->img[0].w,self->img[0].h);
 func_001C1CA8(self->img[0].extra,self->img[0].extra,self->img[0].w,self->img[0].h);
 for(int i=1;i<4;i++) {
  Img *a=&self->img[i]; Img *b=&self->img[i-1];
  func_001C1A50(a->extra,a->w,a->h,b->extra,b->w,b->h);
  func_001C1850(self->img[i].extra,self->img[i].extra,self->img[i].w,self->img[i].h,96);
 }
 int y=3,x=3,a=0,b=0,r;
 for(;;) {
  r=func_001C27C0(&self->rec[y],&self->img[x],a,b);
  if(r) {
   r=func_001C3DE0(self,y,x);
   if(r) break;
   a=self->rec[y].bounds.px+1; b=self->rec[y].bounds.py;
  } else {
   x--;
   if(x<=0) {y--;x=3; if(y<=0) break;}
   a=0;b=0;
  }
 }
 int flag=0,xx=0,yy=0,ww=0,hh=0;
 if(r) {
  xx=self->x0<<self->level; yy=self->y0<<self->level; ww=self->w0<<self->level; hh=self->h0<<self->level;
  func_001C1760(self->work.dst,input,self->w,self->h);
  func_001C18B0(self->work.src,self->work.dst,self->work.w,self->work.h,self->value2);
  u32 n=func_001C1F50(self->work.src,self->work.w,self->work.h,xx,yy,ww,hh);
  float f=(float)n/(float)(ww*hh);
  flag=f>0.1f && f<0.5f;
 }
 int enabled=func_005B72A8();
 self->result=r; self->flag=flag; self->x=xx; self->y=yy; self->rw=ww; self->rh=hh;
 if(enabled) __asm__ volatile("ei");
}
