/* compiler: ee-gcc2.9-as296 */
extern volatile int D_00655F20, D_00655EF4;
extern struct { volatile int value; } D_00655EE8;
extern char D_00657090[];
int func_00580928(void);
int func_005807D0(int);
void func_005ADCC0(int);
void func_0057FF10(void *);
int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
int func_00582228(void) {
 if(func_00580928()==6) return 0;
 if(!func_005807D0(10)) return 0;
 D_00655F20=5;
 D_00655EF4=1;
 if(func_005B19B0(D_00657090,6,1,0,0,0,0,func_0057FF10,&D_00655F20)<0) {
 D_00655F20=0;
 D_00655EF4=0;
 func_005ADCC0(D_00655EE8.value);
 return 0;
 }
 return 1;
}
