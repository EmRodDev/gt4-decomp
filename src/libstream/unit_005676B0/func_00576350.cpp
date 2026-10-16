typedef int s32;
struct Obj {
    char *vt;
    char p1[0x100];
    s32 f104;
    s32 f108;
    s32 f10C;
};
extern "C" int func_00576168(void *, s32);
extern "C" void func_005761B0(void *, s32);
extern "C" void func_00576280(void *);
extern "C" void func_0057DE48(void *, s32, s32);
extern "C" void func_00576350(s32 arg0, s32 arg1) {
    Obj tmp;
    func_00576168(&tmp, 0);
    func_0057DE48(&tmp, arg0, arg1);
    func_00576280(&tmp);
    func_005761B0(&tmp, 2);
}
