/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Recomputes the value at +0x4C of every slot (stride 0xEC from self+0x164, count taken from the table returned by
 * func_00359510) as slot+0x48, scaled by a lookup (func_00359830 over func_003573A8), by slot+0x50 when func_00356EF0 reports a
 * flag, by a per-index table entry, an item table entry and func_00467470. A difference of two values at +0x56C / +0x578
 * of the block at +0x104 is added to or subtracted from slot+4 depending on a per-slot side code. What these quantities
 * physically are is unknown. */
struct Item { char p0[8]; float tab[0x1A0 / 4]; char pad[0x1AC - 0x8 - 0x1A0]; char m1AC[0x2E]; unsigned char m1DA; };
struct V12 { float a, b, c; };
struct Data { char p[0x3B8]; V12 ent[0x18]; char q[0xFD0 - 0x3B8 - 0x18 * 12]; float tab[8]; };
struct Obj { unsigned char m0, m1; char pad[0x12]; unsigned char m14[8]; unsigned char m1C[8]; };
struct Slot {
    char p0[4]; float m4;
    char p1[0x48 - 8]; float m48; float m4C; float m50;
    char p2[0x89 - 0x54]; unsigned char m89;
    char p3[0xDD - 0x8A]; unsigned char mDD;
    char p4[0xEC - 0xDE];
};
struct Self { char p0[4]; int m4; char p1[8]; Data *m10; };
extern "C" Obj *func_00359510(Data *);
extern "C" int func_00356EF0(void *, int) throw();
extern "C" Item *func_00360F80(Data *, int, int);
extern "C" float func_003573A8(Data *, int, float) throw();
extern "C" float func_00359830(void *, float);
extern "C" float func_00467470(void *, int);

extern "C" void func_00357418(Self *self) {
    int slotIndex = 0;
    char *block = (char *)self + 0x104;
    Data *data = self->m10;
    Obj *slotTable = func_00359510(data);
    int flagResult = func_00356EF0(self, self->m4 + 4);
    float delta = *(float *)(block + 0x56C) - *(float *)(block + 0x578);
    if (slotTable->m1 != 0) {
    Slot *slot = (Slot *)((char *)self + 0x164);
    do {
        unsigned tableIndex = 0;
        Item *item = func_00360F80(data, slotIndex, slot->m89);
        if (slotIndex < slotTable->m1) tableIndex = slotTable->m14[slotIndex];
        float value = slot->m48;
        slot->mDD = item->m1DA;
        value = value * func_00359830(item->m1AC, func_003573A8(data, slotIndex, value));
        if (flagResult) value = value * slot->m50;
        value = value * data->tab[tableIndex];
        float input;
        if (slotTable->m0 != 1) {
            input = 0.0f;
            unsigned sideCode = slotTable->m1C[slotIndex];
            if (sideCode == 0) input = -delta;
            else {
                unsigned sideFlipped = sideCode ^ 1;
                if (sideFlipped == 0) input = delta;
            }
            input = input + slot->m4;
        } else {
            input = 0.0f;
        }
        slot->m4C = value * item->tab[slot->m89] * func_00359830(&data->ent[tableIndex], input);
        slot->m4C = slot->m4C * func_00467470(self, slot->m89);
        slotIndex++; slot++;
    } while (slotIndex < slotTable->m1);
    }
}
