/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, refs, selfish; };
struct Str { char *p; char pad[12]; };
extern Rep D_00659E20;
extern char D_006957A8[];
extern "C" char *strobe__toUpper(Rep *) throw();
extern "C" Str *strobe__Any__setMember(Str *, unsigned, unsigned, const char *, unsigned) throw();
extern "C" int func_0057F260(const char *) throw();
extern "C" void free(Rep *) throw();
extern "C" int func_004EC078(void *, Str *);
static inline const char *c_str(Str *s) {
 if (((Rep *)s->p - 1)->len == 0) return D_006957A8;
 s->p[((Rep *)s->p - 1)->len] = 0;
 return s->p;
}
extern "C" void func_005D2EB8(char *self, Str *src) {
 int spare[4];
 Str s;
 char *base = self + 16;
 const char *text = c_str(src);
 Str *ps = &s;
 Rep *r = &D_00659E20;
 char *p = (char *)(r + 1);
 if (r->selfish) p = strobe__toUpper(r); else r->refs++;
 ps->p = p;
 strobe__Any__setMember(ps, 0, -1, text, func_0057F260(text));
 func_004EC078(base + 0xA8, ps);
 r = (Rep *)ps->p - 1;
 if (--r->refs == 0) free(r);
}
