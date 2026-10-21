/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Initialiser of a photo-mode style race scene: runs the base initialiser, installs the vtable D_00660DE8 at +0x64 (the destructor func_001C8778 uses the same pointer), allocates a 0x1F640-byte RacePhotoMode and stores it twice (+0xA4, +0xA8), then builds a RaceMachineTestInformation from the global block D_00622F4C (entry cars = 1, course code from the string at global+4 via func_00447C78, car source taken from the global car buffer at +0xE0 when func_004443A8 accepts it, else from the default at +0x13938), stores the resulting info on the photo-mode object, starts it (func_00387EF0 with 2,1) and registers the member at +0xAC with the singleton from func_001D3A60. Role guessed from the class names. */
typedef int s32;
struct G { char pad0[4]; char f4[0xDC]; char fE0[0x40]; s32 f120; };
struct Obj { char pad0[0x64]; void *f64; char pad1[0xA4 - 0x68]; void *fA4; void *fA8; char fAC[0x218 - 0xAC]; s32 f218; };
struct Item { char pad[0x6C]; void *f6C; };
struct Sing { char pad[0x1C]; void *f1C; };
extern G *D_00622F4C;
extern char D_00660DE8[];
extern "C" void *func_00109A78(void *);
extern "C" Sing *func_001D3A60(void);
extern "C" void func_001D3AD0(void *);
extern "C" void func_00333400(void *);
extern "C" void func_003335F0(void *, void *);
extern "C" void func_00387EF0(void *, s32, s32);
extern "C" void *func_003B7850(void *);
extern "C" void func_003BB440(void *, void *);
extern "C" void RaceInformation__setCourseCode(void *, s32);
extern "C" void RaceInformation__setEntryCars(void *, s32);
extern "C" s32 RaceMachineTestInformation__structor_0(void *);
extern "C" void RaceMachineTestInformation__structor_1(void *, s32);
extern "C" void RacePhotoMode__structor_0(void *);
extern "C" void *func_00441248(void *);
extern "C" s32 func_00444190(void *);
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *, s32);
extern "C" s32 func_004443A8(void *, void *);
extern "C" void func_004452F8(void *, void *);
extern "C" void func_00445880(void *, s32);
extern "C" s32 func_00447C78(void *);
extern "C" void *exception__structor_0(s32);
extern "C" void func_001C85E0(Obj *self) {
    char carBuf[0x180];
    char raceInfo[0x130];
    char carCopy[0x190];
    void *carSource;
    G **globalPtr = &D_00622F4C;
    void **photoField = &self->fA4;
    char *member = self->fAC;
    func_00109A78(self);
    self->f64 = D_00660DE8;
    void *photoMode = exception__structor_0(0x1F640);
    RacePhotoMode__structor_0(photoMode);
    *photoField = photoMode;
    self->fA8 = photoMode;
    func_00333400(member);
    self->f218 = 0;
    G *globals = *globalPtr;
    char *carName = globals->fE0;
    char *courseName = globals->f4;
    func_00444190(carBuf);
    if (func_004443A8(carBuf, carName)) {
        func_00445880(carBuf, (*globalPtr)->f120);
        carSource = carBuf;
    } else {
        carSource = func_00441248((char *)*globalPtr + 0x13938);
    }
    RaceMachineTestInformation__structor_0(raceInfo);
    func_003BB440(raceInfo, (char *)D_00622F4C + 0x44);
    RaceInformation__setEntryCars(raceInfo, 1);
    func_004452F8(carCopy, carSource);
    RaceInformation__setCourseCode(raceInfo, func_00447C78(courseName));
    Item *photo = (Item *)self->fA8;
    photo->f6C = func_003B7850(raceInfo);
    func_00387EF0(self->fA8, 2, 1);
    func_003335F0(member, self->fA8);
    func_001D3AD0(func_001D3A60());
    func_001D3A60()->f1C = member;
    RaceMachineTestInformation__structor_1(raceInfo, 2);
    SPEC_DATABASE__CarEquipments__setVariationOrder(carBuf, 2);
}
