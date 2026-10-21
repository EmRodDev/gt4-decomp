/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct O { char pad[0x10]; char c10[0x98]; s32 *uA8; };
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_0057CB80(void *, void *);
extern "C" s32 func_0060A5B8(O *o) {
    char *lock = o->c10;
    s32 r = 0;
    func_00576788(lock);
    s32 **slot = &o->uA8;
    s32 *p = *slot;
    if (p != 0) {
        func_0057CB80(slot, p);
        r = *p;
    }
    func_005767C0(lock);
    return r;
}
