/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Rewrites the tires of the entry car before a free run (named changeEntryCarTire). The course type from the race spec decides the tire
 * code: type 2 forces 0xB, type 3 forces 0xC, anything else keeps the car's own pair. The pair is read from two bytes (+0x160/+0x161) when
 * the flag at +0x165 says they were set, else from 004462E0/00446320. If the pair changed, or the flag was set, the flag is cleared and
 * the new codes are looked up in database categories 0x19 and 0x1A and applied with 004468F8, all inside a begin/end session pair
 * (00449D58 / 00449D78). Calling the two values front and rear tire is inferred from the function name and the two categories; the do-while
 * runs exactly once (one entry car). */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef long long s64;
struct Info { u32 n; s32 pad; s32 *tbl; };
struct Mid { char pad[0x60]; Info *info; };
struct Obj { char pad0[0x6C]; Mid *mid; };
struct Car { char pad[0x160]; u8 frontTire; u8 rearTire; char pad2[3]; char overrideFlag; };
struct Spec;
extern "C" {
s64 func_004454C0(s64 *);
s32 func_004462E0(void *);
s32 func_00446320(void *);
void func_004468F8(void *, s64);
void func_004468F8b(void *, s64) __asm__("func_004468F8");
s32 SPEC_DATABASE__RaceSpec__getCourseType(void *);
void func_00449D58(void *);
void func_00449D78(void *, s32);
s32 func_00449E10(void *, s64);
s64 func_0044A048(void *, s64, s32);
struct Mid2 { char pad[0x60]; Info *info; char pad2[4]; void *spec; };
struct Obj2 { char pad0[0x6C]; struct M3 *m; };
struct M3 { char pad[0x60]; Info *info; void *spec; };
static inline void change(Car *entryCar, void *session, s32 newFront, s32 newRear) {
    if (func_00449E10(session, func_004454C0((s64 *)entryCar))) {
        s64 r = func_0044A048(session, 0x19, newFront);
        if (r != -1) func_004468F8(entryCar, r);
        r = func_0044A048(session, 0x1A, newRear);
        if (r != -1) func_004468F8(entryCar, r);
    }
}
void RaceFreeRun__changeEntryCarTire(Obj *self) {
    char session[0x20];
    s32 forcedTire = -1;
    s32 i;
    Mid *mid = self->mid;
    s32 courseType = SPEC_DATABASE__RaceSpec__getCourseType(*(void **)((char *)mid + 0x70));
    switch (courseType) {
    case 2: forcedTire = 0xB; break;
    case 3: forcedTire = 0xC; break;
    }
    func_00449D58(session);
    i = 0;
    do {
        Car *entryCar = (Car *)(mid->info->tbl[i] + 0x20);
        s32 frontTire, rearTire, newFront, newRear;
        if (entryCar->overrideFlag) {
            frontTire = entryCar->frontTire;
            rearTire = entryCar->rearTire;
        } else {
            frontTire = func_004462E0(entryCar);
            rearTire = func_00446320(entryCar);
        }
        if (forcedTire == -1) {
            newFront = frontTire;
            newRear = rearTire;
        } else {
            newFront = newRear = forcedTire;
        }
        if (frontTire != newFront || rearTire != newRear || entryCar->overrideFlag) {
            entryCar->overrideFlag = 0;
            change(entryCar, session, newFront, newRear);
        }
        i++;
    } while (i <= 0);
    func_00449D78(session, 2);
}
}
