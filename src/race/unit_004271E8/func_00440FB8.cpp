/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Spec { char pad[12]; short year; char rest[18]; };
struct Range { int low,high; };
struct Table { int ranges[15][2]; };
extern Table D_006A6910;
extern "C" void func_003434A8(void*,unsigned);
extern "C" void func_00343578(void*,float);
extern "C" void func_00343698(void*,float);
extern "C" void func_003438A0(void*,float);
extern "C" void func_00343978(void*,float);
extern "C" void *func_00441248(void*);
extern "C" int func_00441298(void*,int);
extern "C" long func_004454C0(void*);
extern "C" int func_00445808(void*);
extern "C" int func_00448820(long,Spec*);
extern "C" void func_005792E8(int*,int);
extern "C" float mBlockTransition__getBlock(int*,float,float);
extern "C" void func_00440FB8(char *self,int seed,int variation,int amount) {
 int rng[4]; Spec spec;
 char *sub=self+0x4a0;
 func_005792E8(rng,seed);
 if(variation<0) variation=(int)mBlockTransition__getBlock(rng,0.0f,(float)func_00445808(func_00441248(self)));
 func_00441298(self,variation);
 if(amount<0) {
  func_00448820(func_004454C0(func_00441248(self)),&spec);
  int year=spec.year-1990;
  if(year<0) year=0;
  year=year>=15 ? 14 : year;
  amount=(int)mBlockTransition__getBlock(rng,(float)(D_006A6910.ranges[year][0]*1000000),(float)(D_006A6910.ranges[year][1]*1000000));
 }
 float f=(float)amount;
 func_003434A8(sub,amount);
 func_00343578(sub,f);
 func_00343978(sub,f);
 func_00343698(sub,f);
 func_003438A0(sub,f);
 func_003438A0(sub,0.0f);
}
