/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Script native for MGame.menuRef (inferred from the symbol name): looks up a menu reference text by key and returns it as a string handle.
 * The key is args[0] read through vtable slot 0x58 and used directly as a char pointer (0 when argc == 0). The table sits at
 * (context object +0x10) + 0x3A368 and func_0042FDF0(table, key) returns the text or null. A hit is copied into a fresh std::string
 * (empty-rep clone + replace with string length), wrapped by func_00314B20 and stored into out with retain-new / release-old. */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; int pad[3]; };
struct H { struct Q *p; s32 pad[7]; };
struct Q { char pad[0x10]; s32 f10; };
struct VEntryA { short delta; short index; s32 (*fn)(void *); };
struct Obj { char pad0[4]; char *vtbl; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *emptyRep);
extern "C" s32 func_0057F260(const char *strStorage) throw();
extern "C" void *func_005C2630(Str *strStorage, s32 pos, s32 argc, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_0015F388(void *, int) throw();
extern "C" void func_0015F3E0(void *, void *) throw();
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" const char *func_0042FDF0(s32, const char *);

extern "C" void MGame__menuRef(s32 *out, void *ctx, s32 argc, Obj **args) {
    const char *key = 0;
    if (argc > 0) {
        Obj *o = *args;
        VEntryA *e = (VEntryA *)(o->vtbl + 0x58);
        key = (const char *)e->fn((char *)o + e->delta);
    }
    H handle;
    func_0015F3E0(&handle, ctx);
    const char *text = func_0042FDF0(handle.p->f10 + 0x3A368, key);
    func_0015F388(&handle, 2);
    if (text) {
        Str strStorage;
        Str *str = &strStorage;
        Rep *emptyRep = &D_00659FA8;
        char *data;
        if (emptyRep->sel != 0) {
            data = func_005C2560(emptyRep);
        } else {
            data = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        str->p = data;
        func_005C2630(str, 0, -1, text, func_0057F260(text));
        func_00314B20(&handle, str);
        if (out != (s32 *)&handle) {
            s32 newVal = (s32)handle.p;
            if (newVal) func_003285A8(newVal);
            if (*out) func_003285F8(*out);
            *out = newVal;
        }
        func_00312318(&handle, 2);
        {
            Rep *rep = (Rep *)str->p - 1;
            if (--rep->ref == 0) {
                s32 cap = rep->cap + 0x10;
                func_00326798(rep, cap, 4, func_005C11A8()->name);
            }
        }
    }
}
