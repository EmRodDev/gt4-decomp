extern "C" void hModule__getModuleValue();
extern "C" int func_003284E8(void *);
extern "C" void func_00305F80(void *, int, int *);
struct Ent { short delta, index; void (*fn)(void *, int *, int); };
struct Obj { char pad0[4]; Ent *vt; };
struct WidgetSelf {
    char pad0[0x2C];
    Obj *unk2C;
};
static inline Obj *get(Obj **p) {
    int empty = 0;
    if (*p == 0 || func_003284E8(*p) == 0) empty = 1;
    Obj *r = 0;
    if (empty == 0) r = *p;
    return r;
}
extern "C" void mSceneViewFace__virtual_50(WidgetSelf *self, int *arg1, int arg2) {
    hModule__getModuleValue();
    if (*arg1 == 0) {
        Obj **p = &self->unk2C;
        if (get(p)) {
            Obj *obj = get(p);
            Ent *e = &obj->vt[51];
            e->fn((char *)obj + e->delta, arg1, arg2);
            func_00305F80(self, arg2, arg1);
        }
    }
}
