/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Posts or clears a race-label message on the object at D_00622F4C + 0x568. If *kind is not 0xD, it sends the race label text
 * (SPEC_DATABASE::RaceSpec::getRaceLabel of the race spec at +0x70 of the object's sub-object) with the kind byte, the constant 0xE and
 * *value through func_0042F2E0, which builds a type-4 packet (see that file); if *kind is 0xD it calls func_0042F198 instead
 * (presumably a clear/reset, inferred from the missing arguments). */
typedef int s32;
typedef unsigned char u8;
struct Mid { char pad[0x70]; void *raceSpec; };
struct Self { char pad[0x6C]; Mid *mid; };
extern char *D_00622F4C;
extern "C" void func_0042F198(char *);
extern "C" void func_0042F2E0(char *, const char *, u8, u8, s32);
extern "C" const char *SPEC_DATABASE__RaceSpec__getRaceLabel(void *);

extern "C" void func_00110800(Self *self, s32 *kind, s32 *value) {
    Mid *mid = self->mid;
    if (*kind != 0xD) {
        char *globals = D_00622F4C;
        return func_0042F2E0(globals + 0x568, SPEC_DATABASE__RaceSpec__getRaceLabel(mid->raceSpec), *(u8 *)kind, 0xE, *value);
    }
    func_0042F198(D_00622F4C + 0x568);
}
