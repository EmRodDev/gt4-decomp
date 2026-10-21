/* compiler: ee-gcc2.9-991111 */
struct Block { int w[16]; };
extern struct Block D_008851C0, D_00885240;
extern void func_005AE598(void *,void *);
extern int func_005B72A8(void);
extern int func_005B72F8(void);
int func_0058FE98(int i) {
 func_005AE598(&D_008851C0,(char *)&D_008851C0+128);
 func_005B72A8();
 D_00885240=D_008851C0;
 func_005B72F8();
 return D_00885240.w[i]==1 ? 1:3;
}
