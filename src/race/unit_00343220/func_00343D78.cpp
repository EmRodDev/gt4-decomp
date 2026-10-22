/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Dispatches a car-level action by mode (called, for example, from the goal line handler with mode 3). state is
 * the block at car+0x104. Mode 4 is first replaced by bit 4 of the byte at state+0x4B1 (flag(): shift right 3,
 * mask 2, giving 0 or 2). The first time through (byte +0x4B2 zero) it is set to 1 and, if the byte at +0x467 is
 * 2, 3 or 4 (the add-0xFE trick tests that range), the function returns. When the signed byte at +0x466 is 0, the
 * sub-object at car+0x14 is processed with func_004673D0 and func_00467148 (passing the byte at +0x31 of the
 * object at car+0x10). If the conductor byte at +0xCBDE of the object at car+4 is 1 and mode is 0, mode becomes 1.
 * Mode 3 calls func_003454A8, 1 calls func_00345520, 2 calls func_00345598, anything else func_003452F0. The case
 * 0 before default is kept as matched. */
typedef unsigned char u8;
typedef signed char s8;
extern "C" void func_003452F0(void *);
extern "C" void func_003454A8(void *);
extern "C" void func_00345520(void *);
extern "C" void func_00345598(void *);
extern "C" void func_00467148(void *, int);
extern "C" void func_004673D0(void *);
static inline u8 flag(unsigned long v, unsigned long mask) { return (v >> 3) & mask; }
extern "C" void func_00343D78(char *car, int mode) {
    char *state = car + 0x104;
    if (mode == 4) mode = flag(*(u8 *)(state + 0x4B1), 2);
    if (!*(u8 *)(state + 0x4B2)) {
        u8 v = *(u8 *)(state + 0x467);
        *(u8 *)(state + 0x4B2) = 1;
        if ((unsigned)(u8)(v + 0xFE) < 3) return;
    }
    if (*(s8 *)(state + 0x466) == 0) {
        char *subObject = car + 0x14;
        func_004673D0(subObject);
        func_00467148(subObject, *(u8 *)(*(char **)(car + 0x10) + 0x31));
    }
    int v = *(u8 *)(*(char **)(car + 4) + 0xCBDE);
    mode = v == 1 ? (mode ? mode : v) : mode;
    switch (mode) {
    case 3: return func_003454A8(car);
    case 1: return func_00345520(car);
    case 2: return func_00345598(car);
    case 0:
    default: return func_003452F0(car);
    }
}
