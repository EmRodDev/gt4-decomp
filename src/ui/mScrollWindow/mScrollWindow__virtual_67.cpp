struct Rep { int len,cap,ref,sel; };
struct Str { char *p; char pad[12]; };
struct Info { const char *name; };
struct Obj { char pad[0xbc]; void *clip,*space; char bars[0x70]; };
extern Rep D_00659FA8;
extern char D_0069CB10[],D_0069CB18[],D_0069CB20[],D_0069CB28[];
extern "C" void mTextFace__virtual_67();
extern "C" void *func_0030BB18(void *);
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005C2630(Str *,int,int,const char *,int);
extern "C" int HSymID__GetID(Str *);
extern "C" void func_003069F8(void *,void *,void *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
extern "C" void *func_00204D88(void *,void *);
extern "C" void func_00204D30(void *,int);
extern "C" void func_00309378(void *,int);
extern "C" void func_00266438(void *,int);
extern "C" void func_002D1B78(void *,int,void *) throw();
extern "C" void func_002D2020(void *,void *) throw();
extern "C" void mScrollWindow__virtual_67(Obj *o,int arg) {
 int handle[4],name[4]; Str a,b,c,d;
 mTextFace__virtual_67(); func_0030BB18(handle);
 int *pn=name;
 {
 const char *src=D_0069CB10;
 Rep *r=&D_00659FA8;
 Str *ps=&a;
 char *p;
 if(r->sel) p=func_005C2560(r);
 else {p=(char *)(r+1); r->ref++;}
 ps->p=p;
 func_005C2630(ps,0,-1,src,func_0057F260(src));
 pn[0]=HSymID__GetID(ps);
 func_003069F8(o,handle,pn);
 Rep *q=(Rep *)(ps->p-16);
 if(--q->ref==0) {int size=q->cap+16;func_00326798(q,size,4,func_005C11A8()->name);}
 if(__builtin_expect(handle[0],0)) {func_00204D88(pn,handle); o->clip=(void *)pn[0];func_00204D30(pn,2);} else o->clip=0;
 }
 o->space=0;
 if(o->clip) {
 {
 const char *src=D_0069CB18;
 Rep *r=&D_00659FA8;
 Str *ps=&b;
 char *p;
 if(r->sel) p=func_005C2560(r);
 else {p=(char *)(r+1); r->ref++;}
 ps->p=p;
 func_005C2630(ps,0,-1,src,func_0057F260(src));
 pn[0]=HSymID__GetID(ps);
 func_003069F8(o->clip,handle,pn);
 Rep *q=(Rep *)(ps->p-16);
 if(--q->ref==0) {int size=q->cap+16;func_00326798(q,size,4,func_005C11A8()->name);}
 if(__builtin_expect(handle[0],0)) {func_00204D88(pn,handle); o->space=(void *)pn[0];func_00204D30(pn,2);}
 }
 }
 if(o->space) func_00266438(o->space,1);
 void *hbar;
 {
 const char *src=D_0069CB20;
 Rep *r=&D_00659FA8;
 Str *ps=&c;
 char *p;
 if(r->sel) p=func_005C2560(r);
 else {p=(char *)(r+1); r->ref++;}
 ps->p=p;
 func_005C2630(ps,0,-1,src,func_0057F260(src));
 pn[0]=HSymID__GetID(ps);
 func_003069F8(o,handle,pn);
 Rep *q=(Rep *)(ps->p-16);
 if(--q->ref==0) {int size=q->cap+16;func_00326798(q,size,4,func_005C11A8()->name);}
 if(__builtin_expect(handle[0],0)) {func_00204D88(pn,handle); hbar=(void *)pn[0];func_00204D30(pn,2);} else hbar=0;
 }
 void *vbar;
 {
 const char *src=D_0069CB28;
 Rep *r=&D_00659FA8;
 Str *ps=&d;
 char *p;
 if(r->sel) p=func_005C2560(r);
 else {p=(char *)(r+1); r->ref++;}
 ps->p=p;
 func_005C2630(ps,0,-1,src,func_0057F260(src));
 pn[0]=HSymID__GetID(ps);
 func_003069F8(o,handle,pn);
 Rep *q=(Rep *)(ps->p-16);
 if(--q->ref==0) {int size=q->cap+16;func_00326798(q,size,4,func_005C11A8()->name);}
 if(__builtin_expect(handle[0],0)) {func_00204D88(pn,handle); vbar=(void *)pn[0];func_00204D30(pn,2);} else vbar=0;
 }
  
 func_00309378(handle,2);
 func_002D1B78(o->bars,arg,hbar);func_002D1B78((o->bars+0x38),arg,vbar);
 func_002D2020(o->bars,o);func_002D2020((o->bars+0x38),o);
}
