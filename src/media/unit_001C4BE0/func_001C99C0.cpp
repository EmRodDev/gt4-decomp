/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Image { int f0; char *data; int f8,fc,width,height,nx,ny,stride; };
struct Obj { Image *img; };
extern "C" void *func_005A4724(void *,const void *,unsigned int);
extern "C" void func_005A48D8(void *,int,unsigned int);
extern "C" void func_001C99C0(Obj *self,char *dst,int index) {
 if(index<0 || index>=self->img->height*self->img->ny)
  return func_005A48D8(dst,255,self->img->width*self->img->nx*3);
 Image *p=self->img;
 int h=p->height;
  int width=p->width;
  int row=index/h;
  index%=h;
  int i=0;
  if(p->nx>0) {
   int len=width*3;
   do {
    int pitch=self->img->width*self->img->stride;
    char *src=self->img->data+pitch*self->img->height*(row*self->img->nx+i);
    func_005A4724(dst,(char *)(pitch*index+(int)src),len);
    dst+=len;
    i++;
   } while(i<self->img->nx);
  }

}
