/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Computes a point from three virtual getters of an object and rotates it. The getters at vtable slots 1, 2 and 3
 * are called with 0.0 for x, y and z; z gets -6.25 added (a fixed offset behind the object, inferred from the
 * sign). A rotation is then built from xAngle and yAngle with func_00487C68 (two angles wrapped in the 16-byte-
 * aligned Angle struct so they are passed by reference to setRotation), and func_00421DF8 applies it to the point,
 * returning a 16-byte vector in a register (the Vec union copies the whole quad word); the x, y, z of that vector
 * are written to the three outputs. The + 0.0f additions on x and y are kept as in the matched source. */
typedef unsigned int u128 __attribute__((mode(TI)));
typedef float f32;

struct Quat { f32 x, y, z, w; } __attribute__((aligned(16)));
union Vec {
    struct { f32 x, y, z, w; };
    u128 q;
    Vec() {}
    Vec(const Vec &v) { q = v.q; }
    f32 X() const { return x; }
    f32 Y() const { return y; }
    f32 Z() const { return z; }
};
struct Angle { f32 value; Angle(f32 f) : value(f) {} } __attribute__((aligned(16)));

struct Obj {
    virtual void v0();
    virtual f32 getX(f32 t);
    virtual f32 getY(f32 t);
    virtual f32 getZ(f32 t);
};

extern "C" Vec func_00421DF8(void *m, f32 x, f32 y, f32 z);
extern "C" void func_00487C68(Quat *q, f32 x, f32 y);

static inline void setRotation(Quat *q, const Angle &x, const Angle &y) { func_00487C68(q, x.value, y.value); }

extern "C" void func_0040DC08(Obj *source, f32 *outX, f32 *outY, f32 *outZ, f32 yAngle, f32 xAngle) {
    *outX = source->getX(0.0f) + 0.0f;
    *outY = source->getY(0.0f) + 0.0f;
    *outZ = source->getZ(0.0f) + -6.25f;
    Quat q;
    Angle ax(xAngle);
    Angle ay(yAngle);
    setRotation(&q, ax, ay);
    Vec rotated = func_00421DF8(&q, *outX, *outY, *outZ);
    *outX = rotated.X();
    *outY = rotated.Y();
    *outZ = rotated.Z();
}
