/* compiler: ee-gcc2.9-991111 */
extern int func_005B6268(void);
extern int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
extern char D_00889E80[];
extern int D_00889C80[8];
int func_005B6EE8(int addr, void *src, int type) {
 if (func_005B6268()<0) return 0xffff0000;
 D_00889C80[0]=addr;
 D_00889C80[1]=type;
 if (type==0) *(unsigned char *)&D_00889C80[2]=*(unsigned char *)src;
 else if (type==1) *(unsigned short *)&D_00889C80[2]=*(unsigned short *)src;
 else if (type==2) D_00889C80[2]=*(int *)src;
 else return 0xfffefffe;
 if (func_005B19B0(D_00889E80,2,0,D_00889C80,32,D_00889C80,16,0,0)<0) return 0xfffeffff;
 return 0;
}
