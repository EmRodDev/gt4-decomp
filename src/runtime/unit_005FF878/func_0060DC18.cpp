/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct StringRep { u32 len, res, ref, selfish; };
struct String { char *dat; };
extern "C" void free(void *) throw();
extern "C" char *strobe__toUpper(StringRep *) throw();
extern "C" String *strobe__Any__setMember(String *,u32,u32,const char *,u32) throw();
static inline StringRep *rep(const String *s) { return (StringRep *)s->dat - 1; }
extern "C" String *func_0060DC18(String *self,u32 pos1,u32 n1,const String *str,u32 pos2,u32 n2) {
 u32 len2=rep(str)->len;
 if(pos1==0 && n1>=rep(self)->len && pos2==0 && n2>=len2) {
  if(str!=self) {
   StringRep *r=rep(self);
   if(--r->ref==0) free(r);
   StringRep *g=rep(str);
   char *d;
   if(g->selfish!=0) d=strobe__toUpper(g);
   else { d=(char *)(g+1); g->ref++; }
   self->dat=d;
  }
  return self;
 }
 if(n2>len2-pos2) n2=len2-pos2;
 return strobe__Any__setMember(self,pos1,n1,str->dat+pos2,n2);
}
