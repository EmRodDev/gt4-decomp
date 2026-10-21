/* compiler: ee-gcc2.9-991111 */
extern int D_00657500;
extern volatile int D_00655EEC;
extern int D_006570C0[2];
extern char D_00657A40[];
extern int func_00580AD0(int);
extern void func_005ADCC0(int);
extern void func_005B0F78(void *,int);
extern int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
int func_00582C48(int a,unsigned int *out) {
 int *send=&D_00657500;
 int *buf;
 int r;
 if(!func_00580AD0(26)) return -1;
 D_00657500=a;
 func_005B0F78(send,4);
 buf=D_006570C0;
 if(func_005B19B0(D_00657A40,5,0,send,4,buf,8,0,0)<0) {
 func_005ADCC0(D_00655EEC); return -1;
 }
 if(out) *out=*(unsigned int *)((unsigned int)(buf+1)|0x20000000);
 r=*(int *)((unsigned int)buf|0x20000000);
 func_005ADCC0(D_00655EEC);
 return r;
}
