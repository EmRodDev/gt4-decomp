typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct func_004ED4D8_arg0;
extern char D_0069A578[];
extern "C" s32 func_004ED4D8(struct func_004ED4D8_arg0 *arg0, s32 arg1, s32 arg2);

struct mNetConfPS2Layout {
    char pad[0x268];
    func_004ED4D8_arg0 *conn;
};

extern "C" void mNetConfPS2__virtual_102(mNetConfPS2Layout *arg0, void **arg1, void **arg2) {
    char *d1 = (char *)*arg1;
    Rep *r1 = (Rep *)d1 - 1;
    s32 n1 = r1->len;
    const char *c1;
    if (n1 == 0) {
        c1 = D_0069A578;
    } else {
        d1[n1] = 0;
        c1 = (const char *)*arg1;
    }

    char *d2 = (char *)*arg2;
    Rep *r2 = (Rep *)d2 - 1;
    s32 n2 = r2->len;
    const char *c2;
    if (n2 == 0) {
        c2 = D_0069A578;
    } else {
        d2[n2] = 0;
        c2 = (const char *)*arg2;
    }

    func_004ED4D8(arg0->conn, (s32)c1, (s32)c2);
}
