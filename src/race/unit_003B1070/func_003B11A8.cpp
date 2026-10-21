extern "C" int ModelSet2___render(void *,int,void *);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A7698(void *);
static inline int positive(short *p) {return *p>0;}
extern "C" void func_003B11A8(char *self) {
 void *p=self+0x6c8;
 short *cnt=(short *)(self+0x6c2);
 short *start=(short *)(self+0x6c0);
 if(cnt[-1]>=0) {
 func_004A53F8();func_004A7698(p);
 int i=0;
 if(__builtin_expect((int)(positive(cnt)), 0)) do {
 ModelSet2___render(*(void **)self,*start+i,*(void **)(self+0x6b0));
 i++;
 } while(i<*cnt);
 func_004A5400();
 }
}
