/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Collects up to maxCount keys whose time range contains a moment, walking the key array circularly (inferred: the
 * time is reduced by a period when the index wraps). The moment is func_003DDF18 applied to baseTime + steps *
 * step (step is the float at +0x14), the period comes from func_003DDE78 and the first candidate index from
 * func_003DDF88. Keys are 0x7C bytes and have a start time at +4 and an end time at +8; a key is stored into found
 * when start <= t < end. When the index runs past the count it wraps to the start and t is reduced by the period;
 * if t did not decrease, the loop ends. Returns how many keys were stored. A negative first index returns 0. */
typedef float f32;

struct Key {
    int pad0;
    f32 t4;
    f32 t8;
    char padC[0x70];
};

struct Self {
    char pad0[0x14];
    f32 step;
    char pad18[8];
    int count;
    Key *keys;
};

extern "C" f32 func_003DDF18(Self *, f32) throw();
extern "C" f32 func_003DDE78(Self *) throw();
extern "C" int func_003DDF88(Self *, f32) throw();

extern "C" int func_003DDFF0(Self *self, Key **found, int maxCount, int steps, f32 baseTime) {
    f32 t = func_003DDF18(self, baseTime + (f32)steps * self->step);
    f32 period = func_003DDE78(self);
    int idx = func_003DDF88(self, t);
    int n = 0;
    if (idx >= 0) {
        while (self->keys[idx].t4 <= t && n < maxCount) {
            Key *key = (Key *)(idx * 0x7C + (int)self->keys);
            if (t < key->t8) {
                found[n++] = key;
            }
            idx++;
            if (idx >= self->count) {
                f32 previousTime = t;
                t -= period;
                idx -= self->count;
                if (!(t < previousTime))
                    return n;
            }
        }
    }
    return n;
}
