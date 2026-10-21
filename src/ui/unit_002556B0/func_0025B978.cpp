/* Returns a float produced by func_0025BB18 through its third argument (an out-parameter), called with the object's field at +0x34 (purpose unknown).
 * Sibling of func_0025B9D8, which passes the out-parameter in a different slot. */
typedef float f32;

struct C { char pad[0x34]; int f34; };
extern "C" void func_0025BB18(struct C *, int *, float *, float *, int, int);

extern "C" f32 func_0025B978(struct C *obj) {
    float result;
    func_0025BB18(obj, &obj->f34, &result, 0, 0, 0);
    return result;
}
