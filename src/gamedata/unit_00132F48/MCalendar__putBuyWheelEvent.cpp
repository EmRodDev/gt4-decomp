/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Script native for MCalendar.putBuyWheelEvent (inferred from the symbol name); needs argc >= 3, otherwise it does nothing.
 * Argument 0 is read as a string through a handle (func_00312370, then func_00314920 extracts the string), argument 1 is a string
 * from vtable slot 0x18 that func_0042EF18 turns into an int (a lookup by name, purpose of the number unknown), argument 2 is an int
 * from slot 0x58. The calendar owner pointer comes from +0x10 of the context handle. Result goes to func_0042F3C0(owner, text, id, int);
 * the ret slot is not written. The same handle buffer is reused for the context and the argument handle, so it is declared once. */
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
void func_00312318(void *, int);
void func_00312370(void *, void *);
Str *func_00314920(void *);
void func_00326798(void *, s32, s32, const char *);
s32 func_0042EF18(const char *);
void func_0042F3C0(s32, const char *, s32, s32);
struct S00659988 *func_005C11A8(void);

static inline Rep *str_rep(Str *s) { return (Rep *)s->p - 1; }
static inline char *rep_data(Rep *text0Str) { return (char *)(text0Str + 1); }
static inline s32 str_length(Str *s) { return str_rep(s)->len; }
static inline void str_terminate(Str *s) { rep_data(str_rep(s))[str_length(s)] = 0; }
static inline const char *c_str(Str *s) {
    if (str_length(s) == 0) return D_0068EAD8;
    str_terminate(s);
    return rep_data(str_rep(s));
}

void MCalendar__putBuyWheelEvent(void *unusedRet, void *ctx, s32 argc, VO **args) {
    if (argc >= 3) {
        HO *handleBuf[4];
        func_00132DB8(handleBuf, ctx);
        s32 owner = handleBuf[0]->f10;
        func_00132D60(handleBuf, 2);
        func_00312370(handleBuf, args);
        Str *text0Str = func_00314920(handleBuf[0]);
        const char *text0 = c_str(text0Str);
        s32 lookupId;
        {
            Str text1Str;
            VO *o = args[1];
            VEntS *e = &o->vt->e18;
            e->fn(&text1Str, (char *)o + e->delta);
            lookupId = func_0042EF18(c_str(&text1Str));
            Rep *rep = str_rep(&text1Str);
            if (--rep->ref == 0) {
                s32 size = rep->cap + 0x10;
                func_00326798(rep, size, 4, func_005C11A8()->name);
            }
        }
        VO *obj2 = args[2];
        VEntI *slot2 = &obj2->vt->e58;
        func_0042F3C0(owner, text0, lookupId, slot2->fn((char *)obj2 + slot2->delta));
        func_00312318(handleBuf, 2);
    }
}
}
