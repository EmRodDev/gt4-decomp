/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Hook { char pad[0x18]; void (*fn)(int, int); int arg; };
extern Hook D_0064C480;
extern int D_00654D70;
extern int D_00654D88;
extern int D_00654D8C;
extern "C" void func_00563520();
extern "C" void func_00563668();
extern "C" int func_005637A8();
extern "C" void func_00563F30(int);
extern "C" void func_005ADCC0(int);
extern "C" int func_005ADCE0(int);
extern "C" int func_00563420() {
    while (func_005637A8() != 0) {
        int n = 0;
        func_00563520();
        do {
            func_00563F30(n++);
            func_005ADCE0(D_00654D8C);
            int flag = D_00654D88;
            if (flag == 1) {
                D_00654D88 = 0;
                func_005ADCC0(D_00654D8C);
                func_00563668();
                return 0;
            }
            func_005ADCC0(D_00654D8C);
        } while (func_005637A8() != 0);
        if (n != 0) D_0064C480.fn(D_0064C480.arg, D_00654D70);
    }
    func_00563668();
    return 0;
}
