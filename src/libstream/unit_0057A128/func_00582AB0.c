/* compiler: ee-gcc2.9-991111 */
extern int D_006570C0[2];
extern int D_00655EEC;
extern char D_00657A40[];
int func_00580AD0(int);
void func_005ADCC0(int);
int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
int func_00582AB0(int *a) {
 int *buf;
 int r;
 if(!func_00580AD0(33)) return 0;
 buf=D_006570C0;
 if(func_005B19B0(D_00657A40,33,0,0,0,buf,8,0,0)<0) {
 func_005ADCC0(D_00655EEC); return 0;
 }
 *a=*(int *)((unsigned int)(buf+1)|0x20000000);
 r=*(int *)((unsigned int)buf|0x20000000);
 func_005ADCC0(D_00655EEC);
 return r;
}
