/* Pushes an entry onto the front of a singly linked list: the entry's link at +0x8C takes the old list head stored at +0x24 of the
 * owner, then the owner's head points at the entry. Called by func_004852F8 for every non-hidden object with the context as owner,
 * so the list is probably a per-frame list of visible objects (inferred from that caller). */
struct Owner { char pad[0x24]; void *firstEntry; };
struct Entry { char pad[0x8C]; void *nextEntry; };

extern "C" void func_00475C88(Owner *owner, Entry *entry) {
    entry->nextEntry = owner->firstEntry;
    owner->firstEntry = entry;
}
