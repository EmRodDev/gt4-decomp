/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Script property accessor MGame difficulty: with arguments (argCount > 0) it acts as the setter, converting the string in args[0] to a number with func_00430298 and storing it in the game record at +0xCC; otherwise it acts as the getter and converts the stored value back to a name with func_00430270, returning it as a new script string through *out (retain new, release old). The string/number table lookups are named only by position in the source; the semantics of the stored value are inferred from the accessor name. */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; int pad[3]; };
struct Str2 { char *p; int pad[7]; };
struct Q { char pad[0x10]; char *f10; };
struct H { Q *p; s32 pad[3]; };
struct VEntryB { short delta; short index; void (*fn)(Str *, void *); };
struct Obj { char pad0[4]; char *vtbl; };
extern Rep D_00659FA8;
extern char D_006901F0[];
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s) throw();
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_0015F388(void *, int) throw();
extern "C" int func_0015F3E0(void *) throw();
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" const char *func_00430270(s32);
extern "C" s32 func_00430298(const char *);

extern "C" void MGame__get_difficulty(s32 *out, s32 unused, s32 argCount, Obj **args) {
    H h;
    Str2 argText;
    if (argCount > 0) {
        func_0015F3E0(&h);
        Obj *o = *args;
        Str *textPtr = (Str *)&argText;
        char *t = h.p->f10 + 4;
        VEntryB *e = (VEntryB *)(o->vtbl + 0x18);
        e->fn(textPtr, (char *)o + e->delta);
        const char *chars;
        s32 len = ((Rep *)textPtr->p - 1)->len;
        if (len == 0) {
            chars = D_006901F0;
        } else {
            textPtr->p[len] = 0;
            chars = textPtr->p;
        }
        *(s32 *)(t + 0xC8) = func_00430298(chars);
        {
            Rep *q = (Rep *)textPtr->p - 1;
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_0015F388(&h, 2);
    } else {
        Str resultText;
        H recordCopy;
        Str *textPtr = &resultText;
        H *recordPtr = &recordCopy;
        func_0015F3E0(recordPtr);
        const char *name = func_00430270(*(s32 *)(recordPtr->p->f10 + 0xCC));
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        textPtr->p = d;
        func_005C2630(textPtr, 0, -1, name, func_0057F260(name));
        func_00314B20(&h, textPtr);
        if (out != (s32 *)&h) {
            s32 nv = (s32)h.p;
            if (nv) func_003285A8(nv);
            if (*out) func_003285F8(*out);
            *out = nv;
        }
        func_00312318(&h, 2);
        {
            Rep *q = (Rep *)textPtr->p - 1;
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        func_0015F388(recordPtr, 2);
    }
}
