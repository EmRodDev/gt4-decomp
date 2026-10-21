/* compiler: ee-gcc2.9-991111 */
typedef int s32;
struct Req { unsigned char type; char pad[3]; s32 m4,m8,mC,m10,m14,m18,m1C,m20,m24,m28,m2C,m30,m34,m38,m3C; };
extern int func_005878F8(struct Req *, int);
extern int func_0058B200(int);
extern int func_005AE770(void);
extern int func_005ADB90(void);
extern void func_005B0750(const char *, ...);
extern char D_006CE840[], D_006CE888[];
extern int D_0087E180;
int func_005875A0(int a,int b,int c) {
 struct Req r;
 int x,y;
 if (func_005AE770()) return 0x81058007;
 x=func_0058B200((int)__builtin_return_address(0));
 if(x<0) {func_005B0750(D_006CE840); while(1);}
 y=func_005ADB90();
 if(y==D_0087E180) {func_005B0750(D_006CE888,y); while(1);}
 r.type=8; r.m4=x; r.m8=y; r.mC=0; r.m20=a; r.m24=b; r.m28=c;
 return func_005878F8(&r,0);
}
