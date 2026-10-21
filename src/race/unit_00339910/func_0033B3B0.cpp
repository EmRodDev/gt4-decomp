/* Interpolates between the two stored keys (17 floats each, 'current' and the other) with factor t into 9 values and applies them with
 * func_0049A928. Nine values could be eye, target and up vectors of a camera, but that is a guess from the count. */
struct Key { float v[17]; };

struct Obj {
    int unk0;
    Key keys[2];
    int current;
};

extern "C" void func_0033B358(float *out, int n, const float *a, const float *b, float t);
extern "C" void func_0049A928(float a0, float a1, float a2, float a3, float a4, float a5, float a6,
                              float a7, float a8);

extern "C" void func_0033B3B0(Obj *self, float t) {
    float v[9];
    func_0033B358(v, 9, self->keys[1 - self->current].v, self->keys[self->current].v, t);
    func_0049A928(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8]);
}
