/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Sums two quantities over the slots (0xEC bytes apart from +0x164) listed in a per-variant record (func_00359510 picks the record from a
 * table by a byte of the block at +0x10; the record holds a slot count and per-slot table indices and signs). For each slot term =
 * func_0057D1F0(angle) * (float70 + float74) * tableA[aIndex]; outA accumulates term * tableB[cIndex] and outB accumulates term divided
 * by a table value, added or subtracted according to the slot's sign in the record. The slots are probably wheels, but that is not
 * established; what outA and outB are in physical terms is purpose unknown. */
typedef int s32; typedef float f32; typedef unsigned char u8; typedef signed char s8;

struct Rec { char pad0[1]; u8 slotCount; char pad2[0x12]; u8 a[0x18]; u8 cIndex[0x10]; s8 d[0x10]; };
struct Tbl { char pad0[0x10]; f32 f10[71]; };
struct Car { f32 ang; char pad4[0x6C]; f32 f70, f74; char pad78[0xEC - 0x78]; };
struct Obj { char pad0[0x10]; Tbl *tbl; char pad14[0x164 - 0x14]; Car slot[1]; };

extern "C" Rec *func_00359510(Tbl *);
extern "C" f32 func_0057D1F0(f32);

static inline int isPos(Rec *record, s32 i, int slotCount) { int result = 0; if (i < slotCount) result = record->d[i] > 0; return result; }
static inline int isNeg(Rec *record, s32 i, unsigned slotCount) { int result = 0; if ((long)i < slotCount) result = record->d[i] < 0; return result; }

extern "C" void func_0036AF30(Obj *self, f32 *outA, f32 *outB) {
    f32 sumB = 0.0f, sumA = 0.0f;
    s32 i;
    Tbl *table = self->tbl;
    Rec *record = func_00359510(table);
    for (i = 0; i < record->slotCount; i++) {
        f32 *tableA = (f32 *)((char *)table + 4);
        f32 *tableB = (f32 *)((char *)table + 0xC);
        u8 aIndex = 0;
        if (i < record->slotCount) aIndex = record->a[i];
        u8 cIndex = record->cIndex[i];
        Car *slot = &self->slot[i];
        f32 term = func_0057D1F0(slot->ang) * (slot->f70 + slot->f74) * tableA[aIndex + 0xB0];
        sumA += term * tableB[cIndex + 0x48];
        unsigned slotCount = record->slotCount;
        if (isPos(record, i, slotCount)) {
            sumB += term / table->f10[cIndex];
        } else if (isNeg(record, i, slotCount)) {
            sumB -= term / table->f10[cIndex];
        }
    }
    *outA = sumA;
    *outB = sumB;
}
