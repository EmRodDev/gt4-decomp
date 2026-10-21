/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Resets the car's dynamics block (the part at Car+0x104) to its initial state: zeroes the per-wheel fields for each
 * wheel the car has, clears most working fields, sets a few to 1.0 / -f54 / +f54 / 0x7F, and calls the sub-resets
 * func_00363538, func_0036BEB8, func_00353ED8 and func_00363018 before returning func_0035A638. Most fields are only
 * named by offset because their meaning is purpose unknown; the ones that are known (rpm, gear number) are in
 * func_003519B8. Flag u523 is set for gear types 4-6 and 9, u524[i] for drive types 3 and 4 (both read from the
 * engine record; the type numbers' meaning is purpose unknown). */
typedef unsigned char u8;
typedef signed char s8;
typedef short s16;

struct Info {
    u8 b0;
    u8 count;
};
struct Eng {
    char pad0[0x54];
    float f54;
    char pad58[0x234 - 0x58];
    u8 gear;                /* 0x234 */
    char pad235[0x244 - 0x235];
    u8 type[2];             /* 0x244 */
};
struct Wheel {
    char pad0[0x20];
    int i20;
    char pad24[4];
    int i28;
    int i2C;
    int i30;
    char pad34[0x3C - 0x34];
    float f3C;
    char pad40[0x46 - 0x40];
    s8 b46;
    char pad47[0x60 - 0x47];
    int i60;
    int i64;
    int i68;
    int i6C;
    int i70;
    int i74;
    char pad78[0xEC - 0x78];
};
struct Sub {                /* at Car + 0x104 */
    char pad0[0x60];
    Wheel wheel[4];         /* 0x60 */
    char pad410[0x430 - 0x410];
    int i430[4];
    char pad440[0x442 - 0x440];
    u8 u442;
    char pad443[0x444 - 0x443];
    float f444;
    char pad448[0x454 - 0x448];
    s16 h454;
    s16 h456;
    s16 h458;
    s16 h45A;
    int i45C;
    s8 b460;
    s8 b461;
    char pad462[0x466 - 0x462];
    s8 b466;
    u8 u467;
    int i468;
    int i46C;
    int i470;
    int i474;
    int i478;
    int i47C;
    int i480;
    int i484;
    int i488;
    int i48C;
    char pad490[0x494 - 0x490];
    int i494;
    float f498;
    float f49C;
    int i4A0;
    char pad4A4[0x4B5 - 0x4A4];
    s8 b4B5;
    char pad4B6[0x4E8 - 0x4B6];
    float f4E8;
    float f4EC;
    float f4F0;
    s16 h4F4;
    s16 h4F6;
    s16 h4F8;
    s16 h4FA;
    float f4FC;
    float f500;
    float f504;
    float f508;
    char pad50C[0x514 - 0x50C];
    float f514;
    char pad518[0x51C - 0x518];
    int i51C;
    char pad520;
    s8 b521;
    s8 b522;
    u8 u523;
    u8 u524[2];
    s8 b526;
    s8 b527;
    s8 b528;
    s8 b529;
    s16 h52A;
    int i52C[2];
    char pad534[0x53C - 0x534];
    float f53C;
    float f540;
    int i544;
    int i548;
    int i54C;
    int i550;
    int i554;
    int i558;
    char pad55C[0x564 - 0x55C];
    int i564;
    char pad568[0x57C - 0x568];
    int i57C;
    float f580;
    float f584;
    int i588;
    int i58C;
    char pad590[0x59C - 0x590];
    int i59C;
    int i5A0;
    char pad5A4[0x5A8 - 0x5A4];
    int i5A8;
    int i5AC;
    char pad5B0[0x5BC - 0x5B0];
    int i5BC;
    char pad5C0[0x5C8 - 0x5C0];
    float f5C8;
    char pad5CC[0x5F8 - 0x5CC];
    s8 b5F8;
    s8 b5F9;
    char pad5FA[0x604 - 0x5FA];
    s8 b604;
    s8 b605;
    s8 b606;
    s8 b607;
    char pad608[0x610 - 0x608];
    float f610;
    char pad614[0x65C - 0x614];
    int i65C;
    int i660;
};
struct Car {
    char pad0[0x10];
    Eng *eng;               /* 0x10 */
    char pad14[0x104 - 0x14];
    Sub sub;                /* 0x104 */
};

extern "C" Info *func_00359510(Eng *e) throw();
extern "C" void func_00363538(Car *self, float v) throw();
extern "C" void func_0036BEB8(Car *self, int gear);
extern "C" void *func_00353EB8(Car *self) throw();
extern "C" void func_00353EA0(void *p) throw();
extern "C" void func_00353ED8(Sub *s) throw();
extern "C" void func_00363018(Car *self) throw();
extern "C" int func_0035A638(Car *self) throw();

extern "C" int func_00363560(Car *self) {
    Sub *dyn = &self->sub;
    Eng *eng = self->eng;
    Info *info = func_00359510(eng);
    unsigned index;

    for (index = 0; index < info->count; index++) {
        Wheel *wheel = &self->sub.wheel[index];
        wheel->i30 = 0;
        wheel->i60 = 0;
        wheel->i6C = 0;
        wheel->i68 = 0;
        wheel->i70 = 0;
        wheel->i74 = 0;
        wheel->i28 = 0;
        wheel->i2C = 0;
        wheel->i20 = 0;
        wheel->b46 = 0;
        wheel->f3C = 1.0f;
        self->sub.i430[index] = 0;
    }
    for (index = 0; index < 2; index++) {
        dyn->u524[index] = 0;
        u8 driveType = eng->type[index];
        if (driveType == 3 || driveType == 4) dyn->u524[index] = 1;
        dyn->i52C[index] = 0;
    }
    dyn->u523 = 0;
    u8 gearType = eng->gear;
    if ((gearType >= 4 && gearType <= 6) || gearType == 9) dyn->u523 = 1;
    dyn->i51C = 0;
    dyn->f444 = 1.0f;
    dyn->i480 = 0;
    dyn->i468 = 0;
    dyn->f498 = -eng->f54;
    dyn->f49C = eng->f54;
    dyn->i57C = 0;
    dyn->i484 = 0;
    dyn->i4A0 = 0;
    dyn->i46C = 0;
    dyn->i59C = 0;
    dyn->i5A0 = 0;
    dyn->i544 = 0;
    dyn->i548 = 0;
    dyn->i54C = 0;
    dyn->i45C = 0;
    dyn->b460 = 0;
    dyn->i488 = 0;
    dyn->i494 = 0;
    dyn->i48C = 0;
    for (index = 0; index < info->count; index++) self->sub.wheel[index].i64 = 0;
    dyn->f508 = 0.0f;
    dyn->b461 = 0;
    const float &cur = dyn->f508;
    float zero = cur;
    dyn->h4F6 = 0;
    dyn->f500 = zero;
    dyn->f504 = 0.0f;
    dyn->f4E8 = 0.0f;
    dyn->f4EC = 0.0f;
    dyn->f4F0 = zero;
    dyn->h4F4 = 0;
    dyn->h4F8 = 0;
    dyn->b607 = 0;
    dyn->b521 = 0;
    self->sub.f5C8 = zero;
    func_00363538(self, zero);
    func_0036BEB8(self, 1);
    dyn->h4FA = 0;
    dyn->b5F8 = 0;
    dyn->b5F9 = 0;
    dyn->f610 = zero;
    func_00353EA0(func_00353EB8(self));
    dyn->h454 = 0;
    dyn->h456 = 0;
    dyn->h458 = 0;
    dyn->h45A = 0;
    func_00353ED8(dyn);
    dyn->b604 = 0x7F;
    dyn->b605 = 0x7F;
    dyn->b606 = 0;
    func_00363018(self);
    dyn->f53C = zero;
    dyn->f540 = zero;
    dyn->b522 = 0;
    dyn->f514 = zero;
    dyn->f4FC = zero;
    dyn->f580 = zero;
    dyn->f584 = zero;
    dyn->b4B5 = 0;
    dyn->b526 = 0;
    if (dyn->b466 == 1 || dyn->u467 != 0 || dyn->u442 == 0 || dyn->u442 == 2)
        dyn->b526 = 0xC;
    dyn->h52A = 0;
    dyn->b527 = 0;
    dyn->b528 = 0;
    dyn->b529 = 0;
    dyn->i5A8 = 0;
    dyn->i5AC = 0;
    dyn->i550 = 0;
    dyn->i554 = 0;
    dyn->i558 = 0;
    dyn->i58C = 0;
    dyn->i588 = 0;
    dyn->i564 = 0;
    dyn->i5BC = 0;
    dyn->i470 = 0;
    dyn->i478 = 0;
    dyn->i474 = 0;
    dyn->i47C = 0;
    dyn->i65C = 0;
    dyn->i660 = 0;
    return func_0035A638(self);
}
