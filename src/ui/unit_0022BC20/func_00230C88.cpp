/* Zeroes the four floats at +0x1D14 of the object while holding the global lock D_0082E550 (func_005769F0 / func_00576A28 are lock and unlock, inferred from the mutex comment in the source).
 * The temporary zero array and the self-assignment guard are the compiler expansion of a Vec4 assignment from a zero vector. */
extern char D_0082E550[]; /* mutex */
extern "C" void func_005769F0(int obj);
extern "C" void func_00576A28(int obj);

extern "C" void func_00230C88(void *obj)
{
    float zeroVec[4];
    float *vec;
    float zeroValue;

    func_005769F0((int)D_0082E550);
    zeroValue = 0.0f;
    vec = (float *)((char *)obj + 0x1D14);
    zeroVec[0] = zeroValue;
    zeroVec[1] = zeroValue;
    zeroVec[2] = zeroValue;
    zeroVec[3] = zeroValue;
    if (vec != zeroVec) {
        vec[0] = zeroValue;
        vec[1] = zeroValue;
        vec[2] = zeroValue;
        vec[3] = zeroValue;
    }
    func_00576A28((int)D_0082E550);
}
