/* Builds the equipment of a race player from the race spec. After the base set-up func_003BB440 (called with the global block at
 * D_00622F4C + 0x44), a virtual call through slot +0x98 of the object's vtable returns the race spec; its enemy code and a second
 * 64-bit value are then passed to RacePlayerSpec::createEquipments on the member at +0x130. The second value is converted from a
 * 1-based to a 0-based number, with -1 mapped to 0 (the ~b == 0 test; inferred from the arithmetic). */
#include "types.h"
struct VEnt { short adj; short pad; s32 (*fn)(void *); };
struct Vt { char pad[0x98]; VEnt e98; };
struct Self { char pad[0x12C]; Vt *vt; char pad2[0x130 - 0x130]; };
extern s32 D_00622F4C;
extern "C" void func_003BB440(void *, s32);
extern "C" void RacePlayerSpec__createEquipments(void *, long, int, int);
extern "C" s32 SPEC_DATABASE__RaceSpec__getEnemyCode(void *, s32);
extern "C" long func_00447458(void *, s32);

extern "C" void func_0011BEC0(Self *self) {
    func_003BB440(self, D_00622F4C + 0x44);
    VEnt *getSpec = &self->vt->e98;
    void *raceSpec = (void *)getSpec->fn((char *)self + getSpec->adj);
    s32 enemyCode = SPEC_DATABASE__RaceSpec__getEnemyCode(raceSpec, 0);
    long secondValue = func_00447458(raceSpec, 0);
    long zeroBased = secondValue - 1;
    if (~secondValue == 0) zeroBased = 0;
    RacePlayerSpec__createEquipments((char *)self + 0x130, enemyCode, (int)zeroBased, 1);
}
