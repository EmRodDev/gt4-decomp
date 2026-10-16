/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Image { int a; char *data; int b,c; int w,h,cols,rows,stride; float aspect; };
struct Self { char pad[0x1e634]; int busy; char pad2[0x18]; Image *image; };
struct G { char pad[0x38cc4]; int flag; }; extern G *D_00622F4C;
extern "C" int func_004997B0(int,int,int,void*);
extern "C" void func_004A1638(unsigned int);
extern "C" void func_004A2808(signed char,float);
extern "C" void func_004A4550(int,int);
extern "C" void func_004A4810(int,unsigned int,unsigned int);
extern "C" void func_004A6668(float,float,float,float,float,float,float,float);
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" void func_004AB040(unsigned int);
static inline int offset(int w,int stride,int h,int i) { int n=w*stride; n*=h; n*=i; return n; }
extern "C" void func_003C7108(Self *s,float width,float height) {
 Image *im=s->image;
 if(im && s->busy==0) {
 int flag=D_00622F4C->flag;
 if(flag) width/=0.75f;
 float ratio=width/height;
 float aspect=im->aspect;
 int iw=im->w;
 int ih=im->h;
 float w=width;
 float h=height;
 if(ratio<aspect) h=w/aspect; else w=aspect*h;
 float x=(width-w)*0.5f;
 float y=(height-h)*0.5f;
 h*=0.933333333f;
 y*=0.933333333f;
 if(flag) { w*=0.75f;x*=0.75f; }
 func_004A4550(4,2);
 float one=1.0f;
 func_004A4550(5,2);
 func_004A4810(0,0,iw-1);func_004A4810(1,0,ih-1);
 int i=0;
 func_004A4550(3,1);func_004A4550(2,1);
 func_004AA1D8(one,one,one,one);
 func_004AB040(5);func_004AB040(4);func_004A1638(6);
 int n=s->image->cols*s->image->rows;
 for(;i<n;i++) {
 func_004A2808(100,1.0f/(float)(i+1));
 Image *p=s->image;
 func_004997B0(1,iw,ih,p->data+offset(p->w,p->stride,p->h,i));
 func_004A6668(x,y,x+w,y+h,0.0f,0.0f,(float)iw,(float)ih);
 }
 }
}
