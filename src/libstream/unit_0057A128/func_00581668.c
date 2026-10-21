/* compiler: ee-gcc2.9-as296 */
extern volatile int D_00655EF8,D_00655F20,D_00655EF4;
extern int D_00655ED0,D_00657080;
extern volatile int D_00655EE8;
extern char D_00657090[];
extern char D_006CE200[];
extern char D_006CE218[];
extern char D_006CE230[];
extern char D_006CE260[];
extern char D_006CE278[];
struct Packet { unsigned tag[195]; unsigned char a,b,c,d; void *p; };
extern struct Packet D_00655FC0;
int func_00580928(void);
int func_005807D0(int);
void func_005B0750(const char *,...);
void func_005B0F78(void *,int);
void func_005ADCC0(int);
void func_0057FF10(void);
int func_005B19B0(void *,int,int,void *,int,void *,int,void *,void *);
int func_00581668(unsigned *tag,unsigned char *mode) {
 struct Packet *p=&D_00655FC0;
 int i,n,size;
 if(!(D_00655EF8&1) && func_00580928()==6) return 0;
 if(!func_005807D0(3)) return 0;
 if(D_00655ED0>0) func_005B0750(D_006CE200);
 for(i=0; i<192 && *tag!=0xFFFFFFFF; i++) p->tag[i]=*tag++;
 n=(i/3)*3;
 p->tag[n]=0xFFFFFFFF;
 p->tag[n+1]=0xFFFFFFFF;
 p->tag[n+2]=0xFFFFFFFF;
 p->a=mode[0]; p->b=mode[1]; p->c=mode[2]; p->p=&D_00657080;
 switch(mode[2]) { case 0:size=0x800;break; case 1:size=0x918;break; case 2:size=0x924;break; default:size=0x800;break; }
 D_00657080=0;
 if(D_00655ED0>0) func_005B0750(D_006CE218);
 for(i=1; i<n && !(D_00655EF8&2); i+=3) {
  if(!(p->tag[i+1]&1)) {
   if(D_00655ED0>0) func_005B0750(D_006CE230,p->tag[i+1],p->tag[i]*size);
   func_005B0F78((void *)p->tag[i+1],p->tag[i]*size);
  }
 }
 func_005B0F78(p,24); func_005B0F78(&D_00657080,4);
 if(D_00655ED0>0) func_005B0750(D_006CE260);
 D_00655F20=1;D_00655EF4=1;
 if(func_005B19B0(D_00657090,15,1,p,0x314,0,0,func_0057FF10,&D_00655F20)<0) {
  D_00655F20=0;D_00655EF4=0;func_005ADCC0(D_00655EE8); return 0;
 }
 if(D_00655ED0>0) func_005B0750(D_006CE278);
 return 1;
}
