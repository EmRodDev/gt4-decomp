/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;
typedef float f32;
#define NULL 0
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern "C" {
void func_0022F178(void *, void *);
void func_00243470(void *, int);
void mTextFace__structor_0(void *);
void func_00248BF0(void *, int);
void func_00248FF8(void *);
void mToolTipFace__setKey(void *, void *);
void *func_00255088(void *, void *);
void func_002550B8(void *, int);
void *func_002556B0(void *);
float mWidget__getWindowH(void *);
void mWidget__getWindowSize(void *, void *, void *);
void func_0025B500(void *, void *, void *, void *, void *);
void func_0025BA68(void *, float, float);
void func_0025BAA0(void *, float *, float *, float *, float *);
void func_0025BAD8(void *, float, float, float, float) throw();
void func_00265E50(void *, int);
void func_00266830(void *, int);
void func_002A0D20(void *, int);
void *func_002A1120(void *);
void func_003069F8(void *, void *, void *);
void *HSymID__GetID(void *);
void *func_00326750(unsigned, int, const char *);
void func_00326798(void *, int, int, const char *);
const char **func_005C11A8();
char *func_005C2560(void *);
int func_0057F260(const char *) throw();
void *func_005C2630(void *, unsigned, unsigned, const char *, unsigned);
void func_005DB110(const char *, ...);
}
extern char D_0069C5B0[], D_0069C620[], D_0069C628[], D_0069C5A0[], D_0069C630[], D_0069C638[], D_0069C640[], D_0069C648[], D_0069C600[];

typedef unsigned u32;
struct Rep { u32 len, res, ref, selfish;
 char *data() { return (char *)(this+1); }
 char *grab() { if(selfish) return func_005C2560(this); ++ref; return data(); }
 static void operator delete(void *p,u32 n) {func_00326798(p,n,4,*func_005C11A8());}
 void release() {if(--ref==0) operator delete(this,sizeof(Rep)+res);}
};
extern Rep D_00659FA8;
struct String {char *dat; char pad[12];
 String(const char *s):dat(D_00659FA8.grab()) {assign(s);}
 String(const String &);
 void assign(const char *s,unsigned n) {func_005C2630(this,0,-1,s,n);}
 void assign(const char *s) {assign(s,func_0057F260(s));}
 ~String() {((Rep *)dat-1)->release();}
};

struct Slot {void *p; char pad[12];};
static inline bool isNull(Slot *s) {return s->p==0;}
static inline void construct(String *const s,const char *t) {s->dat=D_00659FA8.grab();s->assign(t);}
static inline void destroy(String *const s) {((Rep *)s->dat-1)->release();}
static inline void newtext(void **const p) {void *v=func_00326750(0x120,4,D_0069C5A0);mTextFace__structor_0(v);*p=v;}
struct Obj {char pad[8]; void *owner,*wnd,*keyboard,*normal,*active,*text; float x,y,w,h; int a30,a34,rows,a3c,cols; char p44[20]; float r58,r5c,r60,r64;};
extern "C" int mOSKeyboard__open(Obj *o,void *owner,void *wnd,float x,float y,float unused,float height) {
 Slot keyboard,face; char sb20[16]; Slot text; char sb40[16],sb50[16]; Slot tooltip;char sb70[16]; Slot tip;char sb90[16];Slot sym;char sbB0[16];
 float left,top,width,wh; void *alloc;
 if(o->owner==0 && owner!=0) {
 o->wnd=wnd;
 void *root=*(void **)((char *)owner+0x1d08);
 func_002556B0(&keyboard);
 {String *s=(String *)sb20;construct(s,D_0069C5B0);face.p=HSymID__GetID(s);func_003069F8(root,&keyboard,&face);destroy(s);}
 if(keyboard.p==0) {func_005DB110(D_0069C600);func_002550B8(&keyboard,2);return 0;}
 o->keyboard=keyboard.p;
 func_002A1120(&face);
 Slot *pt=&text;
 {String *s=(String *)sb40;construct(s,D_0069C620);pt->p=HSymID__GetID(s);func_003069F8(o->keyboard,&face,pt);destroy(s);}
 o->normal=face.p;
 {String *s=(String *)sb50;construct(s,D_0069C628);pt->p=HSymID__GetID(s);func_003069F8(o->keyboard,&face,pt);destroy(s);}
 o->active=face.p;
 void **pa=&alloc;void *v=func_00326750(0x120,4,D_0069C5A0);mTextFace__structor_0(v);alloc=v;func_00255088(pt,pa);
 Slot *ph=&tooltip;
 {String *s=(String *)sb70;construct(s,D_0069C630);ph->p=HSymID__GetID(s);func_003069F8(o->keyboard,pt,ph);destroy(s);}
 o->text=pt->p;
 func_002556B0(ph);
 float tipheight=0.0f;
 Slot *pti=&tip;
 {String *s=(String *)sb90;construct(s,D_0069C638);pti->p=HSymID__GetID(s);func_003069F8(o->keyboard,ph,pti);destroy(s);}
 if(!isNull(ph)) {
 tipheight=mWidget__getWindowH(ph->p);
 func_00248FF8(pti);
 void *parent=ph->p;
 Slot *psym=&sym;
 {String *s=(String *)sbB0;construct(s,D_0069C640);psym->p=HSymID__GetID(s);func_003069F8(parent,pti,psym);destroy(s);}
 void *tipobj=pti->p;
 {String *s=(String *)psym;construct(s,D_0069C648);mToolTipFace__setKey(tipobj,s);destroy(s);}
 func_00248BF0(pti,2);
 }
 func_0025BAA0(wnd,&left,&top,&width,&wh);
 mWidget__getWindowSize(o->active,&o->w,&o->h);
 func_0025B500(o->text,&o->r58,&o->r5c,&o->r60,&o->r64);
 float fw=o->w*o->cols,fh=o->h*o->rows;
 if(width<x+fw) x=width-fw;
 if(y+height+10.0f+fh>top+wh-tipheight) y-=fh+10.0f;
 else y+=height+10.0f;
 func_00266830(o->keyboard,0);
 func_0025BA68(o->keyboard,x,y);
 o->x=x; o->y=y;
 func_00265E50(o->active,0);func_00265E50(o->normal,0);func_00265E50(o->text,0);
 if(!isNull(ph)) func_0025BAD8(ph->p,left,top+wh-tipheight,width,tipheight);
 o->owner=owner;func_0022F178(owner,o->active);
 func_002550B8(ph,2);func_00243470(pt,2);func_002A0D20(&face,2);func_002550B8(&keyboard,2);
 return 1;
 }
 return 0;
}
