/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub { u8 x,len; short z,amount; char pad[6]; };
struct Rec { u32 flags; char pad[6]; u8 code; char pad2[3]; signed char state; char pad3; Sub sub; };
struct Work { Rec entries[42]; u8 count,len; short pad; int total; Rec *ptrs[42]; u16 selected; short pad2; void *allocation; u16 zero; };
struct Snapshot { u32 sequence; char data[0xE8]; };
struct History { int index,count; Snapshot entries[1]; };
struct Ctx { char p[12]; u32 *sequence; char p2[24]; u16 *text; int *state; Work *work; void *backup; int *other; char p3[4]; History *history; };
extern Ctx *D_006452D4;
extern "C" {
int func_004BF3A8(Ctx*,int,int);
int func_004BFDA0(Ctx*,Rec*,u16*,int*,int);
int func_004C0D78(Ctx*,u8,int);
void func_004C3F90(void*,unsigned);
void *func_004C4070(void*,const void*,unsigned);
void func_004C8C38(Ctx*,void*);
}
static inline Ctx **context() { return &D_006452D4; }
extern "C" int func_004BB868(int arg0,int arg1) {
 char backup[0xE8];
 int i,n,idx,flags;
 if(arg0<0) return 0x80001946;
 if(arg1<0) return 0x80001B46;
 Ctx *ctx=*context();
 if(*ctx->state!=0x65) return 0x80000146;
 if(arg0!=0) return 0x80001346;
 if(ctx->work->count<arg1) return 0x80001346;
 i=0;
 func_004C4070(backup,ctx->backup,0xE8);
 Ctx *initial=*context();
 u32 saved=*initial->sequence;
 n=initial->work->len;
 for(;i<arg1;i++) {
  Ctx *ctx=*context();
  Work *w=ctx->work;
  u32 *seq=ctx->sequence;
  u32 value=*seq;
  idx=w->count-i-1;
  Rec *ptr=w->ptrs[idx];
  Rec *e=(Rec*)((char*)w+idx*28);
  if(ptr) e=ptr;
  n-=w->entries[idx].sub.len;
  if(value>0x0FFFFFFEU) *seq=0; else *seq=value+1;
  int result;
  if(i==arg1-1) result=func_004BFDA0(*context(),e,(*context())->text+n,(*context())->other,1);
  else result=func_004BFDA0(*context(),e,(*context())->text+n,(*context())->other,0);
  if(result<0) return result;
  flags=e->flags;
  if(!(flags&0x100000)) {
   if(flags&0x800000) {
    if(e->state==0) {if(func_004BF3A8(*context(),0x300,flags)<0) return 0;}
   } else if(!(flags&0x400000)) {
    int result=func_004C0D78(*context(),e->code,flags);
    if(result<0) return result;
   }
  }
 }
 Work *w=(*context())->work;
 idx=w->count-arg1;
 u16 selected=w->selected;
 if(selected!=0x7FFF && (u32)(selected&0x7FFF)>=(u16)idx) {
  w->selected=0x7FFF;
  (*context())->work->zero=0;
  Ctx *ctx=*context();
  void *allocation=ctx->work->allocation;
  if(allocation) {func_004C8C38(ctx,allocation);(*context())->work->allocation=0;}
 } else {
  (*context())->work->selected|=0x8000;
 }
 i=arg0;
 n=(*context())->work->len;
 for(;i<arg1;) {
  Ctx *ctx=*context();
  Work *w=ctx->work;
  idx=w->count-i-1;
  i++;
  int ptroff=idx*4+0x4A0;
  int offset=idx*28;
  int suboff=offset+16;
  n-=((Sub*)((char*)w+suboff))->len;
  ctx->text[n]=0;
  Ctx *freeCtx=*context();
  void *ptr=*(void**)((char*)freeCtx->work+ptroff);
  if(ptr) {func_004C8C38(freeCtx,ptr);*(void**)((char*)(*context())->work+ptroff)=0;}
  Work *w1=(*context())->work;
  flags=((Sub*)((char*)w1+suboff))->amount;
  w1->total-=flags;
  Work *w2=(*context())->work;
  w2->len-=((Sub*)((char*)w2+suboff))->len;
  func_004C3F90((char*)(*context())->work+offset,28);
 }
 (*context())->work->count-=arg1;
 if((*context())->history->count<=0) (*context())->history->count++;
 i=(*context())->history->index;
 func_004C4070((*context())->history->entries[i].data,backup,0xE8);
 (*context())->history->entries[i].sequence=saved;
 if(++(*context())->history->index>0) (*context())->history->index=0;
 return 0;
}
