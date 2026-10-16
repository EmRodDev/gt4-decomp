/* compiler: ee-gcc2.96-as2004 */
typedef unsigned int u32;
struct __attribute__((packed)) HeaderS { char magic[4]; u32 size; short w,h; char rest[4]; unsigned char flags; };
struct __attribute__((packed)) HeaderU { char magic[4]; u32 size; unsigned short w,h; char rest[4]; };
extern "C" {
int func_0057F188(const void *, const void *, u32);
int func_005AE780(int);
int func_005AE7E8(int);
int func_005ADB90();
int func_005AD990(int, void (*)(), int, int);
int func_005AD9C0(int, void (*)(), int, int);
int func_005AD9A0(int,int);
int func_005AD9D0(int,int);
int func_005ADA20(int,void (*)(),int);
int func_005ADA30(int);
void func_005ADBC0();
int func_005ADBF0(int);
void func_005ADF20(int);
void func_00563028();
void func_00563298();
void func_0054D0F0();
void func_00562D58(u32);
int func_005B72A8();
int func_005B72F8();
int func_0054CDF0(u32,u32);
void func_0054D070();
void func_0054CFA8();
void func_0054D0B8();
extern char D_006C8490[];
extern int D_0086F604;
}
#define REG(a) (*(volatile u32 *)(a))
#define SYNC() __asm__ volatile("sync")

extern "C" int func_0054C8F0(int mode,u32 dest,unsigned char *data,...) {
 u32 size, pixels;
 unsigned char flags;
 if(func_0057F188(data,D_006C8490,4)) return -1;
 switch(mode) {
 case 0: { HeaderS *h=(HeaderS *)data; data+=16; size=h->size-16; pixels=h->w*h->h*4; flags=h->flags; break; }
 case 1: { HeaderU *h=(HeaderU *)data; data+=16; size=h->size-16; pixels=h->w*h->h*4; flags=0; break; }
 default: return -1;
 }
 func_005AE780(8);
 {
 u32 s=REG(0x1000E010);
 REG(0x1000E010)=8; (void)REG(0x1000E010); SYNC();
 if(s&0x80000) { REG(0x1000E010)=0x80000; (void)REG(0x1000E010); SYNC(); }
 u32 s2=REG(0x1000E010);
 REG(0x1000E010)=16; (void)REG(0x1000E010); SYNC();
 if(s2&0x100000) { REG(0x1000E010)=0x100000; (void)REG(0x1000E010); SYNC(); }
}
 int thread=func_005ADB90();
 int handler1=func_005AD990(8,func_0054D070,0,thread);
 int handler2=func_005AD9C0(3,func_0054CFA8,0,thread);
 func_00563028();
 func_0054D0F0();
 func_00562D58(0);
 REG(0x1000B400)&=~12; SYNC();
 REG(0x1000B410)=(u32)data&0xfffffff; SYNC();
 REG(0x1000B420)=((size+15)>>4)+1; SYNC();
 func_005ADF20(0); SYNC();
 func_005B72A8();
 u32 old=REG(0x1000F520);
 REG(0x1000F590)=old|0x10000; (void)REG(0x1000F590); SYNC();
 REG(0x1000B400)|=0x100; (void)REG(0x1000B400); SYNC();
 REG(0x1000F590)=old&~0x10000; (void)REG(0x1000F590); SYNC();
 func_005B72F8();
 func_0054CDF0(dest,pixels);
 while((int)REG(0x10002010)<0) {}
 func_00563298();
 while((int)REG(0x10002010)<0) {}
 REG(0x10002010)=(flags&0xfb)<<16; SYNC();
 while((int)REG(0x10002010)<0) {}
 func_005AE7E8(8);
 REG(0x10002000)=(((flags>>2)&1)<<24)|0x10010000; SYNC();
 D_0086F604=func_005ADA20(1000,func_0054D0B8,thread);
 func_005ADBC0();
 func_005ADA30(D_0086F604);
 func_005ADBF0(thread);
 int result=0;
 u32 state=REG(0x10002010);
 if(state&0x4000) result=-1;
 if(state&0x80000000) result=-1;
 func_00563028();
 func_005AE780(8);
 func_0054D0F0();
 {
 u32 s=REG(0x1000E010);
 REG(0x1000E010)=8; (void)REG(0x1000E010); SYNC();
 if(s&0x80000) { REG(0x1000E010)=0x80000; (void)REG(0x1000E010); SYNC(); }
 u32 s2=REG(0x1000E010);
 REG(0x1000E010)=16; (void)REG(0x1000E010); SYNC();
 if(s2&0x100000) { REG(0x1000E010)=0x100000; (void)REG(0x1000E010); SYNC(); }
}
 func_005AD9A0(8,handler1);
 func_005AD9D0(3,handler2);
 return result;
}
