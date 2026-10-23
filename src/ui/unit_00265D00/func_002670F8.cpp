/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Type { const char *name; };
struct Str;
extern Rep D_00659FA8;
extern char D_00699FF0[];
extern const unsigned char D_006D0E79[];
extern "C" char *func_005C2560(Rep *);
extern "C" int func_0057F260(const char *) throw();
extern "C" Str *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
extern "C" Type *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
struct Str {
 char *p;
 Str(const char *text) {
  Rep *r=&D_00659FA8;
  char *d;
  if(r->sel) d=func_005C2560(r);
  else { d=(char *)(r+1); ++r->ref; }
  p=d;
  func_005C2630(this,0,-1,text,func_0057F260(text));
 }
 Str(const Str &s) {
  Rep *r=(Rep *)(s.p-16);
  char *d;
  if(r->sel) d=func_005C2560(r);
  else { d=s.p; ++r->ref; }
  p=d;
 }
 ~Str() {
  Rep *q=(Rep *)(p-16);
  if(--q->ref==0) {
   int cap=q->cap+16;
   func_00326798(q,cap,4,func_005C11A8()->name);
  }
 }
 void append(const char *text) {
  func_005C2630(this,((Rep *)(p-16))->len,0,text,func_0057F260(text));
 }
};
static inline int is_name_char(char c) {
 return (*(const unsigned char *)((int)D_006D0E79 + c) & 7) || c == '_';
}
extern "C" Str func_002670F8(const char *text) {
 const char *p=text;
 if(*(const unsigned char *)((int)D_006D0E79 + *p) & 3) {
  while(*p && is_name_char(*p)) p++;
  if(*p==0) return Str(text);
 }
 Str t(D_00699FF0);
 t.append(text);
 t.append(D_00699FF0);
 return t;
}
