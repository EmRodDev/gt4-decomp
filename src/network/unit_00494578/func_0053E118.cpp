struct Conn {
 void *session; int handle; unsigned int kind; char pC[0x2044]; int arg;
 char p2054[0x28]; char request[0x800];
};
struct Self { char p[0x3c]; int state; int pad40; Conn *conn; int arg; };
struct Address { double value; char pad[8]; };
struct Params { int one,size,other; };
struct Iface {
 char p[0x14]; int (*open)(Conn *,double,int,Params *);
 void (*close)(void *);
 int (*write)(void *,char *,int,int *);
 int (*send)(void *,double,int,char *,int,int *);
 char q[0x48]; void (*init)(void *);
 char r[0x10]; void (*resolve)(void *,const char *);
};
extern Iface *D_0064B4B0;
extern int D_0064C114;
extern char D_006C4298[],D_006C42E8[],D_006C3C60[],D_006C3C90[],D_006C3CC8[],D_006C3CF8[];
extern "C" int func_0057F260(const char *) throw();
extern "C" void *func_005A48D8(void *,int,unsigned int);
extern "C" void func_0057DA20(char *,const char *,...);
extern "C" int func_0053EF68(Self *);
extern "C" int func_0053A878(void *) throw();
extern "C" int func_0053E118(Self *self,unsigned int kind,int arg) {
 Params params;
 Address address;
 Address initial;
 double initialValue;
 int written=0;
 if(!self) return 2;
 if(self->state) return 0xd6da;
 if(!arg) return 2;
 int r=func_0053EF68(self);
 if(r) return r;
 if(D_0064C114) goto success;
 func_005A48D8((char *)self->conn+0x18,0,0x100c);
 switch(kind) {
 case 0x20: func_0057DA20(self->conn->request,D_006C4298,D_006C42E8,0x76c,D_006C3C60); break;
 case 0x40: func_0057DA20(self->conn->request,D_006C4298,D_006C42E8,0x76c,D_006C3C90); break;
 case 0x1000: func_0057DA20(self->conn->request,D_006C4298,D_006C42E8,0x76c,D_006C3CC8); break;
 case 0x800: func_0057DA20(self->conn->request,D_006C4298,D_006C42E8,0x76c,D_006C3CF8); break;
 default: return 2;
 }
 func_005A48D8(&params,0,12);
 params.one=1;
 params.size=0x800;
 D_0064B4B0->init(&initial);
 initialValue=initial.value;
 r=D_0064B4B0->open(self->conn,initialValue,0x76c,&params);
 if(r) return r;
 D_0064B4B0->resolve(&address,D_006C42E8);
 {
 int n=func_0057F260(self->conn->request);
 r=D_0064B4B0->send(self->conn->session,address.value,0x76c,self->conn->request,n,&written);
 }
 if(r==0) {
  if(func_0057F260(self->conn->request)==written) goto success;
 }
 D_0064B4B0->close(self->conn->session);
 return r;
success:
 Conn *c=self->conn;
 self->state=1;
 func_0053A878((char *)c+0x10);
 self->conn->arg=arg;
 self->conn->kind=kind;
 return 0;
}
