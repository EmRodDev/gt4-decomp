/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned char u8;
union Word { int n; u8 b[4]; };
struct Image { int p0; char *data; int p8,pc; Word w; int h; Word count; int p1c,bpp,p24; Word depth; };
struct Name { int a; u16 b; };
struct Header { short magic; u8 storage,bpc; u16 dim,x,y,z; int min,max,dummy; Name name; char rest[480]; };
extern Name D_0069F118;
extern "C" void *func_005A48D8(void*,int,unsigned int);
extern "C" int func_005B2DF0(const char*,int,...);
extern "C" int func_005B3080(unsigned int);
extern "C" int func_005B36A8(int,void*,unsigned int);
extern "C" void func_00332A20(int,int,void*,int) throw();
extern "C" void func_00332740(int,void*,unsigned int) throw();
static inline int swap16(u16 x) { return ((x & 255) << 8) | (x >> 8); }
extern "C" int func_00332AA8(Image *p,const char *path) {
 Header h;
 func_005A48D8(&h,0,512);
 h.magic=swap16(0x01da);
 h.storage=0;
 h.bpc=1;
 h.dim=0x300;
 h.x=(p->w.b[1] | (p->w.b[0]<<8));
 h.y=(p->depth.b[1] | (p->depth.b[0]<<8));
 h.z=(p->count.b[1] | (p->count.b[0]<<8));
 h.min=0;
 h.max=0xff000000;
 h.name.a=D_0069F118.a;
 h.name.b=D_0069F118.b;
 int fd=func_005B2DF0(path,0x602);
 if(fd<0) return 0;
 int pad=(p->depth.n-p->h)/2*p->w.n;
 func_005B36A8(fd,&h,512);
 for(int i=0;i<p->count.n;i++) {
  func_00332A20(fd,pad,&h,512);
  int size=p->w.n*p->bpp; size*=p->h;
  func_00332740(fd,p->data+size*i,size);
  func_00332A20(fd,pad,&h,512);
 }
 func_005B3080(fd);
 return 1;
}
