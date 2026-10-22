/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Script native for MCalendar.putSellCarEvent (inferred from the symbol name and the (ret, ctx, argc, args) callback shape).
 * Builds a context handle (func_00132DB8), reads the owner pointer at +0x10 of the object it holds, then reads up to three script
 * arguments: a string through vtable slot 0x18 and two ints through slot 0x58 (the second and third only when argc >= 2 / >= 3, else 0).
 * Everything is forwarded to func_0042F218(owner, text, int1, int2). The ret slot is never written. The std::string rep is
 * released by hand (ref count at -4 words, size cap + 0x10) because the compiler needs the inlined release in this order. */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct HO { char pad[0x10]; s32 f10; };
struct VEntS { s16 delta; s16 pad; void (*fn)(void *, void *); };
struct VEntI { s16 delta; s16 pad; s32 (*fn)(void *); };
struct VT { char pad[0x18]; VEntS e18; char pad1[0x58 - 0x18 - 8]; VEntI e58; };
struct VO { char pad[4]; VT *vt; };
extern char D_0068EAD8[];
extern "C" {
void func_00132D60(void *, int) throw();
void func_00132DB8(void *, void *) throw();
void func_00326798(void *, s32, s32, const char *);
void func_0042F218(s32, const char *, s32, s32);
struct S00659988 *func_005C11A8(void);

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *r) { return (char *)(r + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_0068EAD8;
    str_terminate(s);
    return rep_data(str_rep(s));
}

void MCalendar__putSellCarEvent(void *unusedRet, void *ctx, s32 argc, VO **args) {
    if (argc > 0) {
        s32 owner;
        {
            HO *ctxHandle[4];
            func_00132DB8(ctxHandle, ctx);
            owner = ctxHandle[0]->f10;
            func_00132D60(ctxHandle, 2);
        }
        const char *text;
        {
            Str textStr;
            VO *o = args[0];
            VEntS *e = &o->vt->e18;
            e->fn(&textStr, (char *)o + e->delta);
            text = c_str(&textStr);
            Rep *rep = str_rep(&textStr);
            if (--rep->ref == 0) {
                s32 size = rep->cap + 0x10;
                func_00326798(rep, size, 4, func_005C11A8()->name);
            }
        }
        s32 int1 = 0;
        if (argc >= 2) {
            VO *o = args[1];
            VEntI *e = &o->vt->e58;
            int1 = e->fn((char *)o + e->delta);
        }
        s32 int2 = 0;
        if (argc >= 3) {
            VO *o = args[2];
            VEntI *e = &o->vt->e58;
            int2 = e->fn((char *)o + e->delta);
        }
        func_0042F218(owner, text, int1, int2);
    }
}
}
