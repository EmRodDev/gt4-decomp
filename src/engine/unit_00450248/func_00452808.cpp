/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Draws a model set and then a second one four times (inferred from the calls to ModelSet2__begin / ___render / __end). The first
 * model set (self->mid->f18, with the object returned by func_00450FE0) is drawn once with the global colour block D_008465B0
 * (meaning of its four floats unknown). If `other` is given it is drawn again for each of four 14-float placement records at
 * self+0x94, odd ones mirrored in x (the sign flip of record value 6). That the four placements are the car's four wheels is only a guess
 * (four mirrored placements); no evidence beyond that. */
struct G { float a, b, c, d; };
struct Mid { char pad[0x18]; void *f18; };
struct Self {
    Mid *mid;
    char pad[0x94 - 4];
};
struct Item {
    float v[14];
};
struct Obj2 { char pad[0x7C]; void *f7C; };
struct Arg1;

extern G D_008465B0;

extern "C" {
Arg1 *func_00450FE0(Self *) throw();
void func_00454110(float *, int);
void ModelSet2__begin(void *, void *);
void ModelSet2__end(void *);
void ModelSet2___render(void *, int, void *);
void func_004A29A8(int);
void func_004A53F8();
void func_004A5400();
void func_004A60E0(float, float, float, float);
void func_004A6100(float, float, float, float);
void func_004A7890(float, float, float);
void func_004AB040(int);
}

static inline void *getObj(Self *self) {
    Mid *m = self->mid;
    if (!m) return 0;
    return m->f18;
}

extern "C" void func_00452808(int selfAddr, Obj2 *other) {
    Self *self = (Self *)selfAddr;
    void *obj = getObj(self);
    void *extra = func_00450FE0(self);
    if (obj != 0 && extra != 0) {
        ModelSet2__begin(obj, extra);
        func_004A6100(D_008465B0.a, D_008465B0.b, D_008465B0.c, 0.0f);
        func_004A60E0(1.0f, 1.0f, 1.0f, D_008465B0.d);
        ModelSet2___render(obj, 1, extra);
        ModelSet2__end(obj);
        if (other != 0) {
            extra = (char *)self + 0x94;
            void *otherParam = other->f7C;
            int i = 0;
            ModelSet2__begin(other, otherParam);
            func_004A6100(D_008465B0.a, D_008465B0.b, D_008465B0.c, 0.0f);
            func_004A60E0(1.0f, 1.0f, 1.0f, D_008465B0.d);
            func_004A29A8(0);
            func_004AB040(5);
            for (; i < 4; i++) {
                int flip = i & 1;
                func_004A53F8();
                func_00454110(((Item *)extra)->v, flip);
                float y = ((Item *)extra)->v[8];
                float x = ((Item *)extra)->v[6];
                extra = (Item *)extra + 1;
                if (flip != 0) {
                    x = -x;
                }
                func_004A7890(x, y, y);
                ModelSet2___render(other, 0, otherParam);
                func_004A5400();
            }
            ModelSet2__end(other);
        }
    }
}
