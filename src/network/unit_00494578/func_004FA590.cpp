/* compiler: ee-gcc2.96-nsa-nogcse */
struct A {int w[21];};
struct B {int state; signed char x,y; char pad[222];};
struct Ent {int id,kind,type,pad;};
struct List {Ent a[32]; int n;};
struct Handle {char pad[28];void *p;};
struct Obj {char p0[0x154];int mode;char p1[0xcc0-0x158];int cc0,cc4,cc8,ccc,cd0,cd4;List list;char p2[0x88]; A a;int active,unused,fc0,fc4,fc8,fcc,fd0,fd4,fd8;char p3[0x2240-0xfdc];int flags[16];B b[16];};
extern "C" {
int func_004F68C8(Obj *);
void func_004F9CE8(Obj *) throw();
int func_004F9E60(Obj *,int) throw();
int func_004FB1E8(Obj *);
int func_00515998(Handle **,int);
void func_00576100(Obj *);
void func_00576140(Obj *);
}
void func_004FA590(Obj *o) {
 Handle *h;
 int host; B *own; int active,allx,ally,allfour; unsigned any;
 if(o->active) {
 host=func_004F68C8(o);
 if(!host) {
 h=0;
 if(!func_00515998(&h,o->cc0)&&h) {
 A *p=(A *)h->p;
 if(p) {int old=o->a.w[1];o->a=*p;if((old^o->a.w[1])<0)func_004F9CE8(o);}
 }
 }
 List *list=&o->list;
 allx=1;
 int kind=func_004F9E60(o,o->cc4);
 active=o->fc0;
 ally=1; allfour=0; any=0;
 own=(B *)((char *)o+kind*0xe4+0x2280); int lo=6, i=0, hi=0;
 if(list->n>0) {
 Ent *e=list->a;
 do {
 int type=e->type; int k=e->kind; int id=e->id;
 if(type==o->cd0) {
 B *b=(B *)((char *)o+k*0xe4+0x2280);
 if(kind!=k) {
 h=0;
 if(func_00515998(&h,id)||!h||!h->p)goto next;
 func_00576100(o);
 if(!o->flags[k])*b=*(B *)h->p;
 func_00576140(o);
 }
 if(active) {if(!b->x)allx=0;if(!b->y)ally=0;}
 int state=b->state;
 lo=lo<state?lo:state;
 hi=state<hi?hi:state;
 if(state!=4)allfour=0;
 any=1;
 }
 next:
 e++;i++;
 }while(i<list->n);
 }
 if(!any){lo=0;hi=0;}
 func_00576100(o);
 if(active && o->fc0) {
 if(allx)own->y=1;
 if(ally){o->fc0=0;o->fc4=2;own->x=0;}
 }
 func_00576140(o);
 if(allfour){int t=func_004FB1E8(o);int v=o->a.w[0];if(!v){if(host)o->a.w[0]=t+(o->mode?100:2000);}else o->fd8=v;}
 o->fc8=lo;o->fcc=hi;
 }
}
