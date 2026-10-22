/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Script native for MMemoryCardPlayList.remove (inferred from the symbol name): removes the playlist entry at an index and reports whether it did.
 * The context handle (func_0017D2C0) points to a node holding the list at +0x10 and a dirty flag at +0x18. With argc > 0 and args[0] (vtable slot 0x58) >= 0,
 * func_001D12D8(list, index) removes the entry, the dirty flag is set to 1 and the result is true; otherwise the result stays false.
 * The bool is boxed by func_002FE278 and assigned to ret with retain-new / release-old. */
struct Node { char pad[16]; void *list; int pad14; int dirty; };
struct VE { short delta; short index; int (*fn)(void *); };
struct VO { int x; VE *vt; };
static inline int vcall(VO *o) {
    VE *e = (VE *)((char *)o->vt + 0x58);
    return e->fn((char *)o + e->delta);
}
extern "C" void func_0017D268(void *, int) throw();
extern "C" void func_0017D2C0(void *, void *) throw();
extern "C" void func_001D12D8(void *, int);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void MMemoryCardPlayList__remove(void **ret, void *ctx, int argc, VO **args) {
    Node *ctxHandle[4];
    void *resultHandle[4];
    bool result = false;
    func_0017D2C0(ctxHandle, ctx);
    if (argc > 0) {
        int index = vcall(*args);
        if (index >= 0) {
            func_001D12D8(ctxHandle[0]->list, index);
            ctxHandle[0]->dirty = 1;
            result = true;
        }
    }
    void **resultPtr = resultHandle;
    func_002FE278(resultPtr, result);
    if (ret != resultPtr) {
        void *newVal = *resultPtr;
        if (newVal != 0) func_003285A8(newVal);
        void *oldVal = *ret;
        if (oldVal != 0) func_003285F8(oldVal);
        *ret = newVal;
    }
    func_002FC870(resultPtr, 2);
    func_0017D268(ctxHandle, 2);
}
