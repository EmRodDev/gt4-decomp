/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Sets the string at +0xF0 of the object to the C string text (copy through the inlined refcounted-string helpers, releasing the old
 * buffer), then rebuilds the handle stored at +0x114 from the string with func_00218A60: the new handle is retained and the old one
 * released. Class not identified (directory unit_0021FAD0). The unused second argument is kept in the signature. */
typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Obj {
    char pad0[0xF0];
    char *str;
    char pad1[0x114 - 0xF4];
    s32 handleField;
};

extern Rep D_00659FA8;
extern "C" char * func_005C2560(Rep *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void * func_005C2630(void *, s32, s32, const char *, s32);
struct R { s32 m0; R(const R &o); };
inline void *operator new(unsigned int, void *p) { return p; }
extern "C" R func_00218A60(s32);
extern "C" void func_0021D828(void *, s32) throw();
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" struct S00659988 * func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(char *p) {
    Rep *q = (Rep *)(p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_0021FC78(Obj *self, s32 unused, const char *text) {
    char *scratch[4];
    char **p = scratch;
    char **stringField = &self->str;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        *p = d;
    }
    func_005C2630(p, 0, -1, text, func_0057F260(text));
    if (scratch != stringField) {
        str_release(*stringField);
        {
            Rep *r = (Rep *)(scratch[0] - 0x10);
            char *d;
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                d = (char *)(r + 1);
                r->ref++;
            }
            *stringField = d;
        }
    }
    str_release(scratch[0]);
    s32 *handleField = &self->handleField;
    new (scratch) R(func_00218A60((s32)stringField));
    if (handleField != (s32 *)scratch) {
        s32 newVal = ((s32 *)scratch)[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        s32 oldVal = *handleField;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *handleField = newVal;
    }
    func_0021D828(scratch, 2);
}
