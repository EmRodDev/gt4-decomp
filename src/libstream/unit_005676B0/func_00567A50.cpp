struct S{unsigned char*p;int len;int c;int d;int flag;int e;int cap;};
extern "C" char D_006C8F40[];
extern "C" char D_006C8F70[];
extern "C" char D_006C8FA0[];
extern "C" void func_00567F48(const char*);
extern "C" void func_00567F50(const char*,int);
extern "C" void*func_00568018(unsigned char*,int);
extern "C" void func_00567A50(S*s,unsigned char*src,int n){
 int i;
 if (s->cap < n) {
  func_00567F50(D_006C8F40,n);
  if (s->flag != 0) {
   void*t=func_00568018(s->p,n);
   if (t != 0) {
    s->p=(unsigned char*)t;
    s->cap=n;
   } else {
    n = s->cap;
    func_00567F48(D_006C8F70);
   }
  } else {
   func_00567F48(D_006C8FA0);
   n = s->cap;
  }
 }
 for (i = 0; i < n; i++)
  s->p[i] = src[i];
 s->c = 0;
 s->d = 0;
 s->len = n * 8;
 s->e = 0;
}
