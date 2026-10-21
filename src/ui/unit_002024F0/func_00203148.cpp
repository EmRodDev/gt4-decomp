/* Assigns four floats to a Vec4 (x, y, z, w; component names inferred from sibling func_002030E8 in the same unit) and returns nothing. */
struct Vec4 {
    float x;
    float y;
    float z;
    float w;
};

extern "C" void func_00203148(Vec4 *dst, float x, float y, float z, float w) {
    dst->x = x;
    dst->y = y;
    dst->z = z;
    dst->w = w;
}
