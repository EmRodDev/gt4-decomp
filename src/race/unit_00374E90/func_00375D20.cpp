/* Per-slot setup (slots are 0x19C bytes apart): when the sub-object at +0xC04 accepts the slot's id, binds that target to the
 * slot through virtual slot 0x138 (with the ratio f9D4/f9C0) and sets 'out' to 1; then hands the slot to func_00378F28. The class
 * and the meaning of the arguments are unknown. */
struct Entry { short delta, index; char *(*fn)(void *, int); };
struct Entry4 { short delta, index; void (*fn)(void *, char *, int, int, float); };
struct Obj { char *vtbl; char pad[0x9C0 - 4]; float f9C0; char pad2[0x9D4 - 0x9C4]; float f9D4; };
struct Tg { char *vtbl; };
extern "C" void func_00378F28(char *, void *, char *, char *, float *);
extern "C" int func_003FFA20(char *);
extern "C" int func_00400408(char *, int);
extern "C" void func_00375D20(Obj *self, char *arg1, int unusedArg, int idx, int unusedArg2, int *out) {
    char *base = (char *)self + idx * 0x19C;
    char *slot = base + 0x10;
    char *slotTail = base + 0xE0;
    char *c04 = (char *)self + 0xC04;
    int *outp = out;
    if (func_00400408(c04, (signed char)slotTail[0x4D])) {
        float *p9C0 = &self->f9C0;
        char *cc = c04;
        Tg *target = *(Tg **)(slot + 0x168);
        int targetId = *(int *)(arg1 + 0x80);
        int handle = func_003FFA20(cc);
        Entry4 *e = (Entry4 *)(target->vtbl + 0x138);
        int one = 1;
        e->fn((char *)target + e->delta, slot, targetId, handle, self->f9D4 / *p9C0);
        *(Tg **)(slot + 0x12C) = target;
        *outp = one;
    }
    float *tailp = &self->f9C0;
    Entry *e0 = (Entry *)(self->vtbl + 0xD8);
    func_00378F28(e0->fn((char *)self + e0->delta, idx), arg1, slotTail, slot, tailp);
}
