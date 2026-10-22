/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Splits a command-line style string into tokens appended to a vector of std::strings.
 * If the text is empty nothing happens. If it does not start with '/', it appends D_00698DB8 (a fixed first token) followed by the whole text.
 * If it starts with '/', it scans from index 1, cutting tokens at spaces and tabs into a 64-byte buffer (a token of 63 characters or more aborts the function),
 * appends each token and skips the whitespace after it. Appending is the hand-expanded push_back: store at end when end != limit, else call the
 * grow-and-insert helper func_005DC070. grab() copies the string rep (clone if shared flag set, else bump the ref count) the way the library does. */
struct Rep { int len,cap,ref,sel; };
struct Str {char *p;};
struct Info {const char *name;};
struct Vec {int pad;Str *begin,*end,*limit;};
extern Rep D_00659FA8;
extern char D_00698DB0[],D_00698DB8[];
extern "C" int func_0057F260(const char *) throw();
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *,unsigned,unsigned,const char *,unsigned);
extern "C" void func_005DC070(Vec *,Str *,Str *);
extern "C" Info *func_005C11A8();
extern "C" void func_00326798(void *,int,int,const char *);
static inline Rep *rep(Str *s) {return (Rep *)s->p-1;}
static inline char *data(Rep *r) {return (char *)(r+1);}
static inline const char *cstr(Str *s) {if(rep(s)->len==0)return D_00698DB0;data(rep(s))[rep(s)->len]=0;return data(rep(s));}
static inline char *grab(Rep *r) {if(r->sel)return func_005C2560(r);++r->ref;return data(r);}
static inline void init(Str *s,const char *text) {s->p=grab(&D_00659FA8);func_005C2630(s,0,-1,text,func_0057F260(text));}
static inline void release(Str *s) {Rep *r=rep(s);if(--r->ref==0){int size=r->cap+16;func_00326798(r,size,4,func_005C11A8()->name);}}
extern "C" void func_0023D230(void *unused,Str *commandLine,Vec *tokens) {
 Str tokenStr;
 char token[64];
 const char *text=cstr(commandLine);
 int length=rep(commandLine)->len;
 if(length>0) {
  if(*text!='/') {
   init(&tokenStr,D_00698DB8);
   if(tokens->end!=tokens->limit){Str *slot=tokens->end;if(slot)slot->p=grab(rep(&tokenStr));++tokens->end;}else func_005DC070(tokens,tokens->end,&tokenStr);
   release(&tokenStr);
   if(tokens->end!=tokens->limit){Str *slot=tokens->end;if(slot)slot->p=grab(rep(commandLine));++tokens->end;}else func_005DC070(tokens,tokens->end,commandLine);
  } else {
   int start=1;
   int pos;
   for(;;) {
    pos=start;
    while(text[pos]!=' ' && text[pos]!='\t' && pos<length) {
     int off=pos-start;
     if(off>=63)return;
     token[off]=text[start+off];
     pos++;
    }
    token[pos-start]=0;
    init(&tokenStr,token);
    if(tokens->end!=tokens->limit){Str *slot=tokens->end;if(slot)slot->p=grab(rep(&tokenStr));++tokens->end;}else func_005DC070(tokens,tokens->end,&tokenStr);
    release(&tokenStr);
    while((text[pos]==' ' || text[pos]=='\t') && pos<length) pos++;
    if(pos>=length)break;
    start=pos;
   }
  }
 }
}
