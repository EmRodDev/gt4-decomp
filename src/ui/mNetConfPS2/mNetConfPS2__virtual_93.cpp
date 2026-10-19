typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct mNetConfPS2Layout {
    char pad[0x268];
    void *conn;
};

extern char D_0069A578[];
extern "C" void func_004ED980(void *conn, void *value, const char *name, const char *text);

extern "C" void mNetConfPS2__virtual_93(mNetConfPS2Layout *arg0, void *arg1, void **arg2, void **arg3) {
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
    func_004ED980(arg0->conn, arg1, (const char *)a2v, (const char *)a3v);
}
