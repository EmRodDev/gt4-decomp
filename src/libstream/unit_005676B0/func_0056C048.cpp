/* compiler: ee-gcc2.96-no-strict-aliasing */
#define ALLOC(var,n,type) { scratch+=(16-scratch)&15; scratch+=(n)*sizeof(type); var=(type *)scratch-(n); }
struct Mode { char pad[32]; float gain; };
struct Sub {
 int a,b,c,double_codebook; int e;
 void (*lsp)(short *,int,void *);
 char pad[16];
 void (*innov)(int *,void *,int,void *,int);
 void *params;
 short k1,k2,k3;
};
struct Audio {
 Mode **mode; void *low; int n8,nC,n10,n14,n18,first;
 int n20,enh,scratch; int *lowout; int n30; int *high;
 void *p38,*p3C,*p40,*p44; int *exc;
 short *lsp,*old,*interp,*lpc; int *mem,*pi;
 int select; Sub **subs; int sub;
};
extern "C" int func_00567D30(void *,void *,short *);
extern "C" void func_00567D80(void *,int,void *);
extern "C" int func_00567C48(void *);
extern "C" int func_00567BE8(void *);
extern "C" int func_00567B38(void *,int);
extern "C" void func_00567F48(const char *);
extern "C" void func_0056BD48(Audio *,void *,int,int) throw();
extern "C" void func_0056BA50(void *,void *,void *,int) throw();
extern "C" void func_0056D698(short *,short *,short *,int,int,int);
extern "C" void func_0056D5D0(short *,int,int);
extern "C" void func_0056D3B0(short *,short *,int,int);
extern "C" void func_0056DD70(short,short *,short *,int);
extern "C" void func_0056DDE0(int *,int *,int,int);
extern "C" int func_0056DE38(int *,int);
extern "C" void func_0056DF58(int *,short *,short *,int *,int,int,int *);
extern "C" void func_0056E170(int *,short *,int *,int,int,int *);
extern "C" void func_0056E2C0(int *,void *,void *,int,int,void *,int);
extern "C" void *func_005A48D8(void *,int,unsigned);
extern "C" float func_0057D488(float);
extern char D_006CAE80[],D_006CAF00[],D_006CAF80[];
extern unsigned short D_006CAE60[];
static inline int peek(void *bits) { if(func_00567C48(bits)<=0) return 0; return func_00567BE8(bits); }
extern "C" int func_0056C048(Audio *h,void *bits,void *out) {
 int flag;
 int sub;
 int *lowpi,*lowexc,*lowinnov;
 short *ak1,*ak2,*ak3;
 Mode *mode;
 int scratch=h->scratch;
 int bytes=h->nC*2;
 scratch+=(-scratch)&15;
 scratch+=bytes;
 short *low=(short *)(scratch-bytes);
 mode=*h->mode;
 int ret=func_00567D30(h->low,bits,low);
 int i;
 for(i=0;i<h->nC;i++) h->lowout[i]=low[i]<<14;
 func_00567D80(h->low,0x67,&flag);
 if(ret) return ret;
 if(!bits) { func_0056BD48(h,out,flag,scratch); return 0; }
 if(h->select) {
  int wide=func_00567C48(bits)>0 ? func_00567BE8(bits) : 0;
  if(wide) { func_00567B38(bits,1); h->sub=func_00567B38(bits,3); }
  else h->sub=0;
  if(h->sub && !h->subs[h->sub]) {func_00567F48(D_006CAF80); return -2;}
 }
 if(!h->subs[h->sub]) {
  if(flag) {func_0056BD48(h,out,1,scratch);return 0;}
  for(i=0;i<h->nC;i++) h->exc[i]=0;
  h->first=1;
  func_0056E170(h->exc,h->lpc,h->high,h->nC,h->n18,h->mem);
  func_0056E2C0(h->lowout,D_006CAE80,h->p38,h->n8,64,h->p40,scratch);
  func_0056E2C0(h->high,D_006CAF00,h->p3C,h->n8,64,h->p44,scratch);
  func_0056BA50(h->p38,h->p3C,out,h->n8); return 0;
 }
 func_005A48D8(h->exc,0,h->nC*4);
 ALLOC(lowpi,h->n14,int);
 ALLOC(lowexc,h->nC,int);
 ALLOC(lowinnov,h->nC,int);
 func_00567D80(h->low,100,lowpi);
 func_00567D80(h->low,101,lowexc);
 func_00567D80(h->low,102,lowinnov);
 h->subs[h->sub]->lsp(h->lsp,h->n18,bits);
 if(h->first) for(i=0;i<h->n18;i++) h->old[i]=h->lsp[i];
 int bytes4=h->n18*2; int span=bytes4+2;
 scratch+=(16-scratch)&15; scratch+=span;
 ak1=(short *)(scratch-bytes4-2);
 scratch+=(16-scratch)&15; scratch+=span;
 ak2=(short *)(scratch-bytes4-2);
 scratch+=(16-scratch)&15; scratch+=span;
 ak3=(short *)(scratch-bytes4-2);
 for(sub=0;sub<h->n14;sub++) {
  int offset=h->n10*sub;
  int *sp=h->high+offset;
  int *exc=h->exc+offset;
  func_0056D698(h->old,h->lsp,h->interp,h->n18,sub,h->n14);
  func_0056D5D0(h->interp,h->n18,410);
  func_0056D3B0(h->interp,h->lpc,h->n18,scratch);
  if(h->enh) {
   short k1=h->subs[h->sub]->k1,k2=h->subs[h->sub]->k2,k3=h->subs[h->sub]->k3;
   func_0056DD70(k1,h->lpc,ak1,h->n18);
   func_0056DD70(k2,h->lpc,ak2,h->n18);
   func_0056DD70(k3,h->lpc,ak3,h->n18);
  }
  h->pi[sub]=8192;
  int rh=8192;
  for(i=1;i<=h->n18;i+=2) {
   int b=h->lpc[i+1],a=h->lpc[i];
   rh+=b-a;
   h->pi[sub]+=a+b;
  }
  short ratio=(short)(((lowpi[sub]+82)<<2)/(short)((rh+82)>>5));
  func_005A48D8(exc,0,h->n10*4);
  if(!h->subs[h->sub]->innov) {
   int q=func_00567B38(bits,5);
   float g=func_0057D488((q-10.0f)*0.125f)/(ratio*0.0078125f);
   for(i=0;i<h->n10;i++) exc[i]=(int)(mode->gain*g*lowinnov[offset+i]);
  } else {
   int q=func_00567B38(bits,4);
   int ener=func_0056DE38(lowexc+offset,h->n10);
   unsigned short x=D_006CAE60[q];
   short g=(short)((((short)x)>>15)*28626+(((x&32767)*28626)>>15));
   if(h->n10==80) g=(short)(g*0x1.6a0902p+0f);
   short g2=(short)((g<<10)/ratio);
   int gain=(g2*(ener+1))<<4;
   h->subs[h->sub]->innov(exc,h->subs[h->sub]->params,h->n10,bits,scratch);
   func_0056DDE0(exc,exc,gain,h->n10);
   if(h->subs[h->sub]->double_codebook) {
    int s=scratch;
    int n=h->n10*4;
    s+=(-s)&15;s+=n;
    int *innov=(int *)(s-n);
    func_005A48D8(innov,0,n);
    h->subs[h->sub]->innov(innov,h->subs[h->sub]->params,h->n10,bits,s);
    for(i=0;i<h->n10;i++) innov[i]=(int)(innov[i]*(gain*0.00006103515625f*0.4f));
    for(i=0;i<h->n10;i++) exc[i]+=innov[i];
   }
  }
  for(i=0;i<h->n10;i++) sp[i]=exc[i];
  if(h->enh) {
   func_0056DF58(sp,ak2,ak1,sp,h->n10,h->n18,h->mem+h->n18);
   func_0056DF58(sp,ak3,h->lpc,sp,h->n10,h->n18,h->mem);
  } else {
   func_005A48D8((void *)(h->n18*4+(int)h->mem),0,h->n18*4);
   func_0056E170(sp,h->lpc,sp,h->n10,h->n18,h->mem);
  }
 }
 func_0056E2C0(h->lowout,D_006CAE80,h->p38,h->n8,64,h->p40,scratch);
 func_0056E2C0(h->high,D_006CAF00,h->p3C,h->n8,64,h->p44,scratch);
 func_0056BA50(h->p38,h->p3C,out,h->n8);
 for(i=0;i<h->n18;i++) h->old[i]=h->lsp[i];
 h->first=0;
 return 0;
}
