/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Re-targets slot `idx` (records of 0x19C bytes from self+0x10, the current target pointer at +0x148) when a virtual (+0xD8)
 * reports a different target, or when flag bit 1 or 2 of `flags` is set. The target object is reset through three of its virtuals, gets
 * 0.5f at +0x234, is told to use a random choice (func_00377A28 of a random float from func_00578598, which is the random-number call
 * in sibling code) and, if its virtual +0xB8 disagrees with that choice, is reset to 0; then it is stored at slot+0x12C, out[0] is set to 1
 * and out[2] to 0.5f. Always returns 0. Meaning of the slots and of the target is unknown; a1 and a2 are unused. */
struct Tgt { char *vtbl; char pad[0x234 - 4]; float f234; };
struct Entry { short delta, index; Tgt *(*fn)(void *, int); };
struct Entry3 { short delta, index; void (*fn)(void *, int, int); };
struct Entry1 { short delta, index; void (*fn)(void *); };
struct Entry2 { short delta, index; void *(*fn)(void *); };
struct Obj { char *vtbl; };
extern "C" int func_00377A28(float) throw();
extern "C" void func_0037BC20(void *, int);
extern "C" void func_0037BC48(void *, int, int);
extern "C" float func_00578598(void *);
extern "C" int func_00377A60(Obj *self, int unusedArg1, int unusedArg2, int idx, unsigned flags, float *out) {
    char *slot = (char *)self + idx * 0x19C + 0x10;
    Tgt *target = *(Tgt **)(slot + 0x148);
    Entry *targetGetter = (Entry *)(self->vtbl + 0xD8);
    int needsUpdate = 0;
    Tgt *newTarget = targetGetter->fn((char *)self + targetGetter->delta, idx);
    if (newTarget != target) needsUpdate = 1;
    if (flags & 2) needsUpdate = 1;
    if (flags & 4) needsUpdate = 1;
    if (!needsUpdate) return 0;
    {
        int randomChoice = func_00377A28(func_00578598((char *)self + 4));
        Entry3 *e1 = (Entry3 *)(target->vtbl + 0x140);
        e1->fn((char *)target + e1->delta, (int)slot, 0);
        Entry1 *e2 = (Entry1 *)(target->vtbl + 0x168);
        e2->fn((char *)target + e2->delta);
        target->f234 = 0.5f;
        Entry1 *e3 = (Entry1 *)(target->vtbl + 0x170);
        e3->fn((char *)target + e3->delta);
        func_0037BC48(target, randomChoice, 1);
        Entry2 *e4 = (Entry2 *)(target->vtbl + 0xB8);
        void *currentChoice = e4->fn((char *)target + e4->delta);
        if ((int)currentChoice != randomChoice) func_0037BC20(target, 0);
        *(Tgt **)(slot + 0x12C) = target;
        *(int *)out = 1;
        out[2] = 0.5f;
    }
    return 0;
}
