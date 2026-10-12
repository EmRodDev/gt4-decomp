typedef int s32;
struct Rep { s32 len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Obj { char pad[0x10]; char *p10; };
extern char D_006901F0[];
extern "C" void func_0015F388(void *, int);
extern "C" void func_0015F3E0(void *, void *);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" Str *func_00314920(s32);
extern "C" void func_0043AF48(char *, const char *);
static inline const char *c_str(Str *s) { s32 len=((Rep *)s->p)[-1].len; if(len==0)return D_006901F0; s->p[len]=0; return s->p; }
static inline void call(char *p, const char *t) { func_0043AF48(p,t); }
extern "C" void MGame__set_last_entry_name(void *, void *arg1, s32, void *arg3) {
    Obj *tmp[4];
    s32 buf[4];
    s32 *pb;
    char *base;
    func_0015F3E0(tmp,arg1);
    pb=buf;
    func_00312370(pb,arg3);
    base=tmp[0]->p10;
    base+=0x348;
    call(base,c_str(func_00314920(*pb)));
    func_00312318(pb,2);
    func_0015F388(tmp,2);
}
