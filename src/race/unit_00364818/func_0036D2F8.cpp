/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Moves a share of some per-slot quantity between two paired slots of the car (inferred from the arithmetic; looks like a
 * steering-dependent load transfer between a wheel and its partner, but what the +0x84 value really is stays unknown).
 * For each entry of the table from func_00359510 it needs a partner slot (0x7F means none), a mode value of 6 or 7, a speed
 * at +0x53C inside a window and a non-zero weight. |steering| (+0x468) scaled and clamped to 1 times that weight is split 7/16 and 9/16
 * between the two slots, towards the one whose +0x20 value is below a steering-biased midpoint. The volatile read of the
 * +0x20 value only keeps the compiler's load order. */
typedef unsigned char u8;
typedef float f32;

struct State {u8 state; char pad[15]; u8 values[8];};
struct Obj {
    char pad0[0x234];
    u8 state;
    char pad235[3];
};
struct Wt { char pad0[0x10]; f32 f[8]; };
struct Pair {
    char pad0[2];
    u8 count;
    char pad3[9];
    u8 a[4];
    u8 b[0x14];
    u8 c[1];
    int get(int i) const { return i < count ? b[i] : 0; }
};
struct Slot { char pad0[0x20]; f32 f20; char pad24[0x60]; f32 f84; char pad88[0x64]; };
struct Car {
    char pad0[0x10];
    Obj *obj;
    char pad14[0x150];
    Slot slots[1];
};
struct Win { char pad0[0x468]; f32 f468; char pad46c[0xD0]; f32 f53C; };

extern "C" void func_00356418();
extern "C" Pair *func_00359510(Obj *);

extern "C" void func_0036D2F8(Car *self) {
    Obj *obj = self->obj;
    State *modeState = (State*)&obj->state;
    Win *drive = (Win *)((char *)self + 0x104);
    if (modeState->state == 7)
        func_00356418();
    Pair *slotTable = func_00359510(obj);
    for (int i = 0; i < slotTable->count; i++) {
        int slotIndex = slotTable->a[i];
        int partnerIndex = slotTable->c[slotIndex];
        if (partnerIndex == 0x7F)
            continue;
        int modeIndex = slotTable->get(i);
        int modeValue = modeState->values[modeIndex];
        if (modeValue < 0)
            continue;
        if (modeValue < 6)
            continue;
        if (modeValue >= 8)
            continue;
        f32 spd = drive->f53C;
        if (spd < 0x1.638e36p+1f || spd > 0x1.8ffffep+5f)
            continue;
        f32 steer = drive->f468;
        f32 steerScaled = steer < 0.0f ? -steer : steer;
        steerScaled = steerScaled * 0x1.e8ec90p+1f;
        if (steerScaled > 1.0f)
            steerScaled = 1.0f;
        Wt *weights = (Wt *)((char *)obj + 0x238);
        f32 shift = steerScaled * weights->f[modeIndex];
        if (shift == 0.0f)
            continue;
        Slot *slotA = &self->slots[slotIndex];
        Slot *slotB = &self->slots[partnerIndex];
        f32 mid = (slotA->f20 + slotB->f20) * 0.5f;
        f32 biasStep = mid * 0.125f;
        if (steer > 0.0f)
            mid += biasStep;
        else if (steer < 0.0f)
            mid -= biasStep;
        f32 smallShare = shift * 0.4375f;
        f32 largeShare = shift * 0.5625f;
        f32 currentValue = *(volatile f32*)&slotB->f20;
        if (currentValue < mid) {
            slotB->f84 = slotB->f84 + smallShare;
            slotA->f84 = slotA->f84 - largeShare;
        } else if (mid < currentValue) {
            slotB->f84 = slotB->f84 - largeShare;
            slotA->f84 = slotA->f84 + smallShare;
        }
    }
}
