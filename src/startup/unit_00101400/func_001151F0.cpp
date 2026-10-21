/* Initializer for a race player: calls func_003BB440 with D_00622F4C + 0x44, makes a virtual call (table entry at +0x98) to get a
 * RaceSpec (inferred from the callee SPEC_DATABASE__RaceSpec__getEnemyCode), reads the enemy code and a second value from it
 * (func_00447458, minus 1, or 0 when the value is -1) and creates the equipments of the RacePlayerSpec embedded at +0x130. */
#include "types.h"
struct VEnt { short adj; short pad; s32 (*fn)(void *); };
struct Vt { char pad[0x98]; VEnt e98; };
struct Self { char pad[0x12C]; Vt *vt; char pad2[0x130 - 0x130]; };
extern s32 D_00622F4C;
extern "C" void func_003BB440(void *, s32);
extern "C" void RacePlayerSpec__createEquipments(void *, long, int, int);
extern "C" s32 SPEC_DATABASE__RaceSpec__getEnemyCode(void *, s32);
extern "C" long func_00447458(void *, s32);

extern "C" void func_001151F0(Self *self) {
    func_003BB440(self, D_00622F4C + 0x44);
    VEnt *entry = &self->vt->e98;
    void *raceSpec = (void *)entry->fn((char *)self + entry->adj);
    s32 enemyCode = SPEC_DATABASE__RaceSpec__getEnemyCode(raceSpec, 0);
    long rawValue = func_00447458(raceSpec, 0);
    long equipmentIndex = rawValue - 1;
    if (~rawValue == 0) equipmentIndex = 0;
    RacePlayerSpec__createEquipments((char *)self + 0x130, enemyCode, (int)equipmentIndex, 1);
}
