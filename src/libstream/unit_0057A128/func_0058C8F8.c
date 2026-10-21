/* compiler: ee-gcc2.9-991111 */
int func_0058BD78(int,int,int,int,int,int *,int);
void *func_005A48D8(void *,int,unsigned int);
int func_0058C8F8(int a,int b,int *c,int *d) {
 int sp[3];
 func_005A48D8(sp,0,12);
 if(func_0058BD78(a,b|0x8000,0,0,1,sp,3)==-1) return 0xFFFF7FF6;
 if(sp[0]==-2) return 0xFFFF7FF5;
 if(sp[0]==-1) return 0xFFFF6FC4;
 if(c) *c=sp[1];
 if(d) *d=sp[2];
 return 0;
}
