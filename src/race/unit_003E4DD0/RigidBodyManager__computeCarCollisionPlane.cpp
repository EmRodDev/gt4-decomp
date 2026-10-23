static inline float absf_(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
struct V4 { float x, y, z, w; };
struct Mgr { int pad0; int count; };
extern Mgr *RigidBodyManager__carCollision_;
extern V4 D_00621D28[];
extern V4 D_006A3978[5];
extern "C" int func_00343BF0(int);
extern "C" float func_003E21A8(void *, void *) throw();
extern "C" void func_004A7454();
extern "C" void func_004A7844(float, float, float);
extern "C" void func_004A79B0(float);
extern "C" void func_004A7AA8(void *, void *);

extern "C" void RigidBodyManager__computeCarCollisionPlane() {
    int count = RigidBodyManager__carCollision_->count;
    for (int i = 0; i < count; i++) {
        char *e = (char *)RigidBodyManager__carCollision_ + i * 0x4F0;
        char *s1 = e + 0xC;
        if (func_00343BF0(*(int *)(s1 + 0x450)) != 0) continue;
        float *vec = (float *)(e + 0x460);
        float fx = *(float *)(s1 + 0x48C);
        float fz = *(float *)(s1 + 0x490);
        float fy = *(float *)(s1 + 0x494);
        float up = 1.5f;
        func_004A7454();
        func_004A7844(vec[0], vec[2], -vec[1]);
        float *ang = (float *)(e + 0x480);
        if (0x1.921fb4p+6f < absf_(*ang)) *ang = 0.0f;
        func_004A79B0(*ang * 0x1.ca5dc2p+5f);
        V4 pts[6] = {
            {fy, 0.0f, -fx, 1.0f},
            {-fy, 0.0f, -fx, 1.0f},
            {-fy, 0.0f, fz, 1.0f},
            {fy, 0.0f, fz, 1.0f},
            {0.0f, up, 0.0f, 1.0f},
            {0.0f, 0.0f, 0.0f, 1.0f},
        };
        V4 xf[6];
        int j;
        for (j = 0; j < 6; j++) func_004A7AA8(&xf[j], &pts[j]);
        for (j = 0; j < 5; j++) {
            V4 *q = &D_00621D28[i * 5 + j];
            func_004A7AA8(q, &D_006A3978[j]);
            q->w = -func_003E21A8(q, &xf[j]);
        }
    }
}
