typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Table;

struct mNetConfPS2Layout {
    char pad[0x268];
    Table *table;
};

extern "C" int func_004EDCE8(Table *table, const char *id);
extern "C" char D_0069A578[];

extern "C" void mNetConfPS2__virtual_97(mNetConfPS2Layout *arg0, void **arg1) {
    char *obj = (char *)*arg1;
    Rep *rep = (Rep *)obj - 1;
    s32 off = rep->len;
    void *a1v;
    if (off == 0) {
        a1v = D_0069A578;
    } else {
        obj[off] = 0;
        a1v = *arg1;
    }
    func_004EDCE8(arg0->table, (const char *)a1v);
}
