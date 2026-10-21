/* Computes 1 / fptodp(seconds * 60) in double precision (soft-float helpers dpdiv/dptofp, so the code calls library routines instead of FPU ops), narrows it to float and passes it to func_002C3C70 with the object at +0x10.
 * What fptodp computes is unknown; the factor 60 suggests seconds to frames (inferred). */
struct Obj_0023F9C0 {
    char pad[0x10];
    void *unk10;
};

extern "C" double fptodp(float x);
extern "C" double dpdiv(double a, double b);
extern "C" float dptofp(double x);
extern "C" void func_002C3C70(void *obj, float seconds);

extern "C" void func_0023F9C0(Obj_0023F9C0 *obj, float seconds) {
    float result = dptofp(dpdiv(1.0, fptodp(seconds * 60.0f)));
    func_002C3C70(obj->unk10, result);
}
