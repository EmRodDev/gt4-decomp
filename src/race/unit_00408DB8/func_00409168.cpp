/* compiler: ee-gcc2.96-no-strict-aliasing */
struct DynamicsConductor;
struct RaceCourse;

struct LicenseConcourse {
    char unk_0[0x14];
    int unk14;
    int unk18;
};

extern "C" void func_004083B0(LicenseConcourse *, float) throw();
extern "C" void func_004091E8(LicenseConcourse *, float);
extern "C" int LicenseConcourse__update_mode(LicenseConcourse *, float, DynamicsConductor *, RaceCourse *);

extern "C" void func_00409168(LicenseConcourse *self, DynamicsConductor *dc, RaceCourse *rc, float f) {
    if (!self->unk18) return;
    func_004083B0(self, f);
    if (!self->unk14) return;
    LicenseConcourse__update_mode(self, f, dc, rc);
    func_004091E8(self, f);
}
