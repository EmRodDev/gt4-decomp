/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Img { int alloc; char *begin,*end,*cap; int w,h,c,d,e; };
extern "C" void func_00330FD8(char*,int,int,int,int) throw();
static inline void dimensions(Img *self,int c,int d){
 self->w=self->w*self->c/c;
 self->h=self->h*self->d/d;
 self->c=c;
 self->d=d;
}
extern "C" void func_00331608(Img *self){
 if(self->c==1 && self->d==1) return;
 for(int i=0;i<self->d;i++){
  int offset=i*self->c;
  int height=self->h;
  int pitch=self->w*self->e;
  func_00330FD8(self->begin+pitch*height*offset,pitch,height,self->c,0x10);
 }
 dimensions(self,1,1);
}
