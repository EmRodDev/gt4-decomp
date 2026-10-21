/* compiler: ee-gcc2.9-991111 */
struct S {
 int a,b,c,size,pos;
 int (*open)(int,int,int,int,int,void *);
 int (*next)(int,int,int,int);
 int f1c,f20,f24;
 int (*sync)(int,int,int *);
 int (*err)(int,int);
};
extern struct S D_0087E1C0;
struct R { int p[4]; int size; };
extern struct R D_00876140;
int func_00589D48(int x,int y,int z) __attribute__((register_precision(s0,128)));
int func_00589D48(int x,int y,int z) {
 int r;
 do {
  r = D_0087E1C0.open(D_0087E1C0.a,D_0087E1C0.b,D_0087E1C0.c,0,1,&D_00876140);
  if(r < -99) {
   r=D_0087E1C0.err(13,r);
   return -r | 0x81080000;
  }
 } while(r < 0);
 D_0087E1C0.sync(0,0,&r);
 if(r < 0) { r=D_0087E1C0.err(13,r); return r; }
 D_0087E1C0.size=D_00876140.size;
 do {
  r=D_0087E1C0.next(D_0087E1C0.a,D_0087E1C0.b,D_0087E1C0.c,z);
 } while(r<0);
 D_0087E1C0.sync(0,0,&r);
 if(r<0) { r=D_0087E1C0.err(2,r); return r; }
 return r;
}
