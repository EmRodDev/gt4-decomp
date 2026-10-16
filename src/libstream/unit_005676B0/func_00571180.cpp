struct Obj;
struct Copy;
extern "C" int func_00570F58(Obj *, void *, int, int *, Copy *, int *, int *, int *) throw();
extern "C" int func_00571180(Obj *self, void *src, Copy *target, int *out, int *limit) {
    int sp0;
    int sp4;
    int sp8;
    int result = 2;
    sp8 = 0;
    sp0 = 0;
    if (!out) return result;
    *out = 0;
    if (!src) return result;
    if (!target) return result;
    if (!limit) return result;
    *limit = 0;
    if (!self) return result;
    result = func_00570F58(self, src, 2, &sp0, target, &sp4, &sp8, limit);
    if (sp8 == 2) *out = 1;
    return result;
}
