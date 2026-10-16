struct Obj;
struct Copy;
extern "C" int func_00570F58(Obj *, void *, int, int *, Copy *, int *, int *, int *);
extern "C" int func_005705F8(void *arg0, void *arg1, Obj *arg2, void *arg3, int count, int *arg5, Copy *arg6, int *arg7, int arg8) {
    int size;
    int err = -0x1f5;
    if (arg0 == 0 || arg8 < -1 || arg1 == 0) return -0x1f5;
    if (count == 0) return 0;
    if (func_00570F58(arg2, arg3, count, arg5, arg6, arg7, &size, &err) == 0) return size;
    return err == 0 ? -0x1f5 : err;
}
