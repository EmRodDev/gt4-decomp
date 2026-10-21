/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Returns a per-slot float from a data table, or 1.0 as the default. The state block sits at +0x104; its byte at +0x466 is a kind
 * (signed) and the byte at +0x467 a mode. The table lookup happens when kind is 1 or 2, or when the mode byte is non-zero; otherwise
 * 1.0 is returned. The table is obtained with func_00463BB8(self + 0x14); the slot index is a byte at (index + *(self+0x10) + 0xF98)
 * and the float lives at +0xA8 + slot * 4 in that table. What the float is (a scale or gain?) is unknown. */
extern "C" int func_00463BB8(void *);
extern "C" float func_00467470(char *self, int index) {
    float result;
    char *state = self + 0x104;
    signed char kind = *(signed char *)(state + 0x466);
    if (kind == 1 || (kind == 2 || (result = 1.0f, *(unsigned char *)(state + 0x467) != 0))) {
        int owner = *(int *)(self + 0x10);
        int table = func_00463BB8(self + 0x14);
        result = *(float *)(table + *(unsigned char *)(index + owner + 0xF98) * 4 + 0xA8);
    }
    return result;
}
