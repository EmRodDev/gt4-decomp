/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Player {
    char pad0[0x34];
    int state;
    char pad1[0x4C - 0x38];
    float time;
    char pad2[0x60 - 0x50];
    int mode;
    int pad64;
    int pending;
};

typedef void (Player::*StateHandler)();

extern StateHandler D_006C8978[];
extern "C" long long func_0055A810(Player *);

extern "C" int func_0055ADB8(Player *self)
{
    (self->*D_006C8978[self->state >> 4])();
    int done = 0;
    if (self->mode != 3) {
        if (self->pending == 0) {
            long long elapsed = func_0055A810(self);
            self->time += (float)(unsigned long long)elapsed;
        } else {
            self->pending = 0;
        }
    } else {
        done = 1;
    }
    return done;
}
