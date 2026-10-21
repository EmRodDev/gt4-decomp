/* compiler: ee-gcc2.9-991111 */
extern int func_005B6268(void);
extern int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
extern char D_00889E80[];
extern int D_00889C80[8];
int func_005B6DF8(int addr, void *dst, unsigned int type) {
 if (func_005B6268()<0) return 0xffff0000;
 if (type>=3) return 0xfffefffe;
 D_00889C80[0]=addr;
 D_00889C80[1]=type;
 if (func_005B19B0(D_00889E80,3,0,D_00889C80,32,D_00889C80,32,0,0)<0) return 0xfffeffff;
 if (type==0) *(unsigned char *)dst=*(unsigned char *)D_00889C80;
 else if (type==1) *(unsigned short *)dst=*(unsigned short *)D_00889C80;
 else if (type==2) *(int *)dst=D_00889C80[0];
 else return 0xfffefffe;
 return 0;
}
