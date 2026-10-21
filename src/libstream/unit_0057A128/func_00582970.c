/* compiler: ee-gcc2.9-991111 */
struct Block { int w[4]; };
extern int D_006570C0[6];
extern int D_00655EEC;
extern char D_00657A40[];
extern int func_00580AD0(int);
extern void func_005ADCC0(int);
extern int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
int func_00582970(struct Block *out,int *n) {
 int *buf;
 int r;
 if(!func_00580AD0(5)) return 0;
 buf=D_006570C0;
 if(func_005B19B0(D_00657A40,26,0,0,0,buf,24,0,0)<0) {
 func_005ADCC0(D_00655EEC); return 0;
 }
 *out=*(struct Block *)((unsigned int)(buf+2)|0x20000000);
 *n=*(int *)((unsigned int)(buf+1)|0x20000000);
 r=*(int *)((unsigned int)buf|0x20000000);
 func_005ADCC0(D_00655EEC);
 return r;
}
