/* Returns a float produced by func_0025BB18 through an out-parameter, called with the object's field at +0x34 (purpose unknown) and zeros for the other options.
 * Shares this shape with func_0025B978, which differs only in which output slot receives the result. */
typedef float f32;

struct C { char pad[0x34]; int f34; };
extern "C" void func_0025BB18(struct C *, int *, int, float *, int, int);

extern "C" f32 func_0025B9D8(struct C *obj) {
    float result;
    func_0025BB18(obj, &obj->f34, 0, &result, 0, 0);
    return result;
}
