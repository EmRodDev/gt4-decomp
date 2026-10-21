/* compiler: ee-gcc2.9-as296 */
extern volatile char D_00875040[],D_00657090[];
extern volatile void *D_00655FC0;
extern volatile int D_00655F40[2],D_00655EE8;
extern volatile int D_00655F20;
int func_005807D0(int);
void func_005B0F78(void *,int);
void func_005ADCC0(int);
int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
int func_00581EC8(void *out) {
 void **cmd=&D_00655FC0;
 int *res;
 int r;
 char *buf;
 if(!func_005807D0(8)) return 0;
 buf=D_00875040;
 *cmd=buf;
 func_005B0F78(buf,0x810);
 res=D_00655F40;
 func_005B0F78(cmd,12);
 D_00655F20=3;
 if(func_005B19B0(D_00657090,4,0,cmd,12,res,8,0,0)<0) {
  D_00655F20=0;func_005ADCC0(D_00655EE8);return 0;
 }
 D_00655F20=0;
 r=res[0];
 if(res[1]==0) __builtin_memcpy(out,(void *)((unsigned)buf|0x20000000),0x400);
 else __builtin_memcpy(out,(void *)((unsigned)buf|0x20000000),0x810);
 func_005ADCC0(D_00655EE8);
 return r;
}
