/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
struct VT { short delta,index; int (*fn)(char *); };
struct VT4 { short delta,index; void (*fn)(char *,char *,int,int); };
struct TableSub { char pad[0xA0]; float rate[24]; float other[24]; char flag[24]; };
struct Table { char pad[12]; TableSub sub; char mode[24]; };
extern Table D_00620938;
static inline float other(TableSub * const t,int i) {return t->other[i];}
extern "C" u8 *func_00359510(int);
extern "C" float func_00369640(float,float,float,int) throw() __attribute__((const));
extern "C" int func_003F4E40(char *);
extern "C" int func_003F4EA0(char *);
extern "C" void func_00369888(char *p) {
 int i;
 u8 *s=(u8 *)p+0x104;
 int n=0;
 int flags=0;
 u8 *info=func_00359510(*(int *)(p+0x10));
 i=0;
 if(i<info[1]) {
 char *part=p+0x7B8;
 do {
  if (!((u8 *)part)[0x30]) {
   flags+=((u8 *)part)[0x33]&1;
   if(func_003F4EA0(part)) n++;
  }
 i++; part+=0x34;
 } while(i<info[1]);
 }
 int all=info[1]==n;
 i=0;
 if(i<info[1]) {
 char *q=p;
 u8 *w=(u8 *)p+0x164;
 do {
  char *part=q+0x7B8;
  if(((u8 *)part)[0x30]) *(float *)(w+0x90)=0.0f;
  else {
   *(float *)(w+0x8C)=*(float *)(part+0x10);
   w[0x89]=func_003F4E40(part);
   Table *t=&D_00620938;
   TableSub *sub=&t->sub;
   w[0x8A]=((u8 *)part)[0x32];
   w[0x8B]=((u8 *)part)[0x33];
   float result;
   float rate=sub->rate[w[0x89]];
   if(rate==0.0f) result=0.0f;
   else {
    int m=t->mode[w[0x89]];
    float value=func_00369640(*(float *)(q+0x7B8),*(float *)(part+8),other(sub,w[0x89]),m);
    if(func_003F4EA0(part) && !all) value*=0.5f;
    if(D_00620938.sub.flag[w[0x89]]) value*=*(float *)(w+0x40);
    result=value*rate;
   }
   *(float *)(w+0x90)=result;
  }
 i++; q+=0x34; w+=0xEC;
 } while(i<info[1]);
 }
 *(int *)(s+0x4A8)=*(int *)(p+0x7C4);
 s[0x62C]=n; s[0x62D]=flags;
 if(!s[0x467]) {
  u8 f=s[0x630];
  if((u8)(f&1)==0) {
   if(n==info[1]) {
    u8 count=s[0x62F]; s[0x630]=f|1;
    if(count<100u) s[0x62F]=count+1;
   }
  } else if(n==0) s[0x630]=f^1;
 }
 s[0x4B1]&=0xEF;
 if(flags) {
  char *dc=*(char **)(p+4);
  VT *e=(VT *)(*(char **)(dc+0x10140)+0x180);
  if(e->fn(dc+e->delta)) s[0x4B1]|=0x10;
 }
 char *dc=*(char **)(p+4);
 VT4 *e=(VT4 *)(*(char **)(dc+0x10140)+0x188);
 e->fn(dc+e->delta,p,flags,n);
}
