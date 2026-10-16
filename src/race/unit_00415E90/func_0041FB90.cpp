/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int U128 __attribute__((mode(TI)));
extern "C" void func_00487A58(U128 *, float);
extern "C" void func_004879A0(U128 *, float);
extern "C" U128 *func_0041FB90(U128 *out, float *a) {
    U128 temp;
    float angle[4];
    float *p = angle;
    float x = a[1];
    p[0] = x;
    func_00487A58(&temp, x);
    x = -a[0];
    p[0] = x;
    func_004879A0(&temp, x);
    *out = temp;
    return out;
}
