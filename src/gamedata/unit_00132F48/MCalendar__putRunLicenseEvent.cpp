/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Script method putRunLicenseEvent: same argument handling as putRunRaceEvent (name, converted string, optional converted string defaulting to 14, integer) but the event is added with func_0042F2E0. Value meanings are not determined. */
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
s32 func_0042EF68(const char *);
s32 func_00431C60(const char *);
s32 func_00431CB8(const char *);
void func_0042F2E0(s32, const char *, s32, s32, s32);
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

static inline void release(Str *s) {
    Rep *q = str_rep(s);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}
static inline void text(Str *s, VO *o) {
    VEntS *e = &o->vt->e18;
    e->fn(s, (char *)o + e->delta);
}
static inline s32 number(VO *o) {
    VEntI *e = &o->vt->e58;
    return e->fn((char *)o + e->delta);
}
void MCalendar__putRunLicenseEvent(void *unused, void *object, s32 argCount, VO **args) {
    if (argCount >= 4) {
        union { Str st; HO *h[4]; } scratch;
        text(&scratch.st, args[0]);
        const char *name = c_str(&scratch.st);
        release(&scratch.st);
        text(&scratch.st, args[1]);
        const char *color = c_str(&scratch.st);
        release(&scratch.st);
        s32 b = func_00431C60(color);
        s32 c = 14;
        if (args[2]) {
            text(&scratch.st, args[2]);
            c = func_00431CB8(c_str(&scratch.st));
            release(&scratch.st);
        }
        s32 d = number(args[3]);
        func_00132DB8(scratch.h, object);
        func_0042F2E0(scratch.h[0]->f10, name, b, c, d);
        func_00132D60(scratch.h, 2);
    }
}
}
