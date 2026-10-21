struct VEntry { short delta, index; int (*fn)(void *); };
struct Owner { char pad[0xF8A0]; int count; char pad2[0x10140 - 0xF8A4]; char *vtable; };
struct Self { int word; Owner *owner; char pad[0x5B3 - 8]; signed char state; char pad2[2]; unsigned char enabled; };
static inline bool is_enabled(Self *self) { return self->enabled != 0; }
extern "C" int func_00468A60(Self *self) {
    Owner *owner = self->owner;
    VEntry *entry = (VEntry *)(owner->vtable + 0x30);
    int value = entry->fn((char *)owner + entry->delta);
    if (!(value == 0 && owner->count >= 2 && is_enabled(self) && self->state == 1)) return 0;
    return 1;
}
