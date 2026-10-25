/* compiler: ee-gcc2.96-as2004 */
typedef unsigned int u32;
typedef unsigned long long Addr __attribute__((aligned(4)));
struct Peer { Addr addr; int x8,kind,x10,x14; unsigned short x18; short pad; int x1c,active,x24; bool informed; };
struct Session { int a,b,c,state,x10,x14; };
struct Packet { unsigned char kind,id,a,b; unsigned short port; short pad; int x8,xC; };
struct Context;
struct Info { int ctx,id,name,kind,xC,user; };
struct Context { char pad0[0x100]; Session *session; int index; char pad108[0x134-0x108]; void (*onPeer)(Info *); int user; };
struct Util { char pad0[0x7c]; int (*format)(char *,Addr); };
struct Api { char pad0[0x44]; int (*f44)(Context *,int); char pad48[0x98-0x48]; int (*f98)(Context *,int,int,int); char pad9c[0xac-0x9c]; int (*fac)(Context *,int,int,int); };
extern Api *D_0064B4B4;
extern Util *D_0064B4B0;
extern "C" Peer *func_00535C88(Context *,u32) throw();
extern "C" int func_00536568(int) throw() __attribute__((const));
extern "C" int func_00532588(Context *,int,int,int,void *) throw();
extern "C" void *func_005A48D8(void *,int,u32);
extern "C" int func_00537770(Context *ctx,int unused,u32 len,Packet *p) {
 char name[16]; Info info; unsigned char msg[4];
 if(!ctx) return 16;
 if(len>=64) return 16;
 Peer *peer=func_00535C88(ctx,p->id);
 if(!peer) return -1;
 if(!peer->active) return 16;
 Session *sess=ctx->session;
 if(!sess) return 16;
 int kind=p->kind;
 peer->kind=kind;
 peer->x10=p->a;
 peer->x14=p->b;
 peer->x18=p->port;
 if(kind==5) D_0064B4B4->f44(ctx,p->id);
 int state;
 if(ctx->onPeer && !peer->informed) {
  D_0064B4B0->format(name,peer->addr);
  func_005A48D8(&info,0,24);
  int id=p->id;
  int xC=p->xC;
  int user=ctx->user;
  int peerKind=peer->kind;
  info.id=id;
  info.user=user;
  info.xC=xC;
  info.kind=peerKind;
  info.ctx=(int)ctx;
  info.name=(int)name;
  ctx->onPeer(&info);
  peer->informed=true;
  state=sess->state;
  if(state==3) {
   int index=ctx->index;
   peer->kind=0;
   msg[0]=state;
   msg[1]=func_00536568(index);
   msg[2]=sess->x10;
   msg[3]=sess->x14;
   func_00532588(ctx,p->id,21,4,msg);
   return 16;
  }
 } else state=sess->state;
 if(p->x8) peer->x1c=p->x8;
 switch(state) {
 case 3: D_0064B4B4->f98(ctx,p->id,p->a,p->b); break;
 case 5: if(p->kind==3) D_0064B4B4->fac(ctx,p->id,p->a,p->b); break;
 case 0: break;
 case 1: break;
 case 2: break;
 case 4: break;
 default: break;
 }
 return 16;
}
