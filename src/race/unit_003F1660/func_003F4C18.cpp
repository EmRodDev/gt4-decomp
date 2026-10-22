/* compiler: ee-gcc2.96-no-strict-aliasing */
/* For each car: when the feature byte of D_006202B0 is on and the car's entry is not yet active,
 * projects the move since the saved position onto the car's two body axes (+0xC and +0x18) and,
 * if that sideways/forward displacement exceeds the threshold of D_006202C8, activates the entry
 * with a scaled push (capped at the limit); then copies the saved state back into the car. */
typedef unsigned char u8;
typedef int s32;
typedef float f32;

struct Control { char pad[0xA]; u8 enabled; };
struct Params { char pad[0x20]; f32 threshold; f32 limit; f32 base; f32 pad2C; f32 gain; };

struct Body {
    f32 pos[3];
    f32 axisA[3];
    f32 axisB[3];
    char pad24[0x544 - 0x24];
    f32 prev[3];
    char pad550[0x570 - 0x550];
    f32 f570;
    char pad574[0x57C - 0x574];
    f32 f57C;
};

struct Car {
    char pad0[0x104];
    Body body;
};

struct Push { char pad[0x1C]; f32 x; f32 y; s32 active; char pad28[8]; };

struct Saved {
    f32 pos[3];
    f32 cur[3];
    char pad18[8];
    f32 f20;
    char pad24[8];
    f32 f2C;
    char pad30[0x4F0 - 0x30];
};

struct Self {
    char pad0[0xCAB8];
    Push push[1];
    char padCAE8[0xDECC - 0xCAE8];
    Saved saved[1];
    char padE3BC[0xF8A0 - 0xE3BC];
    s32 count;
};

extern Control D_006202B0;
extern Params D_006202C8;

extern "C" Car *func_0034C190(Self *, s32);

extern "C" void func_003F4C18(Self *self) {
    for (s32 i = 0; i < self->count; i++) {
        Saved *sv = &self->saved[i];
        Push *pp = &self->push[i];
        Car *car = func_0034C190(self, i);
        Body *body = &car->body;
        if (D_006202B0.enabled) {
            if (pp->active == 0) {
                f32 delta[3];
                s32 j;
                for (j = 0; j < 3; j++)
                    delta[j] = sv->cur[j] - body->prev[j];
                f32 a = 0.0f;
                f32 b = 0.0f;
                for (j = 0; j < 3; j++) {
                    a += body->axisA[j] * delta[j];
                    b += body->axisB[j] * delta[j];
                }
                f32 sq = a * a + b * b;
                f32 mag;
                __asm__("sqrt.s %0, %1" : "=f"(mag) : "f"(sq));
                Params *p = &D_006202C8;
                f32 thr = p->threshold;
                if (thr < mag) {
                    f32 scale = 1.0f;
                    if (p->limit < mag) {
                        scale = p->limit / mag;
                        mag = p->limit;
                    }
                    scale *= (p->base + p->gain * (mag - thr)) / mag;
                    pp->active = 1;
                    pp->y = b * scale;
                    pp->x = a * scale;
                }
            } else {
                pp->active = 0;
            }
        } else {
            pp->active = 0;
        }
        for (s32 j = 0; j < 3; j++) {
            body->pos[j] = sv->pos[j];
            body->prev[j] = sv->cur[j];
        }
        body->f570 = sv->f20;
        body->f57C = sv->f2C;
    }
}
