typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Conn;

struct mNetConfPS2Layout {
    char pad[0x268];
    Conn *conn;
};

extern char D_0069A578[];
extern "C" void func_004EE140(Conn *arg0, const char *arg1, const char *arg2);

extern "C" void mNetConfPS2__virtual_96(mNetConfPS2Layout *arg0, void **arg1, void **arg2) {
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
    func_004EE140(arg0->conn, (const char *)a1v, (const char *)a2v);
}
