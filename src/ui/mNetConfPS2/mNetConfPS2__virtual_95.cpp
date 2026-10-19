#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Netcnf;

struct mNetConfPS2Layout {
    char pad[0x268];
    Netcnf *netcnf;
};

extern char D_0069A578[];
extern "C" s32 func_004EE048(Netcnf *n, s32 mode, const char *name, s32 arg);

extern "C" void mNetConfPS2__virtual_95(mNetConfPS2Layout *arg0, void **arg1, void **arg2, void **arg3) {
    char *obj1 = (char *)*arg1;
    Rep *rep1 = (Rep *)obj1 - 1;
    s32 off1 = rep1->len;
    void *a1v;
    if (off1 == 0) {
        a1v = D_0069A578;
    } else {
        obj1[off1] = 0;
        a1v = *arg1;
    }
    char *obj2 = (char *)*arg2;
    Rep *rep2 = (Rep *)obj2 - 1;
    s32 off2 = rep2->len;
    void *a2v;
    if (off2 == 0) {
        a2v = D_0069A578;
    } else {
        obj2[off2] = 0;
        a2v = *arg2;
    }
    char *obj3 = (char *)*arg3;
    Rep *rep3 = (Rep *)obj3 - 1;
    s32 off3 = rep3->len;
    void *a3v;
    if (off3 == 0) {
        a3v = D_0069A578;
    } else {
        obj3[off3] = 0;
        a3v = *arg3;
    }
    func_004EE048(arg0->netcnf, (s32)a1v, (const char *)a2v, (s32)a3v);
}
