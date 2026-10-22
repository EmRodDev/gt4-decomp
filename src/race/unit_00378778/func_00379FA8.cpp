/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Configures a smoothing effect object embedded at +0x238 (two floats f0 and f4) from a level index stored at
 * +0x1B4. func_0036F948 is first called with constants 0.1, 0.3, 1.0 and 0.01 and the setters
 * func_0036F968/970/978 with 0, 0 and 0.5; the same calls are then repeated with values derived from
 * func_00578598(level) (0.3 times it, 40 times it minus 20, 0.5 times it plus 0.2), so the first block is
 * overwritten later; both blocks are kept because the calls cannot be removed. When snapFlag is set, f4 is copied
 * from f0 (inferred: the current value jumps to the target). Finally the float amount is stored at +0x260 and the
 * byte at +0x264 (bit field inside the 64-bit word at +0x260) is set to 1. The hex float literals are the exact
 * values that matched. */
typedef unsigned long long u64;

struct Fx {
    float f0;
    float f4;
};
struct Obj {
    char pad0[0x1B4];
    int level;
    char pad1B8[0x238 - 0x1B8];
    Fx fx;
    char pad240[0x260 - 0x240];
    float f260;
    char b264;
};

extern "C" void func_0036F948(Fx *, float, float, float, float) throw();
extern "C" void func_0036F968(Fx *, float) throw();
extern "C" void func_0036F970(Fx *, float) throw();
extern "C" void func_0036F978(Fx *, float) throw();
extern "C" float func_00578598(int);

extern "C" void func_00379FA8(Obj *self, int snapFlag, float amount) {
    Fx *fx = &self->fx;
    int levelIndex = self->level;
    func_0036F948(fx, 0x1.999998p-4f, 0x1.333332p-2f, 1.0f, 0x1.47ae14p-7f);
    func_0036F968(fx, 0.0f);
    func_0036F970(fx, 0.0f);
    func_0036F978(fx, 0.5f);
    func_0036F948(fx, 0x1.999998p-4f, func_00578598(levelIndex) * 0x1.333332p-2f, 1.0f, 0x1.47ae14p-7f);
    func_0036F968(fx, func_00578598(levelIndex) * 40.0f - 20.0f);
    func_0036F970(fx, func_00578598(levelIndex) * 40.0f - 20.0f);
    if (snapFlag != 0) fx->f4 = fx->f0;
    func_0036F978(fx, func_00578598(levelIndex) * 0.5f + 0x1.999998p-3f);
    self->f260 = amount;
    *(u64 *)((char *)self + 0x260) = (*(u64 *)((char *)self + 0x260) & 0xFFFFFF00FFFFFFFFull) | 0x100000000ull;
}
