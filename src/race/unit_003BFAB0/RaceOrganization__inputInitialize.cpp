/* For every entry of the organization's list, asks the race's virtual at vtable +0x240 (with the value at entry +0x198) for a record, stores it at
 * entry +0x343C and, when that record's field +0x1CC is nonzero, resets the AutomobileControlRecord manager embedded at record +0xD4. That the
 * record is the entry's control-input recording is inferred from the manager's name; the +0x343C field is the one 00363B10 later copies from. */
#include "types.h"

struct Ent {
    s16 delta;
    s16 pad;
    void *(*fn)(void *, void *);
};

struct Vt {
    char pad[0x240];
    Ent ent;
};

struct Obj {
    char pad[0x64];
    Vt *vt;
};

struct List {
    u32 count;
    s32 pad4;
    void **items;
};

struct Self {
    char pad[0x60];
    List *list;
};

struct Item {
    char pad0[0x198];
    void *f198;
    char pad1[0x343C - 0x19C];
    s32 inputRecordPtr;
};

struct Res {
    char pad[0x1CC];
    s32 f1CC;
};

extern "C" void AutomobileControlRecord__Manager__reset(void *organization);

extern "C" void RaceOrganization__inputInitialize(Self *organization, Obj *race) {
    u32 i = 0;
    List *entryList = organization->list;
    for (i = 0; i < entryList->count; i++) {
        Item *entry = (Item *)organization->list->items[i];
        Vt *raceVtable = race->vt;
        Ent *entry240 = (Ent *)((char *)raceVtable + 0x240);
        Res *inputRecord = (Res *)entry240->fn((char *)race + entry240->delta, entry->f198);
        entry->inputRecordPtr = (s32)inputRecord;
        if (inputRecord->f1CC != 0) {
            AutomobileControlRecord__Manager__reset((char *)inputRecord + 0xD4);
        }
    }
}
