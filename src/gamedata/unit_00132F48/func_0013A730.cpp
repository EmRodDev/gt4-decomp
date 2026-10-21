/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Sets the object's name string (+0x2B8 gets the c_str of *name), looks up a handle by that name with func_00148080 and stores it into the handle field at +0x2A8 (retain new, release old), then, if the sub-object pointer at +0x2A4 is set, sets its flag +0x98 to 1 and drives it through virtual slots +0x1B0, +0x1C8 and +0x190 (the last with a temporary basic_string built from the handle's name and a flag that is true when the embedded value at +0xA4 is 2). The string is destroyed by hand because the inlined basic_string destructor is expanded here. */
typedef int s32;
typedef short s16;
typedef unsigned int u32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; char pad[0xC]; };
struct VEnt { s16 delta; s16 pad; void (*fn)(void *, ...); };
struct VT { char pad[0x190]; VEnt e190; char pad2[0x18 - 8 + 0x8]; VEnt e1b0; char pad3[0x10]; VEnt e1c8; };
struct M { char pad[4]; VT *vt; char pad2[0x90]; s32 f98; };
struct Sub { char pad[4]; s32 f4; };
struct Obj {
    char pad[0xA0];
    Sub sub;
    char pad2[0x2A4 - 0xA0 - 8];
    M *m;
    void *h;
    char pad3[0x2B8 - 0x2A8 - 4];
    const char *f2b8;
};
extern Rep D_00659FA8;
extern char D_0068EE18[];
extern "C" {
void func_0013BD50(void *, void *);
void func_0013BD68(void *, int);
void func_00148080(void *, const char *);
s32 func_00145AB8(void *);
const char *func_00145E30(void *);
int func_00147D80(void *);
void func_00153B50(void *, void *);
void func_00326798(void *, s32, s32, const char *);
void func_003285A8(void *);
void func_003285F8(void *);
s32 func_00441248(s32);
s32 SPEC_DATABASE__CarEquipments__getVariationOrder(s32);
s32 func_0057F260(const char *) throw();
struct S00659988 *func_005C11A8(void);
char *func_005C2560(void *);
void *func_005C2630(void *, u32, u32, const char *, u32);

static inline const char *c_str(Str *s) {
    if (((Rep *)s->p - 1)->len == 0) return D_0068EE18;
    s->p[((Rep *)s->p - 1)->len] = 0;
    return s->p;
}
void func_0013A730(Obj *self, Str *name) {
    union { void *h[4]; Str st; } lookup;
    self->f2b8 = c_str(name);
    void **handleField = &self->h;
    func_00148080(lookup.h, c_str(name));
    if (handleField != lookup.h) {
        void *found = lookup.h[0];
        if (found != 0) func_003285A8(found);
        if (*handleField != 0) func_003285F8(*handleField);
        *handleField = found;
    }
    func_0013BD68(lookup.h, 2);
    M **subObjField = &self->m;
    if (__builtin_expect((int)*subObjField, 0)) {
        (*subObjField)->f98 = 1;
        Sub *embedded = &self->sub;
        M *subObj = *subObjField;
        VEnt *slot = &subObj->vt->e1b0;
        slot->fn((char *)subObj + slot->delta, 0);
        const char *name = func_00145E30(*handleField);
        func_00153B50(*subObjField, embedded);
        func_0013BD50(lookup.h, handleField);
        M *subObj2 = *subObjField;
        VEnt *slot2 = &subObj2->vt->e1c8;
        slot2->fn((char *)subObj2 + slot2->delta, lookup.h);
        M *subObj3 = *subObjField;
        Str *nameStr = &lookup.st;
        VEnt *slot3 = &subObj3->vt->e190;
        char *slotThis3 = (char *)subObj3 + slot3->delta;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        nameStr->p = chars;
        func_005C2630(nameStr, 0, -1, name, func_0057F260(name));
        slot3->fn(slotThis3, &lookup.st, handleField, embedded->f4 == 2);
        Rep *rep = (Rep *)lookup.st.p - 1;
        if (--rep->ref == 0) {
            s32 size = rep->cap + 0x10;
            func_00326798(rep, size, 4, func_005C11A8()->name);
        }
    }
}
}
