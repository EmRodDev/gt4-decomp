/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Clears the whole state of the two-slot channel object: counters at +0x10/+0x1C/+0x858/+0x85C/+0x860, the idle second slot (subs[1]) and the record at +0x654, marks that record with byte 1, calls func_004B59C0(o, 6) twice and finally func_004B8270(o). Field names are descriptive; what the channels are is not determined. */
typedef int s32;
typedef unsigned char u8;
struct Sub {
    s32 f0; s32 f4; short *f8; char pc[4]; short s10; char p12[0x1FE];
    s32 f210; s32 f214; char b218; char p219[3]; short s21C; short s21E;
    char p220[0x1F8]; s32 f418;
};
struct W { char b; char p1[3]; short s4; short s6; };
struct Obj {
    char p0[0x10]; s32 f10; short *f14; char p18[4]; s32 f1C;
    Sub subs[2];
    char pad[0x858 - 0x20 - 2 * sizeof(Sub)];
    s32 f858; s32 f85C; s32 f860;
};
extern "C" void *func_004B59C0(void *, s32);
extern "C" void func_004B8270(void *);
extern "C" void func_004B4598(Obj *self) {
    Sub *slot1 = &self->subs[1];
    self->f10 = 0;
    *self->f14 = 0;
    self->f1C = 0;
    self->f858 = 0;
    self->f85C = 0;
    self->f860 = 0;
    slot1->f0 = 0;
    slot1->f4 = 0;
    *slot1->f8 = 0;
    slot1->s10 = 0;
    slot1->f210 = 0;
    slot1->f214 = 0;
    W *record = (W *)((char *)self + 0x654);
    record->b = 1;
    record->s6 = 0;
    record->s4 = 0;
    slot1->f418 = 0;
    func_004B59C0(self, 6);
    func_004B59C0(self, 6);
    func_004B8270(self);
}
