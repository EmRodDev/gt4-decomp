/* Script-engine registration for MPhotoMapWindow: sets its name through the vtable, links it to its parent class mBox (class id from mBox__GetClassID),
 * then registers 3 methods, 11 attributes (getter/setter), 1 registration on a global symbol object
 * so scripts can call into C++ (see knowledge/script-engine.md, section 3.3).
 * Each registration builds the member name as a refcounted string from a literal and releases it afterwards;
 * the repeated inline blocks are the compiler expansion of that string constructor/destructor and are kept as is. */
#define GT4_DECLS
#include "gt4/hObject.h"
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

struct Str {
    char *p;
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *, Str *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern Rep D_00659FA8;

extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_0057F260(const char *s);
extern "C" void *func_005C2630(Str *s, s32 pos, s32 n, const char *src, s32 len);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_002F3A30(Obj *cls, s32 parentClassId);
extern "C" int mBox__GetClassID(void);
extern "C" void func_002F3818(Obj *cls, Str *name, void (*method)(void));
extern "C" void func_002F3860(Obj *cls, Str *name, void (*getter)(void), void (*setter)(void));
extern "C" void func_00306780(Obj *cls, void *symbol, void (*function)(void));
extern char D_00692278[];
extern char D_00692288[];
extern char D_00692298[];
extern char D_006922A8[];
extern char D_006922B8[];
extern char D_006922C8[];
extern char D_006922D8[];
extern char D_006922E8[];
extern char D_006922F8[];
extern char D_00692300[];
extern char D_00692310[];
extern char D_00692320[];
extern char D_00692330[];
extern char D_00692338[];
extern char D_00692348[];
extern char D_00824FC0[];
extern "C" void MPhotoMapWindow__global_00824FC0(void);
extern "C" void MPhotoMapWindow__get_wheel_angle(void);
extern "C" void MPhotoMapWindow__get_lightness(void);
extern "C" void MPhotoMapWindow__get_color_filter(void);
extern "C" void MPhotoMapWindow__setBaseLen(void);
extern "C" void MPhotoMapWindow__get_brightness(void);
extern "C" void MPhotoMapWindow__get_contrast(void);
extern "C" void MPhotoMapWindow__get_whiteBalance(void);
extern "C" void MPhotoMapWindow__doFocus(void);
extern "C" void MPhotoMapWindow__get_operate_mode(void);
extern "C" void MPhotoMapWindow__set_operate_mode(void);
extern "C" void MPhotoMapWindow__get_view_angle(void);
extern "C" void MPhotoMapWindow__set_view_angle(void);
extern "C" void MPhotoMapWindow__get_aperture(void);
extern "C" void MPhotoMapWindow__get_stand(void);
extern "C" void MPhotoMapWindow__set_stand(void);
extern "C" void MPhotoMapWindow__getAperture(void);
extern "C" void MPhotoMapWindow__get_can_shoot(void);
extern "C" void MPhotoMapWindow__set_can_shoot(void);

extern "C" void func_001965A0(Obj *cls) {
    Str name;
    {
        Str *namePtr = &name;
        const char *literal = D_00692278;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        {
            VEntry *entry = (VEntry *)(cls->vtbl + 0x190);
            entry->fn((char *)cls + entry->delta, &name);
        }
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    func_002F3A30(cls, mBox__GetClassID());
    func_00306780(cls, D_00824FC0, MPhotoMapWindow__global_00824FC0);
    {
        Str *namePtr = &name;
        const char *literal = D_00692288;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3860(cls, &name, MPhotoMapWindow__get_wheel_angle, MPhotoMapWindow__get_wheel_angle);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_00692298;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3860(cls, &name, MPhotoMapWindow__get_lightness, MPhotoMapWindow__get_lightness);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_006922A8;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3860(cls, &name, MPhotoMapWindow__get_color_filter, MPhotoMapWindow__get_color_filter);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_006922B8;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3818(cls, &name, MPhotoMapWindow__setBaseLen);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_006922C8;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3860(cls, &name, MPhotoMapWindow__get_brightness, MPhotoMapWindow__get_brightness);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_006922D8;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3860(cls, &name, MPhotoMapWindow__get_contrast, MPhotoMapWindow__get_contrast);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_006922E8;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3860(cls, &name, MPhotoMapWindow__get_whiteBalance, MPhotoMapWindow__get_whiteBalance);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_006922F8;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3818(cls, &name, MPhotoMapWindow__doFocus);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_00692300;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3860(cls, &name, MPhotoMapWindow__get_operate_mode, MPhotoMapWindow__set_operate_mode);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_00692310;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3860(cls, &name, MPhotoMapWindow__get_view_angle, MPhotoMapWindow__set_view_angle);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_00692320;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3860(cls, &name, MPhotoMapWindow__get_aperture, MPhotoMapWindow__get_aperture);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_00692330;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3860(cls, &name, MPhotoMapWindow__get_stand, MPhotoMapWindow__set_stand);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_00692338;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3818(cls, &name, MPhotoMapWindow__getAperture);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
    {
        Str *namePtr = &name;
        const char *literal = D_00692348;
        Rep *emptyRep = &D_00659FA8;
        char *chars;
        if (emptyRep->sel != 0) {
            chars = func_005C2560(emptyRep);
        } else {
            chars = (char *)(emptyRep + 1);
            emptyRep->ref++;
        }
        namePtr->p = chars;
        func_005C2630(namePtr, 0, -1, literal, func_0057F260(literal));
        func_002F3860(cls, &name, MPhotoMapWindow__get_can_shoot, MPhotoMapWindow__set_can_shoot);
        {
            Rep *rep = (Rep *)(name.p - 0x10);
            if (--rep->ref == 0) {
                s32 capacity = rep->cap + 0x10;
                func_00326798(rep, capacity, 4, func_005C11A8()->name);
            }
        }
    }
}
