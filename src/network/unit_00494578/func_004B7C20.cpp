/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Steps the state machine of the idle slot (1 - o+0x858) and returns 1 while something is still going on, 0 when idle: returns 1 right away when o+0x860 is set; state 0 is idle (0), state 1 asks for work (func_004B4F28) and advances to 2, state 2 fetches a record (func_004B5CC0), copies 0x100 bytes into a local buffer, forwards (end-start) bytes of it with func_004B5E00 and marks the record 4. State meanings are guessed from this flow. */
struct Slot {
    int m0;
    int m4;
};
struct Rec {
    char c0;
    char pad1[3];
    short s4;
    short s6;
};
struct O {
    char pad[0x20];
    Slot slot[1];
};
extern "C" void func_004B4CC0(O *, Rec *, char *, int) throw();
extern "C" void func_004B4F28(O *) throw();
extern "C" Rec *func_004B5CC0(O *) throw();
extern "C" void func_004B5E00(O *, Rec *, char *, int) throw();

extern "C" int func_004B7C20(O *self) {
    if (*(int *)((char *)self + 0x860) != 0) {
        return 1;
    }
    Slot *slot = (Slot *)((char *)self + (1 - *(int *)((char *)self + 0x858)) * 0x41C + 0x20);
    char copyBuf[0x200];
    switch (slot->m0) {
    case 0:
        return 0;
    case 1:
        slot->m4 = 1;
        func_004B4F28(self);
        slot->m0 = 2;
        return 1;
    case 2: {
        Rec *record = func_004B5CC0(self);
        func_004B4CC0(self, record, copyBuf, 0x100);
        func_004B5E00(self, record, copyBuf, record->s6 - record->s4);
        record->c0 = 4;
        return 1;
    }
    default:
        return 1;
    }
}
