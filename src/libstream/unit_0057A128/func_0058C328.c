/* compiler: ee-gcc2.9-991111 */
extern int D_00657AA8, D_00657AA0, D_00657AB0;
extern signed char D_00657A9A;
int func_0058BD78(int,int,int,int,int,void *,int);
int func_0058C328(unsigned int arg0) {
 if(arg0>=5) return -22;
 D_00657AA8=arg0;
 if(func_0058BD78(0,9,arg0,0,1,0,0)<0) return (int)0xFFFF7FF6;
 if(D_00657AA8<3 && D_00657A9A>=2) D_00657AB0=D_00657AA0/2;
 else D_00657AB0=D_00657AA0;
 return 0;
}
