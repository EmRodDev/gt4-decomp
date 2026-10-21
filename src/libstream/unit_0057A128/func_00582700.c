/* compiler: ee-gcc2.9-991111 */
extern int D_00657500[];
extern int D_006570C0[];
extern int D_00655EEC;
extern char D_00657A40[];
int func_00580AD0(int);
void func_005B0F78(void *,int);
void func_005ADCC0(int);
int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
int func_00582700(int a) {
 int *send=D_00657500;
 int *buf;
 int r;
 if(!func_00580AD0(35)) return -1;
 D_00657500[0]=a;
 func_005B0F78(send,4);
 buf=D_006570C0;
 if(func_005B19B0(D_00657A40,35,0,send,4,buf,4,0,0)<0) {
 func_005ADCC0(D_00655EEC); return -1;
 }
 r=*(int *)((unsigned int)buf|0x20000000);
 func_005ADCC0(D_00655EEC);
 return r;
}
