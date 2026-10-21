/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Assigns the ref-counted handle *newHandle into the object's handle field (+0x2A8 area, with the usual self-assignment guard and retain/release pair), caches func_00145AB8 of it in +0x2B8, clears the sub-object's flag at +0x98, then drives the sub-object through three virtual calls: slot +0x1B0 with the car-equipment variation order of the handle (inferred from the SPEC_DATABASE::CarEquipments callee), slot +0x1C8 with a copy of the handle, and slot +0x190 with a temporary string built from the handle's name. The string temporary is released by hand at the end because the inlined basic_string destructor is expanded here. */
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
    s32 f2b8;
};
extern Rep D_00659FA8;
extern "C" {
void func_0013BD50(void *, void *);
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

void func_0013A9E0(Obj *self, void **newHandle) {
    void **handleField = &self->h;
    if (handleField != newHandle) {
        void *retained = *newHandle;
        if (retained != 0) func_003285A8(retained);
        if (*handleField != 0) func_003285F8(*handleField);
        *handleField = retained;
    }
    M **subObjField = &self->m;
    Sub *embedded = &self->sub;
    self->f2b8 = func_00145AB8(*handleField);
    (*subObjField)->f98 = 0;
    M *subObj = *subObjField;
    VEnt *slot = &subObj->vt->e1b0;
    char *slotThis = (char *)subObj + slot->delta;
    slot->fn(slotThis, SPEC_DATABASE__CarEquipments__getVariationOrder(func_00441248(func_00147D80(*handleField))));
    const char *name = func_00145E30(*handleField);
    func_00153B50(*subObjField, embedded);
    {
        void *tmp[4];
        func_0013BD50(tmp, handleField);
        M *subObj2 = *subObjField;
        VEnt *slot2 = &subObj2->vt->e1c8;
        slot2->fn((char *)subObj2 + slot2->delta, tmp);
    }
    M *subObj3 = *subObjField;
    Str nameStr;
    Str *nameStrPtr = &nameStr;
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
    nameStrPtr->p = chars;
    func_005C2630(nameStrPtr, 0, -1, name, func_0057F260(name));
    slot3->fn(slotThis3, &nameStr, handleField, embedded->f4 == 2);
    Rep *rep = (Rep *)nameStr.p - 1;
    if (--rep->ref == 0) {
        s32 size = rep->cap + 0x10;
        func_00326798(rep, size, 4, func_005C11A8()->name);
    }
}
}
