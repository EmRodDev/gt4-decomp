typedef short s16;
typedef int s32;
typedef float f32;

struct VEntry {
    s16 delta;
    s16 index;
    void *fn;
};

struct Obj {
    VEntry *vtbl;
};

struct Owner {
    VEntry *vtbl;
    char pad4[0x9BC - 4];
    s32 unk9BC;
};

typedef Obj *(*ObjFn)(void *self, s32 arg);
typedef f32 (*FFn)(void *self, f32 arg);

f32 RacePhotoModeCameraManager__virtual_03(Owner *arg0, f32 fparg0) {
    f32 result;
    VEntry *e = &arg0->vtbl[27];
    Obj *obj = ((ObjFn)e->fn)((char *)arg0 + e->delta, arg0->unk9BC);
    result = 0.0f;
    if (obj != 0) {
        VEntry *f = &obj->vtbl[4];
        result = ((FFn)f->fn)((char *)obj + f->delta, fparg0);
    }
    return result;
}
