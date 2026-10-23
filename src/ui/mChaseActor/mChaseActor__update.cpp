typedef struct {
    char pad0[0x18];
    float x;
    float y;
    float ax;
    float ay;
    float speed;
    int stopped;
    float angle;
} Chase;
extern "C" float func_0057D2B8(float);
extern "C" void mWidget__setWindowPosition(void *, float, float);

#define ABS(v) ((v) >= 0.0f ? -(v) : (v))

extern "C" void mChaseActor__update(Chase *self, void *arg, void *target) {
    float x = self->x;
    float y = self->y;
    if (self->stopped == 0) {
        float rad, ay, dx;
        int deg;
        self->angle += self->speed;
        deg = (int)self->angle % 360;
        rad = (int)self->angle % 360 / 180.0f * 3.1415927f;
        dx = func_0057D2B8(rad) * self->ax;
        ay = self->ay;
        { float t = ABS(func_0057D2B8(rad)) * ay; y += t; }
        x += dx;
        self->angle = deg;
    }
    mWidget__setWindowPosition(target, x, y);
}
