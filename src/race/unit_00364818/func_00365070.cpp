/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Reports a limit pair and a byte value for an index. Returns 0 if the flag byte at +4 is set. Otherwise func_00359510 (called on
 * the member at base+0x600) gives a table: idx, if below the count byte at +1, selects a byte at +0x14 of it (else 0), and that
 * byte indexes the array at 0x98 of the base object, giving the returned value. Reports the range 0..100 through the two outputs
 * (its sibling func_00364FE0 reports -100..100 and reads a signed array at 0x90). Meaning of the values unknown. */
typedef unsigned char u8;
typedef signed char s8;
struct In { char pad0[1]; u8 f1; char pad2[0x14 - 2]; u8 tab[1]; };
struct Base { char pad[0x98]; u8 f98[1]; };
struct O { Base *f0; u8 f4; };
extern "C" In *func_00359510(void *) throw();
extern "C" u8 func_00365070(O *self, int index, s8 *rangeMin, s8 *rangeMax) {
    u8 result = 0;
    if (self->f4 != 0) return result;
    In *table = func_00359510((char *)self->f0 + 0x600);
    u8 tableIndex = 0;
    if (index < table->f1) tableIndex = table->tab[index];
    *rangeMin = 0;
    *rangeMax = 100;
    return self->f0->f98[tableIndex];
}
