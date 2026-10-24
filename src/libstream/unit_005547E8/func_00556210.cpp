/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Returns 1 when the table at 0x500 holds zero, when the slot id at +0x00 is
   -1, or when the slot state at +0x10C is not 2; the slot stride is 0x114.
   The count==0 case must be an else branch, not an early return, so gcc jumps
   to the shared result=1 store and keeps the two address adds before the load. */
struct Slot {
    int id;
    char pad[0x10C - 4];
    int state;
    char pad2[0x114 - 0x110];
};

struct SlotTable {
    Slot slots[1];
    char pad[0x500 - sizeof(Slot)];
    int count;
};

extern "C" int func_00556210(SlotTable *table, int index)
{
    int result = 0;
    if (table->count != 0) {
        Slot *slot = &table->slots[index];
        if (slot->id == -1 || table->slots[index].state != 2)
            result = 1;
    } else {
        result = 1;
    }
    return result;
}
