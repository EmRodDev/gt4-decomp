struct O;
struct E { short adjust, pad; O *(*call)(void *, int); };
struct Slot { char pad[0x168]; O *object; char tail[0x30]; inline O *get() const { return object; } };
struct S {
    E *table;
    char pad[0xC];
    Slot slots[5];
    char pad8[0x9BC - 0x10 - 5 * sizeof(Slot)];
    int index;
};
struct Target { int unk0; char pad4[0x1dc]; int unk1E0; };
extern "C" int func_00373F70(S *s) {
    int index = s->index;
    Slot *slot = &s->slots[index];
    E *e = s->table + 27;
    O *o = e->call((char *)s + e->adjust, index);
    if (!o) return 0;
    O *target = slot->get();
    if (o != target) return 0;
    return ((Target *)o)->unk1E0;
}
