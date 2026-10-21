/* compiler: ee-gcc2.9-991111 */
extern volatile int D_00655EEC;
extern volatile int D_00655F20;
extern char D_00657A40[];
extern int D_006570C0[];
int func_00580AD0(int);
void func_005ADCC0(int);
int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
int func_00582648(void) {
 int r;
 if(!func_00580AD0(30)) return 0;
 D_00655F20=8;
 if(func_005B19B0(D_00657A40,22,0,0,0,D_006570C0,4,0,0)<0) {
 func_005ADCC0(D_00655EEC);
 D_00655F20=0;
 return 0;
 }
 D_00655F20=0;
 r=*(int *)((unsigned int)D_006570C0|0x20000000);
 func_005ADCC0(D_00655EEC);
 return r;
}
