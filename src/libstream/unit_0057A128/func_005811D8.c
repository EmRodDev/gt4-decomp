/* compiler: ee-gcc2.9-991111 */
extern int D_00655ED0,D_00655F10,D_00655F00;
extern volatile int D_00655EF0;
extern char D_006CE1B8[],D_006CE180[],D_006CE1A0[];
extern int D_00875010,D_00657940;
struct Cl { char pad[36]; int server; };
extern struct Cl D_00874FD0;
void func_005801D8(void);
int func_00580FC0(int);
void func_005ADCC0(int);
int func_005ADCF0(int);
void func_005B0750(const char *,...);
void func_005B0F78(void *,int);
void func_005B1028(int);
int func_005B17D0(void *,int,int);
int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
int func_005B72A8(void);
int func_005B72F8(void);
int func_005811D8(int mode) {
 int i,j,r;
 if(D_00655ED0>0) func_005B0750(D_006CE1B8);
 func_005801D8();
 if(D_00655EF0!=func_005ADCF0(D_00655EF0)) return mode!=8?6:-1;
 func_005B1028(0);
 i=0;
 if(D_00655F10<0) {
  for(;;) {
   if(func_005B17D0(&D_00874FD0,0x8000059C,0)<0) {
    if(D_00655ED0>0) func_005B0750(D_006CE180);
    for(j=0x100000;j!=-1;j--);
    continue;
   }
   if(D_00874FD0.server) { D_00655F10=0; break; }
   if(i>=17) {
    func_005ADCC0(D_00655EF0);
    return func_00580FC0(mode);
   }
   for(j=0x100000;j!=-1;j--);
   i++;
  }
 }
 r=func_005B72A8();
 D_00655F00=0;
 if(r) func_005B72F8();
 D_00875010=mode;
 func_005B0F78(&D_00875010,4);
 if(func_005B19B0(&D_00874FD0,0,0,&D_00875010,4,&D_00657940,4,0,0)<0) {
  func_005ADCC0(D_00655EF0);
  return mode!=8?6:-1;
 }
 if(D_00655ED0>0) func_005B0750(D_006CE1A0);
 r=*(int *)((unsigned)&D_00657940|0x20000000);
 func_005ADCC0(D_00655EF0);
 return r;
}
