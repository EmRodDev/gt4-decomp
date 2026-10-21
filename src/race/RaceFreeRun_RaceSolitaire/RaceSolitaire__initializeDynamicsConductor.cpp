/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Prepares the physics side of a solitaire race (time-trial base class of FreeRun, License and MachineTest): both RaceInput blocks (+0xE48C,
 * +0xE84C) get the run mode kept at +0xCC8; the race info obtained through the virtual method at vtable +0x90 receives the logger check
 * point count of the organization (field +0x90, named from RaceOrganization::getLoggerCheckPointCount); the first entry stores the run
 * mode when it is below 2; the player input and the ghost input each receive one value from the race info (+0x84 and +0x8C into their +0x14C,
 * purpose unknown); the ghost runs in mode 3 when a second entry exists and its stored mode is 1, otherwise in mode 2. After the base
 * class setup, a subsystem that answers a virtual query (+0x40) overrides the check point count with another virtual result (+0x128). */
typedef int s32;
typedef unsigned int u32;
typedef short s16;

struct VEnt { s16 off; s16 pad; void *(*fn)(void *); };
struct VTab { char pad[0x90]; VEnt e90; };

struct Item { char pad[0x3440]; s32 entryRunMode; };
struct Lst { s32 count; s32 unk4; Item **items; };
struct Org { char pad[0x60]; Lst *unk60; };

struct Info { char pad[0x84]; s32 unk84; s32 unk88; s32 unk8C; s32 checkpointCount; };
struct Inp { char pad[0x14C]; s32 inputSetting; };

struct Sub { char pad[0x10140]; char *unk10140; };

struct Self {
    char pad0[0x64];
    char *vtable;
    char pad68[4];
    Org *organization;
    Sub *subsystem;
    char pad74[0xCC8 - 0x74];
    u32 runMode;
};

extern "C" void RaceInput__setRunMode(void *, u32);
extern "C" s32 RaceOrganization__getLoggerCheckPointCount(void *);
extern "C" Inp *RaceSolitaire__getInput(void *) throw();
extern "C" Inp *RaceSolitaire__getInputGhost(void *) throw();
extern "C" void RaceBase__initializeDynamicsConductor(void *);

extern "C" void RaceSolitaire__initializeDynamicsConductor(Self *self) {
    RaceInput__setRunMode((char *)self + 0xE48C, self->runMode);
    RaceInput__setRunMode((char *)self + 0xE84C, self->runMode);
    Org *organization = self->organization;
    VEnt *infoEntry = (VEnt *)(self->vtable + 0x90);
    Info *raceInfo = (Info *)infoEntry->fn((char *)self + infoEntry->off);
    raceInfo->checkpointCount = RaceOrganization__getLoggerCheckPointCount(organization);
    Item *firstEntry = organization->unk60->items[0];
    u32 runModeCopy = self->runMode;
    if (runModeCopy < 2) {
        firstEntry->entryRunMode = runModeCopy;
    }
    u32 ghostRunMode = 2;
    RaceSolitaire__getInput(self)->inputSetting = raceInfo->unk84;
    if (organization->unk60->count >= 2) {
        ghostRunMode = (organization->unk60->items[1]->entryRunMode ^ 1) == 0 ? 3 : 2;
    }
    Inp *ghostInput = RaceSolitaire__getInputGhost(self);
    RaceInput__setRunMode(ghostInput, ghostRunMode);
    ghostInput->inputSetting = raceInfo->unk8C;
    RaceBase__initializeDynamicsConductor(self);
    Sub *subsystem = self->subsystem;
    VEnt *readyEntry = (VEnt *)(subsystem->unk10140 + 0x40);
    if (readyEntry->fn((char *)subsystem + readyEntry->off)) {
        VEnt *countEntry = (VEnt *)(subsystem->unk10140 + 0x128);
        raceInfo->checkpointCount = (s32)countEntry->fn((char *)subsystem + countEntry->off);
    }
}
