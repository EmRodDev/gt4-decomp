/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *) throw();
extern "C" int func_001F62E0(s32) ;
extern "C" void *func_001F63A8(s32);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

struct Result {
    s32 v[4];

    ~Result() { func_002FC870(this, 2); }
};

static inline void store(s32 *ret, Result *r) {
    if (ret != r->v) {
        s32 newVal = r->v[0];
        s32 oldVal;
        if (newVal != 0) func_003285A8(newVal);
        oldVal = *ret;
        if (oldVal != 0) func_003285F8(oldVal);
        *ret = newVal;
    }
}

extern "C" void MNetwork__endMGCL(s32 *ret) {
    s32 h0[4];

    func_001DC650(h0);
    if (func_001F63A8(h0[0]) == 0) {
        {
            Result r; func_002FE278(&r, 0);
            store(ret, &r);
        }
        func_001DC5F8(h0, 2);
        return;
    }
    if (func_001F62E0(h0[0]) == 0) {
        Result r; func_002FE278(&r, 0);
        store(ret, &r);
    }
    {
        Result r; func_002FE278(&r, 1);
        store(ret, &r);
    }
    func_001DC5F8(h0, 2);
}
