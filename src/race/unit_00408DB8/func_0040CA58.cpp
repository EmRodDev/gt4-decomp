/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Automatic-transmission style shift decision (inferred): rpm is an integer truncation of a float at +0x738 (func_00350F30), currentGear the
 * byte at +0x624. Gear 0 and the top gear (count at owner state +2) get an upshift threshold of 99999 and gears below 2 a downshift threshold
 * of -100000, which only makes sense as "no such shift exists" sentinels (inferred from those values). The function only ever writes 1 (or the
 * gear 1) into the outputs, never 0, so the caller must clear them first. input1/input2 are two float queries (func_00344698 / 003446A0),
 * probably throttle and brake (inferred from how they gate the thresholds: more downshift room when input2 is nonzero); outFlag3's exact
 * meaning (downshift past one gear while braking) is a guess. The only caller is the driver-support code in 00412018. */
typedef int s32;
typedef unsigned char u8;
struct St { char p[2]; u8 count; };
struct O { char p[0x234]; St state; };
struct S {
    char pad0[0x10];
    O *owner;
    char pad14[0x624 - 0x14];
    u8 f624;
};
extern "C" s32 func_00343BE0(S *);
extern "C" float func_00344698(S *);
extern "C" float func_003446A0(S *);
extern "C" s32 func_00350F30(S *);
extern "C" s32 func_0036BEE0(S *, s32);
extern "C" s32 func_0036BF28(S *, s32);
extern "C" s32 func_0036BF68(S *, float);

extern "C" void func_0040CA58(S *self, s32 *outShiftUp, s32 *outShiftDown, s32 *outFlag3, s32 *outTargetGear) {
    St *st = &self->owner->state;
    s32 rpm = func_00350F30(self);
    s32 gearCount = st->count;
    s32 currentGear = self->f624;
    func_00343BE0(self);
    float input1 = func_00344698(self);
    float input2 = func_003446A0(self);
    float *floats14 = (float *)((char *)self + 0x14);
    float lowerOfTwo = floats14[10] < floats14[9] ? floats14[10] : floats14[9];
    s32 targetGear = func_0036BF68(self, lowerOfTwo);
    if (outTargetGear) *outTargetGear = targetGear;
    s32 upshiftRpm;
    if (currentGear == 0 || currentGear == gearCount) upshiftRpm = 99999;
    else upshiftRpm = func_0036BEE0(self, currentGear);
    s32 downshiftRpm = (s32)0xFFFE7961;
    if (currentGear >= 2) downshiftRpm = func_0036BF28(self, currentGear);
    if (currentGear == 1) {
        if (upshiftRpm - 1000 < rpm)
            if (input1 > 0.2f) *outShiftUp = currentGear;
    } else if (upshiftRpm - 300 < rpm && input1 > 0.7f) {
        *outShiftUp = 1;
    }
    if (currentGear == targetGear) {
        if (rpm < downshiftRpm - 1000) *outShiftDown = 1;
    } else if (input1 > 0) {
        if (rpm < downshiftRpm) *outShiftDown = 1;
    } else if (input2 == 0) {
        if (rpm < downshiftRpm + 500) *outShiftDown = 1;
    } else {
        if (rpm < downshiftRpm + 1000) *outShiftDown = 1;
        if (targetGear > 0 && targetGear < currentGear) *outFlag3 = 1;
    }
}
