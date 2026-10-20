/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0057D8A0(float *, float *, float);
struct Quaternion { float x, y, z, w; };
extern "C" void func_0048D510(Quaternion *, const Quaternion *);
/* Left-multiply the destination by an axis-angle quaternion. The caller supplies
 * the axis; this helper does not normalize it. Reference-based component access
 * follows the recovered vector-library siblings. */
static inline float &component(Quaternion *vector, const int &index) {
    return *(float *)((char *)vector + index * sizeof(float));
}
static inline const float &component(const float *vector, const int &index) {
    return vector[index];
}
extern "C" void func_004878C0(Quaternion *destination, const float *axis, float angle) {
    float sine, cosine;
    Quaternion rotation;
    func_0057D8A0(&sine, &cosine, angle * 0.5f);
    Quaternion *q = &rotation;
    q->x = axis[0] * sine;
    component(q, 1) = component(axis, 1) * sine;
    component(q, 2) = component(axis, 2) * sine;
    q->w = cosine;
    func_0048D510(destination, q);
}
