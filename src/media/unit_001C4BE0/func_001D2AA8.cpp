/* Selects the sound-effect id for a state change of this object: it stores the new state at +0x6A0, then calls
   func_001CD580 on the sub-object at +0x6A4 with an id that depends on the state (3 -> 0x52, 4 -> 0x42,
   6 -> 0x46, 7 -> 0x50, every other state -> 0). The meaning of the ids and of the states is unknown.
   The compiler emits one block per case after the jump; the inventory cut the function at two of them
   (0x1D2B20 and 0x1D2B38), so this source covers all of 0x1D2AA8..0x1D2B50. */
extern "C" void func_001CD580(char *buf, int c);

struct func_001D2AA8_Obj {
    char pad[0x6A0];
    int state;
};

extern "C" void func_001D2AA8(func_001D2AA8_Obj *self, int k) {
    self->state = k;
    switch (k) {
    case 3:
        return func_001CD580((char *)self + 0x6A4, 0x52);
    case 4:
        return func_001CD580((char *)self + 0x6A4, 0x42);
    case 1:
    case 2:
    case 5:
    default:
        return func_001CD580((char *)self + 0x6A4, 0);
    case 6:
        return func_001CD580((char *)self + 0x6A4, 0x46);
    case 7:
        return func_001CD580((char *)self + 0x6A4, 0x50);
    }
}
