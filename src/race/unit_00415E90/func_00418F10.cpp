/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u128 __attribute__((mode(TI)));
struct S {char p[0x1a0];u128 a[6];int n;};
extern "C" S *func_0041C2A8(S*,const S*);
extern "C" void func_00418FF8(void*,const void*);
static inline void assign(char *d,const char *s) {
 u128 *dst=(u128*)(d+0xc0); const u128 *src=(const u128*)(s+0xc0);
 for(int i=0;i<6;i++) *dst++=*src++;
 func_00418FF8(d,s);
}
extern "C" S *func_00418F10(S *o,const S *b) {
 func_0041C2A8(o,b);
 assign((char*)o+0xe0,(const char*)b+0xe0);
 o->n=b->n;
 return o;
}
