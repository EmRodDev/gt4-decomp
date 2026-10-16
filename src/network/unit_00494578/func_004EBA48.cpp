/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
extern "C" Rep D_00659E20;
extern "C" char D_006C01E0[];
extern "C" char *func_00575DC8(int) throw() __attribute__((malloc));
extern "C" void free(void *) throw();
extern "C" void func_0057DA20(char *, const char *, ...);
extern "C" char *strobe__toUpper(Rep *);
struct Str;
extern "C" Str *strobe__Any__setMember(Str *, unsigned int, unsigned int, const char *, unsigned int);
struct Str {
 char *p;
 Rep *rep() const { return (Rep *)p-1; }
 int size() const { return rep()->len; }
 char *begin() const { return (char *)(rep()+1); }
 char *end() const { return begin()+size(); }
 Str() {}
 Str(const Str &s) {
  Rep *r=(Rep *)(s.p-16);
  char *d;
  if (r->sel) d=strobe__toUpper(r);
  else { d=s.p; int n=r->ref+1; r->ref=n; }
  p=d;
 }
 ~Str() { Rep *r=(Rep *)(p-16); if (--r->ref==0) free(r); }
};
extern "C" Str func_004EBA48(Str *s) {
 int n=0;
 char *buf=func_00575DC8(s->size()*3);
 char *q=s->begin();
 for (; q!=s->end(); ++q) {
  int c=*q;
  if ((unsigned int)(c-0x21)>=0x5e || c=='<' || c=='>' || c=='"' || c=='#' || c=='%' || c=='{' || c=='}' || c=='|' || c=='\\' || c=='^' || c=='~' || c=='[' || c==']' || c=='`') {
   func_0057DA20(buf+n,D_006C01E0,c); n+=3;
  } else { buf[n]=c; n++; }
 }
 Str out;
 Str *po=&out;
 char *d;
 if (D_00659E20.sel) d=strobe__toUpper(&D_00659E20);
 else { d=(char *)(&D_00659E20+1); int refs=D_00659E20.ref+1; D_00659E20.ref=refs; }
 po->p=d;
 strobe__Any__setMember(po,0,-1,buf,n);
 free(buf);
 return out;
}
