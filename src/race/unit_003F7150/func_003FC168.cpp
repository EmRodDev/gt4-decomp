/* Per-frame (1/60 s) update of one of three small timer-driven state entries at +0x78 (0x14 bytes each), selected by idx. State "active" is
 * byte 1 of the flags. Inactive: chargeTime grows, clamped to 0..30; while conditionHeld stays true holdTimer counts up, and past triggerHold
 * the entry becomes active for durationStart, with a chance (curve at +0xB4 sampled at chargeTime/30, times curveScale, compared with
 * a draw from func_00578598 on the pointer at +4, which 0040AA48 uses as a random-number threshold; inferred) of instead setting byte 0 and a longer durationHit and resetting chargeTime. Active: remaining counts
 * down and the entry ends when holdTimer passes releaseHold or remaining < 0. The field names are inferred from the arithmetic; what the
 * entries model in game terms is purpose unknown. */
struct Ent { float chargeTime, holdTimer, remaining; int pad; unsigned flags; };
struct Obj { char p0[4]; void *o4; char p1[0x70]; Ent entry[3]; };
extern "C" float func_0036F778(void *, float);
extern "C" float func_00578598(void *);

extern "C" void func_003FC168(Obj *self, int idx, int conditionHeld, float curveScale, float triggerHold, float releaseHold, float durationHit, float durationStart)
{
    Ent *entry = (Ent *)((char *)self + idx * 0x14 + 0x78);
    float timeStep = 0.016666666f;
    unsigned flagsNoByte0 = entry->flags & ~0xFFu;
    entry->flags = flagsNoByte0;
    if (((unsigned char *)&entry->flags)[1] != 0) {
        entry->remaining = entry->remaining - timeStep;
        if (conditionHeld != 0) {
            entry->holdTimer = 0.0f;
        } else {
            float updated = entry->holdTimer + timeStep;
            entry->holdTimer = updated;
            if (releaseHold < updated) {
                entry->holdTimer = 0.0f;
                entry->flags = flagsNoByte0 & 0xFFFF00FFu;
            }
        }
        if (entry->remaining < 0.0f) {
            entry->holdTimer = 0.0f;
            entry->flags = entry->flags & 0xFFFF00FFu;
        }
    } else {
        float updated = entry->chargeTime + timeStep;
        entry->chargeTime = updated;
        if (updated <= 0.0f) entry->chargeTime = 0.0f;
        if (entry->chargeTime >= 30.0f) entry->chargeTime = 30.0f;
        if (conditionHeld != 0) {
            float updatedHold = entry->holdTimer + timeStep;
            entry->holdTimer = updatedHold;
            if (triggerHold < updatedHold) {
                entry->remaining = durationStart;
                entry->holdTimer = 0.0f;
                entry->flags = (entry->flags & 0xFFFF00FFu) | 0x100;
                float chance = func_0036F778((char *)self + 0xB4, entry->chargeTime / 30.0f) * curveScale;
                if (func_00578598(self->o4) < chance) {
                    entry->remaining = durationHit;
                    entry->chargeTime = 0.0f;
                    entry->flags = (entry->flags & ~0xFFu) | 1;
                }
            }
        } else {
            entry->holdTimer = 0.0f;
        }
    }
}
