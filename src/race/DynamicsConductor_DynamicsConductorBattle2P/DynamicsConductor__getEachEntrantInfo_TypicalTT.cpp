/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info { char pad[0x1cc]; int active; int special; };
struct Entrant { char pad[0x343c]; Info *info; char pad3440[8]; int value; };
struct Entries { char pad[8]; Entrant **items; };
struct Race { char pad[0x60]; Entries *entries; char pad64[0xe0 - 0x64]; int special; };
struct Self { Race *race; char pad[0xcbd8]; unsigned char mode; };
extern "C" int DynamicsConductor__IsBSpecRace(Self *);
extern "C" void DynamicsConductor__getEachEntrantInfo_TypicalTT(Self *self, int index, int *a, int *b, int *kind, int *c) {
    Race *race = self->race;
    Entrant *entrant = race->entries->items[index];
    *a = 0;
    *b = entrant->value;
    Info *info = race->entries->items[index]->info;
    if (info->active) {
        if (!race->special || !info->special) {
            *kind = 0;
            if (DynamicsConductor__IsBSpecRace(self)) *kind = 1;
            else if (self->mode == 4) *kind = 2;
        } else {
            *kind = 2;
        }
    } else {
        *kind = 2;
    }
    *c = 0;
    if (index == 1) *c = index;
}
