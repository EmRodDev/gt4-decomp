/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Looks a member up by key inside a script value and assigns 'value' to it (shape inferred from the calls; func_00476790 stores the
 * value). Dispatches on the value kind at +0: kind 7 searches the container at +4 of the inner object (func_004812C8 when
 * createIfMissing is set, func_00481230 otherwise, which can fail), kind 13 is only handled for the single key D_006AD678 and uses
 * func_0047A890 on the inner object, kinds 10 and 11 delegate to func_0047B640 / func_0047C970 on the embedded value at +4. Returns 1
 * on success, 0 when nothing was assigned. The kind numbers are not named anywhere yet (purpose of each unknown). */
typedef unsigned int u32;
struct N { int mode; N *f4; };
extern char D_006AD678[];
extern "C" void *func_00476790(void *, void *) throw();
extern "C" int func_0047A890(void *);
extern "C" int func_0047B640(void *, void *, void *, int);
extern "C" int func_0047C970(void *, void *, void *, int);
extern "C" void *func_00481230(void *, void *);
extern "C" void *func_004812C8(void *, void *);
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_005FBDD0(void *, const char *, u32, u32);

extern "C" int func_00477738(N *node, void *key, void *value, int createIfMissing) {
    switch (node->mode) {
    case 7: {
        void *slot;
        if (createIfMissing) {
            slot = func_004812C8((char *)node->f4 + 4, key);
            func_00476790(slot, value);
            return 1;
        } else {
            slot = func_00481230((char *)node->f4 + 4, key);
            if (!slot) return 0;
        }
        func_00476790(slot, value);
        return 1;
    }
    case 13: {
        if (func_005FBDD0(key, D_006AD678, 0, func_0057F260(D_006AD678)) != 0) return 0;
        void *slot = (void *)func_0047A890(node->f4);
        func_00476790(slot, value);
        return 1;
    }
    case 10:
        return func_0047B640((char *)node + 4, key, value, createIfMissing);
    case 11:
        return func_0047C970((char *)node + 4, key, value, createIfMissing);
    default:
        return 0;
    }
}
