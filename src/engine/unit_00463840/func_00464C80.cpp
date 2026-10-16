/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub {
    char p[0x467]; unsigned char state; char q[0x53c - 0x468];
    float speed; char r[4]; float x, y, z;
    char s[0x57c - 0x550]; float ax, ay, az;
};
struct Obj {
    char p[0x34]; float f34, f38; char q[0x52 - 0x3c]; unsigned char count;
    char r[0xe8 - 0x53]; char *owner;
};
extern "C" void func_003455C8(char *);
extern "C" float func_003F76E8(char *, float);
extern "C" void func_00464BB0(Obj *, float) throw();
extern "C" void func_00464ED8(Obj *);
static inline float root(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float fraction(unsigned long n) { return (float)(unsigned char)n * 0x1.111110p-5f; }
extern "C" void func_00464C80(Obj *o, float dt) {
    Sub *s = (Sub *)(o->owner + 0x104);
    func_00464ED8(o);
    func_00464BB0(o, dt);
    o->f34 = 0.0f;
    int stopped = 0;
    float x = s->x;
    float y = s->y;
    float ax = s->ax;
    float az = s->az;
    float z = s->z;
    float ay = s->ay;
    float speed = root(x * x + y * y + z * z);
    float angular = root(ax * ax + az * az + ay * ay);
    if (speed < 0x1.1c71c6p-4f && angular < 0x1.acee9cp-5f) stopped = 1;
    if (stopped) {
        o->f38 = 0.0f;
        return func_003455C8(o->owner);
    }
    if (s->state == 6) {
        unsigned char *count = &o->count;
        if (*count != 0) {
            float v = func_003F76E8(o->owner, s->speed - 0x1.1c71c6p-2f);
            o->f34 = v;
            unsigned char n = *count;
            if (n < 30) {
                float t = fraction(n);
                o->f34 = v * t;
                o->f38 = (1.0f - t) * 0.8f;
            }
            *count = (int)n + 0xff;
        } else o->f38 = 0.8f;
    } else o->f38 = 0.5f;
}
