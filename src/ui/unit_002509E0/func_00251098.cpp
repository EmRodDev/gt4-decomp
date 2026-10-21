struct Obj { int pad; char *vt; char pad8[0x74]; unsigned char count[4]; float magnitude[4]; char pad90[0x14]; short repeat, delay; };
struct Entry { short delta,index; float (*fn)(void*,int,int); };
extern "C" void func_00251838(Obj*,int);
extern "C" float func_0057D118(float,float);
static inline unsigned char increment(unsigned char *p) { unsigned char old=*p; *p=old+1; return old; }
extern "C" int func_00251098(Obj *p,int a,int b,int sectors) {
 Entry *e=(Entry*)(p->vt+0x1e0);
 float x=e->fn((char*)p+e->delta,a,b?0:2);
 Entry *e2=(Entry*)(p->vt+0x1e0);
 float y=e2->fn((char*)p+e2->delta,a,b?1:3);
 float sum=x*x+y*y;
 float length; __asm__ volatile("sqrt.s %0, %1":"=f"(length):"f"(sum));
 if (length>0.0f) { x/=length; y/=length; }
 int step=8/sectors;
 float angle=func_0057D118(y,x)*180.0f/0x1.921fb4p+1f;
 int idx=a*2+b;
 float prev=p->magnitude[idx]; p->magnitude[idx]=length;
 float fstep=(float)step;
 int result=(int)((angle+180.0f+fstep*22.5f)/(fstep*45.0f));
 if (result==sectors) result=0;
 result*=step;
 if (length>0.5f) {
  if (prev<0.5f) { func_00251838(p,a); p->count[idx]=1; }
  else {
   Obj *indexed=(Obj*)(idx+(int)p);
   unsigned char *count=(unsigned char*)indexed+0x7c;
   if ((*count)!=0) {
    int repeat=p->repeat;
    int old=increment(count);
    result=(old!=repeat)?-1:result;
    if (*count>=p->repeat+p->delay) *count=p->repeat;
   }
  }
 } else { p->count[idx]=0; result=-1; }
 return result;
}
