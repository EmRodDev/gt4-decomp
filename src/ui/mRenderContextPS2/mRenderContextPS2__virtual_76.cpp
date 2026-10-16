/* compiler: ee-gcc2.96-nogcse */
struct Vec2 {
    float x, y;
    void add(const Vec2 &a, const float &tx, const float &ty) { x = a.x + tx; y = a.y + ty; }
    void mul(const Vec2 &a, const float &sx, const float &sy) { x = a.x * sx; y = a.y * sy; }
};
struct Mat {
    float m[9];
    bool isTranslation() const {
        return m[0] == 1.0f && m[1] == 0.0f && m[2] == 0.0f && m[3] == 0.0f &&
               m[4] == 1.0f && m[5] == 0.0f && m[8] == 1.0f;
    }
};
extern "C" void func_00218430(void *self, Vec2 *p, float f) throw();
extern "C" Mat *func_002314E8(void *self);
extern "C" void func_0048D000(Vec2 *out, const Mat *m, const Vec2 *v);
extern "C" void func_004A1638(int);
extern "C" void func_004AB040(int);
extern "C" void mRenderContextPS2__virtual_76(void *self, Vec2 *pts, int count, Vec2 *scale, float width) {
    Vec2 v[2];
    Mat *t = 0;
    Mat *m = func_002314E8(self);
    if (m->isTranslation()) t = m;
    int n = count - 1;
    func_004A1638(9);
    for (int i = 0; i < n; i += 2) {
        const float *sy = &scale->y;
        for (int j = 0; j < 2; j++) {
            Vec2 p;
            p.mul(pts[i + j], scale->x, *sy);
            Vec2 *d = &v[j];
            if (t) {
                d->add(p, t->m[6], t->m[7]);
            } else {
                func_0048D000(d, m, &p);
            }
        }
        func_00218430(self, v, width);
    }
    func_004AB040(9);
}
