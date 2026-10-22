/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Per-car start-up step for the race object, run only when the info block has a non-zero word at +0xC4 and its
 * float at +0xC8 truncates to 0xB3 (179; what that value stands for is unknown). For each car (count at +0xF8A0,
 * car found with func_0034C190) whose byte at state+0x4B2 is zero it sets the byte at +0x632 to 1, and when the
 * signed byte at +0x466 is zero it sets that to 2 and, unless the byte at +0x467 is 2, 3 or 4 (the +0xFE trick
 * tests that range), calls func_00463C28 on the sub-object at car+0x14 with 6 and 1. The same +0x4B2, +0x466 and
 * +0x467 bytes are tested in func_00343D78. The do-while with the pre-check on the count is the loop form of the
 * matched source. */
struct Inf {char pad[0xC4]; int c4; float c8;};
struct Sub {char pad0[0x466]; signed char s466; unsigned char u467; char pad1[0x4B2-0x468]; unsigned char u4B2; char pad2[0x632-0x4B3]; signed char s632;};
struct Car {char pad0[0x14]; int w14; char pad1[0x104-0x18]; Sub sub;};
struct Main {Inf *inf; char pad[0xF8A0-4]; int count;};
extern "C" Car *func_0034C190(Main *, int);
extern "C" void func_00463C28(void *, int, int);
extern "C" void func_00366588(Main *self){
    Inf *inf = self->inf;
    if (inf->c4 != 0 && (int)inf->c8 == 0xB3) {
        int carIndex = 0;
        if (self->count > 0) {
            do {
                Car *car = func_0034C190(self, carIndex++);
                Sub *state = &car->sub;
                if (state->u4B2 == 0) {
                    state->s632 = 1;
                    if (state->s466 == 0) {
                        state->s466 = 2;
                        if ((unsigned char)(state->u467 + 0xFE) >= 3)
                            func_00463C28((char *)car + 0x14, 6, 1);
                    }
                }
            } while (carIndex < self->count);
        }
    }
}
