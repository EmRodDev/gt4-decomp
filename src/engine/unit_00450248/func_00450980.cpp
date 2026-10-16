/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Slot {
    char pad[0x38];
};

struct Mat {
    float m[16];
};

struct Obj {
    s32 f0;
    char pad4[0x34];
    s32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
    s32 f48;
    char pad4C[0x10];
    float f5C;
    s32 f60;
    s32 f64;
    char pad68[0xC];
    s32 f74;
    s32 f78;
    s32 f7C;
    s32 f80;
    s32 f84;
    s32 f88;
    s32 f8C;
    float f90;
    Slot slots[4];
    char pad_1[0x174 - 0x94 - 4 * 0x38];
    s32 f174;
    char pad_2[0x578 - 0x178];
    Mat mat;
    s32 f5B8;
    s32 f5BC;
};

extern "C" s32 func_00453680(void *, s32);
extern "C" void func_004539F0(void *, s32);
extern "C" void func_004540E0(void *);

extern "C" int func_00450980(Obj *self)
{
    int tmp;
    Slot *s = self->slots;
    s32 n = 3;
    self->f0 = 0;
    func_00453680((char *)self + 4, (s32)self);
    func_004539F0((char *)self + 0xC, (s32)self);
    self->f38 = 0;
    self->f5C = 0.5f;
    self->f88 = 1;
    self->f8C = -1;
    self->f90 = 220.0f;
    self->f3C = 0;
    self->f40 = 0;
    self->f44 = 0;
    self->f48 = 0;
    self->f60 = 0;
    tmp = 1;
    self->f7C = 0;
    self->f80 = 0;
    self->f84 = 0;
    do {
        func_004540E0(s);
        s++;
        n--;
    } while (n != -1);
    self->f5B8 = 0;
    self->f5BC = 0;
    self->f64 = 0;
    self->f74 = 0;
    self->f78 = 0;
    self->f174 = tmp;
    float *m = self->mat.m;
    m[0] = 1.0f;
    m[4] = 0;
    m[8] = 0;
    m[12] = 0;
    m[1] = 0;
    m[5] = 1.0f;
    m[9] = 0;
    m[13] = 0;
    m[2] = 0;
    m[6] = 0;
    m[10] = 1.0f;
    m[14] = 0;
    m[3] = 0;
    m[7] = 0;
    m[11] = 0;
    m[15] = 1.0f;
    return 1;
}
