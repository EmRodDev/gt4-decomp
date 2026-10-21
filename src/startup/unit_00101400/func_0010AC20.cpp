/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Does its work between func_00576788 and func_005767C0 on the sub-object at +0x6C (inferred lock / unlock). With mode 0 it clears
 * +0xA0 and +0xA4 and makes the virtual call at table offset 0x90 with D_00618498; otherwise, if +0xA4 is set, it clears it and makes
 * the virtual call at table offset 0xA0. Meaning of the calls unknown. */
typedef int s32;
struct VEnt { short adj; short pad; void (*fn)(void *, ...); };
struct Vt { char pad[0x90]; VEnt e90; VEnt e98; VEnt eA0; };
struct Self {
    char pad[0x64]; Vt *vt; char pad1[0xA0 - 0x68]; s32 fA0; s32 fA4;
};
extern s32 D_00618498;
extern "C" void func_00576788(s32);
extern "C" void func_005767C0(s32);

extern "C" void func_0010AC20(Self *self, s32 mode) {
    s32 lockObject = (s32)self + 0x6C;
    func_00576788(lockObject);
    if (mode == 0) {
        self->fA4 = 0;
        Vt *vt = self->vt;
        self->fA0 = 0;
        VEnt *entry = &vt->e90;
        entry->fn((char *)self + entry->adj, D_00618498);
    } else if (self->fA4 != 0) {
        Vt *vt = self->vt;
        self->fA4 = 0;
        VEnt *entry = &vt->eA0;
        entry->fn((char *)self + entry->adj);
    }
    func_005767C0(lockObject);
}
