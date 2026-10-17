/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Chan { int id; char pad4[0x108]; int state; int timer; };
extern "C" void func_00555228(void *);
extern "C" void func_00555268(void *);
extern "C" void func_00555D10(void *, int, int, int, int);
struct Mix { Chan ch[8]; };
extern "C" void func_005555C0(Mix *mixer, int idx) {
    func_00555228(mixer);
    Chan *c = &mixer->ch[idx];
    int flag = 1;
    int fade = -0xFF;
    if (c->id != -1) {
        int *timer = &c->timer;
        int t = *timer;
        *timer = t + 1;
        if (t < 100) {
        } else if (t < 200) {
            fade = 0xFF;
        } else if (t < 300) {
            fade = 0;
        } else {
            fade = 0;
            c->state = 2;
            flag = 0;
        }
        func_00555D10(mixer, idx, fade, flag, 1);
    }
    func_00555268(mixer);
}
