/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Resets the idle one of two 0x41C-byte channel slots in o (index 1 - o+0x858, i.e. the slot that is not the current one) and the shared sequence fields, then calls func_004B59C0(o, 6) twice and finishes by the slot's state: 1 runs func_004B61A8, 2 runs it and falls back to state 1, 0 does nothing. What the channels carry is not determined; the double call is how the compiler had to see it (identical consecutive calls kept). */
struct Slot {
    int m0;
    int m4;
    short *m8;
    char padC[4];
    short m10;
    char pad12[0x210 - 0x12];
    int m210;
    int m214;
    char pad218[0x418 - 0x218];
    int m418;
    char pad41C[0x41C - 0x41C];
};
struct O {
    char pad0[0x10];
    int m10;
    short *m14;
    char pad18[8];
    Slot slot[2];
};
extern "C" void *func_004B59C0(void *, int) throw();
extern "C" void func_004B61A8(O *) throw();

struct T {
    char c0;
    char pad1;
    short s2;
    short s4;
    short s6;
};

extern "C" void func_004B80A0(O *self) {
    self->m10 = 0;
    short *sharedCounter = self->m14;
    char *idleSlotBase = (char *)self + (1 - *(int *)((char *)self + 0x858)) * 0x41C;
    *sharedCounter = 0;
    Slot *slot = (Slot *)(idleSlotBase + 0x20);
    T *record = (T *)(idleSlotBase + 0x238);
    slot->m4 = 0;
    *slot->m8 = 0;
    slot->m10 = 0;
    slot->m210 = 0;
    slot->m214 = 0;
    record->s4 = 0;
    record->s6 = 0;
    record->c0 = 1;
    slot->m418 = 0;
    func_004B59C0(self, 6);
    func_004B59C0(self, 6);
    switch (slot->m0) {
    case 1:
        return func_004B61A8(self);
    case 2:
        func_004B61A8(self);
        slot->m0 = 1;
        break;
    case 0:
    default:
        break;
    }
}
