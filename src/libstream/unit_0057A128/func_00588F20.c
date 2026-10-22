/* compiler: ee-gcc2.9-991111 */
struct S { char pad[16]; int p10; int p14; int flags; int p1c; char pad20[16]; int p30; int p34; };
extern void *func_0058B1B8(void);
extern int func_00588BA8(int,int,int,int*,int,int);
extern int func_00588D38(int,int,int*,int);
extern int func_00588E08(int,int,int,int*);
extern int func_005898C0(int,int,int,int,int*);
extern void func_0058B140(int);
extern void func_0058B1C0(void*);
extern void func_0058B250(int,int);
extern void func_0058B260(int,void*);
void * __attribute__((register_precision(s0, 128))) func_00588F20(struct S *s,int n,int size,int a3,int *out,int *err) {
 int base=s->p30;
 int ctx=s->p34;
 int p;
 void *handle=func_0058B1B8();
 int flag;
 if(!handle) { *err=0x81050069; return 0; }
 {
  int type=s->flags & 255;
  if(type==1 || (flag=1,type!=0)) flag=0;
  if(s->flags & 0x1000) flag^=1;
  if(n>=0) {
   p=func_00588BA8(base,ctx,n,err,size,flag);
   if(!p) {
    func_0058B1C0(handle);
    return 0;
   }
  } else p=s->p10;
  if(s->flags & 0x6000) {
   int r=-1;
   if(s->flags & 0x2000) r=func_00588E08(p,size,0,err);
   if(s->flags & 0x4000) r=func_00588E08(p,size,1,err);
   if(r<=0) {
    if(n>=0) func_0058B140(p);
    func_0058B1C0(handle);
    return 0;
   }
   size=r;
  }
  if(s->flags & 0x1000) {
   flag=func_00588D38(p,size,err,flag^1);
   if(n>=0) func_0058B140(p);
   if(!flag) {
    func_0058B1C0(handle);
    return 0;
   }
   p=flag;
  }
  *out=func_005898C0(p,a3,s->flags & 255,s->p1c,err);
  if(!*out) {
   if(n>=0) func_0058B140(p);
   func_0058B1C0(handle);
   return 0;
  }
  func_0058B250(p,a3);
  func_0058B260(a3,handle);
  if(n>=0) func_0058B140(p);
  return handle;
 }
}
