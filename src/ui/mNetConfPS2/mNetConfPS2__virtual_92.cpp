typedef int s32;

/* Layout backed by include/gt4/mNetConfPS2.h, config/class_fields.json, and bastring.h:
 *   mNetConfPS2: offset 0x268 is unk268 (Table *table)
 *   Rep: GCC 2.96 basic_string header at p - sizeof(Rep)
 */
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

extern char D_0069A578[];
extern "C" int func_004EE4E8(Table *table, const char *id);

extern "C" void mNetConfPS2__virtual_92(mNetConfPS2Layout *arg0, void **arg1) {
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
    func_004EE4E8(arg0->table, (const char *)a1v);
}
