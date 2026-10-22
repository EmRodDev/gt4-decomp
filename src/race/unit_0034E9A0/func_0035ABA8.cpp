/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Applies a stored record to a car (called from func_003F58B0 at a lap boundary). It takes the car from
 * func_0034C190, remembers the two bytes at state+0x440 and +0x441 (state = car+0x104), lets func_003F85F0 load
 * from record+0x54 (they are saved and restored around it, so the call probably overwrites them; inferred) and
 * puts the two bytes back, then calls func_003455F0. The word at state+0x614 is set from func_003584A0 with 0x32
 * minus the record byte at +2 (an index computed against 50; meaning unknown). In the table at self+0xDA6C,
 * func_0045B948 is called for the car, then the 0x400 data bytes at record+0x10F4 are summed and, if the total is
 * not zero, copied by func_0045CF18 into that car's 0x4F0-byte slot (+0xC), passing the total as size. */
struct E7 { char p[0x440]; unsigned char m440, m441; char q[0x614 - 0x442]; unsigned m614; };
struct E { char p[0x104]; E7 e7; };
struct Rec { char p[2]; unsigned char m2; char q[0x10F4 - 3]; unsigned char data[0x400]; };
extern "C" E *func_0034C190(void *, int);
extern "C" void func_003F85F0(E *, void *);
extern "C" void func_003455F0(E *);
extern "C" unsigned func_003584A0(void *, int) throw();
extern "C" void func_0045B948(void *, int);
extern "C" void func_0045CF18(void *, void *, int);

extern "C" void func_0035ABA8(char *self, int carIndex, Rec *record) {
    E *car = func_0034C190(self, carIndex);
    E7 *state = &car->e7;
    unsigned char saved441 = state->m441;
    unsigned char saved440 = state->m440;
    func_003F85F0(car, (char *)record + 0x54);
    state->m441 = saved441;
    char *table = self + 0xDA6C;
    state->m440 = saved440;
    func_003455F0(car);
    state->m614 = func_003584A0(self, 0x32 - record->m2);
    func_0045B948(table, carIndex);
    int total = 0;
    for (unsigned i = 0; i < 0x400; i++) total += record->data[i];
    if (total != 0) func_0045CF18(table + carIndex * 0x4F0 + 0xC, record->data, total);
}
