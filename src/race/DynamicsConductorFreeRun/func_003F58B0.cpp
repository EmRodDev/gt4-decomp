/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Handles a car passing a lap boundary in free run, unless the conductor is disabled (flag after the 0xFC-byte
 * manager at +0xD4). The control record manager (at self+0xD4) provides a record through func_00346A28; that
 * record is passed to func_0035ABA8 together with the car's index byte, the car's lap field (a short at +0x4AC of
 * the sub-state) is set to the lap argument + 1, and the manager is reset
 * (AutomobileControlRecord__Manager__reset). The time argument has the record time subtracted; if it goes
 * negative, then in race mode 0 for car index 1 func_0034DB30(race, 1) is called, and 1.0 is added (a wrap, so the
 * time is probably a lap fraction; inferred). The result is stored at arg+0x554 (meaning unknown). The sub-state
 * starts at arg+0x104 and the byte at +0x440 of it is the car index. */
struct Rec { char pad[0xC]; float time; };
struct Settings { char pad[0xE0]; int mode; };
struct Race { Settings *settings; };
struct Sub { char pad[0x440]; unsigned char index; char pad441[0x6B]; short lap; };
struct Arg { int unk0; Race *race; char pad8[0xFC]; Sub sub; };
struct Obj { char pad[0xD4]; char manager[0xFC]; int disabled; };
extern "C" Rec *func_00346A28(int);
extern "C" void AutomobileControlRecord__Manager__reset(int);
extern "C" int func_0034DB30(Race *, int);
extern "C" void func_0035ABA8(Race *, int, Rec *);
extern "C" void func_003F58B0(Obj *self, Arg *arg, int lap, float time) {
    Sub *carState;
    if (self->disabled == 0) {
        carState = &arg->sub;
        int managerAddr = (int)self + 0xD4;
        Rec *record = func_00346A28(managerAddr);
        Race *race = arg->race;
        func_0035ABA8(race, carState->index, record);
        carState->lap = lap + 1;
        AutomobileControlRecord__Manager__reset(managerAddr);
        time -= record->time;
        if (time < 0.0f) {
            if (race->settings->mode == 0 && carState->index == 1) {
                func_0034DB30(race, 1);
            }
            time += 1.0f;
        }
        *(float *)((char *)arg + 0x554) = time;
    }
}
