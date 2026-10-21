/* compiler: ee-gcc2.9-991111 */
struct Export { int a, b, c, d; };
struct Lists { struct Export *a, *b; };
extern int D_00657A80, D_00875860;
extern unsigned int D_0087585C;
extern struct Export D_0068AF2C;
extern char D_0068AF98[], D_0068B09C[];
extern char D_006CE500[], D_006CE528[], D_006CE540[], D_006CE550[];
extern void func_00583BA0(void);
extern int func_00583D40(void);
extern int func_00583D98(void *, unsigned int);
extern void *func_00584380(int *);
extern struct Lists *func_00585248(int *);
extern int func_00585268(int);
extern int func_00585B10(void *);
extern int func_00586DA0(int);
extern int *func_00586F70(int *);
extern void func_0058B150(unsigned int *, unsigned int *);
extern int func_0058B320(const char *, int, int, int, int, int *);
extern void *func_005A48D8(void *, int, unsigned int);
extern int func_005AE0F0(void);
extern void func_005B0750(const char *, ...);
extern int func_005B9278(int (*)(void *));
int func_00583718(int priority, void *start, unsigned int size, int max) {
    int n, status, result;
    void *p;
    struct Lists *list;
    int *state;
    if (D_00657A80 == 0) {
        p = func_00584380(&n);
        func_005A48D8(p, 0, n);
        list = func_00585248(&n);
        func_005A48D8(list, 0, n);
        list->b = &D_0068AF2C;
        list->a = &D_0068AF2C;
        D_0068AF2C.c = 0;
        D_0068AF2C.d = 0;
        state = func_00586F70(&n);
        func_005A48D8(state, 0, n);
        state[2] = -1;
        state[3] = -1;
        state[0] = -1;
        if (!func_00583D98(start, size)) return 0x8105000C;
        result = func_00585268(max);
        if (result < 0) return result;
        result = func_00586DA0(priority);
        if (result < 0) return result;
        D_00657A80 = 1;
        func_00583D40();
        func_00585B10(D_0068AF98);
        func_00585B10(D_0068B09C);
        result = func_005B9278(func_00585B10);
        if (result < 0) {
            func_005B0750(D_006CE500, result);
            for (;;) {}
        }
        if (func_005AE0F0() & 0x100) goto fallback;
        {
            result = func_0058B320(D_006CE528, 0, 0, 0, 0, &status);
            if (result < 0) {
                result = func_0058B320(D_006CE540, 0, 0, 0, 0, &status);
                if (result < 0) {
                    func_005B0750(D_006CE550, result);
                    goto fallback;
                }
            }
            if (result == 0 && status == 1) {
fallback:
                func_00583BA0();
                D_00875860 = -1;
            } else {
                D_00875860 = result;
            }
        }
        func_0058B150(&D_0087585C, 0);
    }
    return 0;
}
