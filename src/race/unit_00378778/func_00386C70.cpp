/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Crew count for a car model (CarGeometry::GetNumCrew): 0 when the geometry is invalid or flag 2 is set, 1 when the race has three
 * or more cars (race count at +0xF8A0, inferred), otherwise whatever GetNumCrew reports. */
typedef int s32;
typedef unsigned short u16;

struct Arg { char pad0[4]; char *unk4; };
struct Local { char d[0x20]; };

extern "C" void CarGeometry__structor_0(Local *, Arg *, s32);
extern "C" u16 *func_0038DC18(Local *);
extern "C" s32 CarGeometry__GetNumCrew(Local *) throw();

static inline bool valid(Local *race) { return func_0038DC18(race) != 0; }

extern "C" s32 func_00386C70(s32 unusedArg, Arg *geometryRef) {
    Local geometry;
    char *race;

    CarGeometry__structor_0(&geometry, geometryRef, 0);
    if (!valid(&geometry)) {
        return 0;
    }
    for (;;) {
    race = geometryRef->unk4;
    s32 flag = *func_0038DC18(&geometry) & 2;
    if (flag) {
        return 0;
    }
    if (race != 0) {
        flag = *(s32 *)(race + 0xF8A0);
        flag = flag < 3;
        if (!flag) {
            return 1;
        }
    }
    return CarGeometry__GetNumCrew(&geometry);
    }
}
