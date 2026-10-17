/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Voice {
    char pad00[0x34];
    int stateIndex;
    char pad38[0x14];
    float accum;
    char pad50[0x10];
    int state;
};
typedef void (Voice::*Handler)();
extern Handler D_006C89F8[];
extern "C" unsigned long func_0055A810(Voice *);
extern "C" int func_0055B360(Voice *v) {
    (v->*D_006C89F8[v->stateIndex >> 4])();
    int done = 0;
    if (v->state != 3) {
        v->accum += (float)func_0055A810(v);
    } else {
        done = 1;
    }
    return done;
}
