/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
 char b0; unsigned char fx,fy; char b3;
 short x,y,w,h;
 float alpha; int p10; char *vt;
 unsigned int color,color2;
 char pad20[4]; float unitwidth;
 char pad28[0x46-0x28]; char unit[0x68-0x46];
 float speed,width;
};
struct Font { int a,mode; };
extern Font D_00623838;
extern char D_006A1460[];
extern int PDISTD__UNIT_MANAGER[];
extern "C" int func_003AFD78(int,int,int);
extern "C" void func_003B0230(char *,float);
extern "C" void func_0044D920(Font *,const char *);
extern "C" void func_0044D988(Font *);
extern "C" float func_0044DC30(Font *);
extern "C" void func_0044DDF8(Font *,float,float,float);
extern "C" void func_0044DE80(Font *,unsigned int);
extern "C" float func_0044DFC8(Font *,const char *);
extern "C" void func_0044E030(Font *,const char *);
extern "C" void func_0044E088(Font *,const char *,...);
extern "C" char *func_00472680(int *);
extern "C" float func_00472940(int *,float);
static inline float maxf(float a,float b) {float r; __asm__("max.s %0, %1, %2":"=f"(r):"f"(a),"f"(b)); return r;}
extern "C" void RaceSpeedDisplay__render_main(Obj *o) {
 char buf[32];
 float zero=0.0f;
 Font *g=&D_00623838;
 func_0044DE80(g,o->color);
 g->mode=2;
 float x=(float)func_003AFD78(o->x,0,o->fx);
 float y=(float)o->y;
 func_0044DDF8(g,x,y,zero);
 const char *font=D_006A1460;
 func_0044D920(g,font);
 int *conv=PDISTD__UNIT_MANAGER;
 const char *text=func_00472680(conv);
 func_0044E088(g,text);
 float inv=1.0f/func_0044DC30(g);
 if(o->width==zero) o->width=func_0044DFC8(g,text)*inv;
 func_0044D920(g,font);
 func_003B0230(buf,func_00472940(conv,o->speed));
 func_0044DDF8(g,x-o->width,y,zero);
 func_0044E088(g,buf);
 float extent=maxf(o->width+func_0044DFC8(g,buf)*inv,90.0f)+10.0f;
 func_0044D920(g,font);
 if(o->unitwidth==zero) { text=o->unit; o->unitwidth=func_0044DFC8(g,text)*inv; }
 else text=o->unit;
 func_0044DDF8(g,x-extent-o->unitwidth,y,0.0f);
 func_0044DE80(g,o->color2);
 func_0044E030(g,text);
 g->mode=0;
 func_0044D988(g);
}
