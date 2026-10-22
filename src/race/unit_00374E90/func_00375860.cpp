/* Updates one slot of a table of 0x19C-byte slots at the start of the object (slot struct at slotBase+0x10,
 * auxiliary part at +0xE0). If the int at slot+0x18C is not negative, func_003FC4F0 is called with it and the slot
 * is marked started: flags gets bit 2 and results[1] is set to 1. When flag bit 2 or 4 is set, a virtual call at
 * vtable+0x138 of the target object kept at slot+0x154 is made with the slot, the int at target+0x180, the int at
 * ctx+0xBC and the byte at target+0x1D0 (what the call does is unknown). Last, a virtual query at vtable+0xD8 of
 * self for the slot index returns a handle which is passed with ctx, the aux part, the slot and self+0x9C0 to
 * func_00378F28. The unused argument is part of the original signature. The two virtual entries carry this-
 * adjustments, so the calls are written through small structs. */
struct Entry { short delta, index; int (*fn)(void *, int); };
struct Entry5 { short delta, index; void (*fn)(void *, char *, int, int, int); };
struct Obj { char *vtbl; };
struct Tgt { char *vtbl; };
extern "C" void func_00378F28(int, char *, char *, char *, char *);
extern "C" void func_003FC4F0(char *, int);
static inline int VCALL(Obj *self, int slotIndex) {
    Entry *e = (Entry *)(self->vtbl + 0xD8);
    return e->fn((char *)self + e->delta, slotIndex);
}
extern "C" void func_00375860(Obj *self, char *ctx, int unusedArg, int slotIndex, unsigned flags, int *results) {
    int started = 0;
    char *slotBase = (char *)self + slotIndex * 0x19C;
    char *slot = slotBase + 0x10;
    char *slotAux = slotBase + 0xE0;
    int pendingId = *(int *)(slot + 0x18C);
    if (pendingId >= 0) {
        func_003FC4F0(slot, pendingId);
        started = 1;
    }
    if (started) {
        flags |= 2;
        results[1] = 1;
    }
    int notify = 0;
    if (flags & 2) notify = 1;
    if (flags & 4) notify = 1;
    if (notify) {
        Tgt *target = *(Tgt **)(slot + 0x154);
        Entry5 *e = (Entry5 *)(target->vtbl + 0x138);
        e->fn((char *)target + e->delta, slot, *(int *)((char *)target + 0x180), *(int *)(ctx + 0xBC), *(unsigned char *)((char *)target + 0x1D0));
    }
    int handle = VCALL(self, slotIndex);
    func_00378F28(handle, ctx, slotAux, slot, (char *)self + 0x9C0);
}
