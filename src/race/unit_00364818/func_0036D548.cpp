/* Returns a scalar limit computed from the car state at self+0x104 and the spec pointed to by self+0x10, using
 * 97999.9921875 (a float written out in full) as an unbounded sentinel: every early exit returns it, or its
 * negative when D_0062030A is set and x is negative (inferred from that use). steerWeight is 1 up to the steering
 * magnitude D_0062030C, D_00620314 from 1.0 up, and linear in between. span is |F(p,0x530) - F(p,0x52c)| times the
 * spec float at +0x238, then times the weight, and is returned as long as it is below 1; at 1 or more it becomes
 * the sentinel, or 1 if the spec float at +0x23C is zero. When that float is non-zero extra early outs apply: a
 * state word pattern at +0x520, the byte at +0x522 (0 or, with weight 1, 2), a float at +0x48c above 0.75, and x,
 * y + x + z both positive or both negative. What x, y and z are is unknown. The macros F, B and U read a float,
 * byte and word at an offset. */
struct Self;
extern float D_0062030C,D_00620314;
extern unsigned char D_0062030A;
#define F(p,o) (*(float*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned int*)((char*)(p)+(o)))
extern "C" float func_0036D548(Self*self,float x,float y,float z){
 char*p=(char*)self+0x104;
 char*spec=*(char**)((char*)self+0x10);
 float steerAmount=F(p,0x58c);
 if(steerAmount<0)steerAmount=-steerAmount;
 float steerWeight;
 if(steerAmount<=D_0062030C)steerWeight=1;else if(steerAmount>=1)steerWeight=D_00620314;
 else steerWeight=1-(1-D_00620314)*(steerAmount-D_0062030C)/(1-D_0062030C);
 float lowEnd=F(p,0x52c);
 float span=F(p,0x530)-lowEnd;
 if(span<0)span=-span;
 span*=F(spec,0x238);
 if(!B(p,0x520))x=-x;
 if(D_0062030A && x<0)return -97999.9921875f;
 float enabledValue=F(spec,0x23c);
 if(enabledValue!=0){
 if((U(p,0x520)&0x00ff00ff)==0x10000)return 97999.9921875f;
 int mode=B(p,0x522);
 if(!mode)return 97999.9921875f;
 if(steerWeight==1){
 if(mode==2)return 97999.9921875f;
 if(F(p,0x48c)>.75f)return 97999.9921875f;
 y=(x+y)+z;
 if(x>0 && y>0)return 97999.9921875f;
 if(x<0 && y<0)return 97999.9921875f;
 }
 }
 span*=steerWeight;
 if(span>=1){span=97999.9921875f;if(enabledValue==0)span=1;}
 return span;
}
