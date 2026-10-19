typedef int s32;

struct RefCounter;

extern "C" void func_00319268(void *arg0);
extern "C" s32 hThread__execCode(void *arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5);
extern "C" void func_00318538(void *arg0, int arg1);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);

/* Layout backed by config/class_layout.json (size 0x10):
 *   0x00: ref_count
 *   0x04: vtable (hScriptMethod)
 *   0x08: unk8
 *   0x0C: bytecode / code pointer passed to hThread__execCode
 */
struct hScriptMethodLayout {
    void *ref_count;
    void *vtable;
    s32 unk8;
    s32 bytecode;
};

extern "C" void hScriptMethod__call_const(hScriptMethodLayout *arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s5;
    s32 newVal;
    s32 oldVal;

    func_00319268(buf0);
    p_s5 = buf1;
    hThread__execCode(p_s5, buf0[0], &arg0->bytecode, arg2, arg3, arg4);
    if (arg1 != p_s5) {
        newVal = *p_s5;
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *arg1;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *arg1 = newVal;
    }
    func_00309378(p_s5, 2);
    func_00318538(buf0, 2);
}
