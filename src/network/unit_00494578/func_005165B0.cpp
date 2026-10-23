struct Message0; typedef void (*Cb0)(Message0 *);
struct Message1; typedef void (*Cb1)(Message1 *);
struct Message2; typedef void (*Cb2)(Message2 *);
struct Message3; typedef void (*Cb3)(Message3 *);
struct Message4; typedef void (*Cb4)(Message4 *);
typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
struct N { char pad[12]; int state; u32 width,height; int pad18,ready,present; };
struct Obj { char pad[0x100]; N *node; int id; char p108[0x3c]; int valid; int p148; int connected; int count; int p154; int kind; char p15c[12]; Cb3 x168; void *x16c; Cb4 x170; void *x174; };
struct Packet; typedef void (*PacketCb)(Packet *);
struct Input { int valid; Obj *obj; char text[12]; u32 width,height; Cb0 x1c; PacketCb x20; void *x24; Cb1 x28; void *x2c; Cb2 x30; void *x34; Cb3 x38; void *x3c; Cb4 x40; void *x44; };
struct Work { char pad[8]; int maxWidth,width,maxHeight,height; char text[12]; };
struct Global { char pad[0x104]; int x104,x108,x10c,x110,x114; Obj *obj; Cb0 x11c; PacketCb x120; void *x124; Cb1 x128; void *x12c; Cb2 x130; void *x134; };
extern "C" {
extern Global D_00854038; extern Global *D_0064B4B4;
int func_00518B58(Obj*,int); void func_00518D28(Obj*); void func_00518E68(Obj*,int);
Work *func_0051B968(Obj*,u32); void func_005310D0(Obj*,u32);
u32 func_00531CA8(); int func_00532588(Obj*,int,int,int,void*);
int func_00534990(Obj*,int); void func_00535298(); N *func_00535C88(Obj*,u32);
int func_00536568(int); void func_005A6AB0(void*,void*,int) throw();
int func_005165B0(Input *in) {
 u8 message[4];
 int r=0x17;
 if(!in) return r;
 r=0x26; if(!in->valid) return r;
 Obj *o=in->obj;
 r=0x17; if(!o) return r;
 if(in->width>0x1000U) return r;
 if(in->height>0x200U) return r;
 Global *g=&D_00854038;
 r=0x10; if(g->obj) return r;
 r=15; if(o->kind==4) return r;
 r=0x17; if(o->valid!=1) return r;
 g->x124=in->x24;
 Global *global=D_0064B4B4;
 global->x128=in->x28;
 global->x12c=in->x2c;
 global->x114=0;
 global->x104=0;
 global->x130=in->x30;
 global->x134=in->x34;
 o->x168=in->x38;
 o->x16c=in->x3c;
 o->x170=in->x40;
 o->x174=in->x44;
 global->x11c=in->x1c;
 global->obj=o;
 g->x120=in->x20;
 Work *w=func_0051B968(o,o->id);
 r=0x16; if(!w) return r;
 int id=o->id;
 r=8; if(id==0x100) return r;
 N *p=o->node;
 r=0x17; if(!p) return r;
 int count=o->count;
 p->state=3;
 int i=0;
 if(count>0) do {
  p=func_00535C88(o,i);
  if(p && p->present && i!=id) p->state=0;
 } while(++i<o->count);
 w->maxWidth=0x1000;
 w->width=(u16)in->width;
 w->maxHeight=0x200;
 w->height=(u16)in->height;
 func_005A6AB0(w->text,in->text,11);
 w->text[11]=0;
 p=o->node;
 r=0x17; if(!p) return r;
 p->width=in->width;
 p->height=in->height;
 int sent=0;
 message[0]=3;
 message[1]=func_00536568(o->id);
 message[2]=(u8)in->width;
 message[3]=(u8)in->height;
 for(i=0;i<o->count;i++) {
  p=func_00535C88(o,i);
  if(p && p->present && i!=id) { sent++; func_00532588(o,i,21,4,message); }
 }
 p=o->node;
 r=0x17; if(!p) return r;
 if(!(sent | o->connected)) {
  p->state=5;
  p->ready=1;
  r=func_00518B58(o,id);
  if(r) return r;
  w->maxWidth=0;
  w->maxHeight=0;
  D_0064B4B4->x108=1;
  func_00534990(o,1);
  func_00518E68(o,id);
 }
 if(!D_00854038.x120) {
  u32 deadline=func_00531CA8()+30000;
  while(!D_0064B4B4->x10c) {
   func_00535298();
   if(deadline<func_00531CA8()) {
    goto timedout;
   }
  }
  return D_0064B4B4->x10c ? 0 : 7;
 }
 return 0;
timedout:
 p->state=2;
 func_005310D0(o,-1);
 func_00518D28(o);
 return 14;
}
}
