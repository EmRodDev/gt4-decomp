struct Block { int words[19]; };
struct Config { int version, id; Block block; int *name, *key; int val5c,val60,val64,val68,val6c,val70,val74; };
enum Error { ERR_OK = 0, ERR_12 = 0x12, ERR_17 = 0x17, ERR_26 = 0x26 };
struct Result { int state; Error error; char data[1]; };
struct Settings { int id; Block block; char pad50[0x1c]; int a,b; };
struct Api {
 char pad[0x4c]; int (*init)(); char pad50[0xa4]; int f4,f8,fc,f100,f104;
 char pad108[0x30]; char b138[0x40],b178[0x40],b1b8[0x40];
 char pad1f8[0xa440]; char buf[0x4000]; int e638;
};
struct Client { char pad[0x184]; char key[0x80]; };
struct Message { char pad[0xc]; int (*startup)(int *); };
struct Entry { char pad[0x10]; int active; char tail[0xc]; };
enum Mode { MODE_0, MODE_1, MODE_2 };
struct Status { int state,unk4,unk8,a; Mode c; int unk14,unk18,b; };
extern Settings *D_0064B47C;
extern Api *D_0064B4B4;
extern Client *D_0064B70C;
extern void *D_0064B710;
extern Message *D_0064B4A8;
extern int D_0064B4FC,D_0064B4EC,D_0064B4D8,D_0064B4DC,D_0064B4F8,D_0064B4B8;
extern char D_008686B8[],D_008686C8[],D_0086A848[],D_008687E0[],D_00868848[];
extern Status D_00868698;
extern Entry D_008A05B0[127];
extern "C" int func_0052E4A8(void *) throw();
extern "C" void func_00530600(int,int) throw();
extern "C" void func_005316E8(int) throw();
extern "C" int func_00532D98();
extern "C" int func_00537998();
extern "C" int func_00537F28();
extern "C" void func_00539670(int);
extern "C" int func_00539FD8(int,int,int,int);
extern "C" void func_0053A860(int *);
extern "C" int func_0057D9C0(const char *,...);
extern "C" void *func_005A4724(void *,const void *,unsigned);
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" int func_005328D0(Config *cfg,Result *out) {
 int time;
 if(!out) return 0x17;
 if(cfg->id==-1) return 0x17;
 func_0053A860(&time);
 func_00539670(time);
 out->error=ERR_12;
 out->state=1;
 func_0052E4A8(out->data);
 if(!cfg) { out->error=ERR_17; return 0x17; }
 else if(cfg->version!=1) { out->error=ERR_26; return 0x17; }
 func_005A48D8(D_008686B8,0,0x10);
 func_005A48D8(D_008686C8,0,0x100);
 D_0064B47C->id=cfg->id;
 D_0064B47C->block=cfg->block;
 func_00530600(cfg->val68,cfg->val6c);
 func_005316E8(0);
 if(func_00539FD8(0x600,0x100,6,0)) return 0x1e;
 for(int i=126;i>=0;i--) D_008A05B0[i].active=0;
 if(D_0064B4B4) {
  D_0064B4B4->f8=0;
  D_0064B4B4->f4=0;
  D_0064B4B4->fc=1;
  D_0064B4B4->f100=0;
  D_0064B4B4->f104=0;
  func_005A48D8(D_0064B4B4->buf,0,0x4000);
  D_0064B4B4->e638=0;
  func_005A48D8(D_0064B4B4->b138,0,0x40);
  func_005A48D8(D_0064B4B4->b178,0,0x40);
  func_005A48D8(D_0064B4B4->b1b8,0,0x40);
 }
 func_00537998();
 if(D_0064B4B4) D_0064B4B4->init();
 int r=func_00537F28();
 if(r) return r;
 func_005A48D8(D_0086A848,0,0x80);
 func_005A48D8(D_0064B70C->key,0,0x80);
 D_0064B4FC=0;
 if(cfg->name && *cfg->name) {
  if(D_0064B710 && cfg->key && *cfg->key) {
   func_005A4724(D_0086A848,cfg->name,0x80);
   func_005A4724(D_0064B70C->key,cfg->key,0x80);
   D_0064B4FC=1;
  } else { out->error=ERR_12; return 0x12; }
 }
 if(D_0064B4A8) {
  int r=D_0064B4A8->startup(cfg->name);
  if(r) {
   func_0057D9C0("msg client startup failed, msg error code = %d\n",r);
   out->error=ERR_12; return 0x12;
  }
 }
 func_005A48D8(&D_00868698,0,0x20);
 D_00868698.b=D_0064B47C->a=cfg->val5c;
 out->error=ERR_OK;
 D_00868698.a=D_0064B47C->a;
 D_00868698.c=MODE_2;
 D_00868698.state=1;
 func_005A48D8(D_008687E0,0,0x38);
 func_005A48D8(D_00868848,0,0x2000);
 D_0064B4EC=0;
 D_0064B4D8=cfg->val70;
 D_0064B4DC=cfg->val74;
 D_0064B47C->b=cfg->val60;
 D_0064B4F8=cfg->val64;
 if(D_0064B4B8) { int r=func_00532D98(); if(r) return r; }
 return 0;
}
