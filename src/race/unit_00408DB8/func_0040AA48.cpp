/* compiler: ee-gcc2.96-no-strict-aliasing */
/* For every car of the list whose CarEquipments variation order is still -1 (unset), fills a table of weighted records with 0040A6F0 and picks
 * one: the first record whose weight is above a random draw (func_00578598 on the generator rng, a float, inferred from its use as a threshold),
 * or the last candidate if none is, then applies that record's value to the car with 00445880. So it is a weighted random choice of a
 * variation for cars that have none yet (reading "variation" as appearance is inferred from the getter name); the record layout (count,
 * value, weight) is read from the indexing. */
struct Rec { int a; int b; float w; int pad[3]; };
struct Ent { int f0; char data[0x300]; };
struct List { int count; int p4; int *arr; };
struct Self { char p[0x60]; List *list; };
extern "C" void func_0040A6F0(Self *, void *) throw();
extern "C" int func_00445880(void *, int);
extern "C" int SPEC_DATABASE__CarEquipments__getVariationOrder(void *);
extern "C" float func_00578598(int);

extern "C" void func_0040AA48(Self *self, int rng) {
    Ent tables[6];
    int entryCount = self->list->count;
    int entryIndex;
    for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
        char *carEquipment = (char *)self->list->arr[entryIndex] + 0x20;
        if (SPEC_DATABASE__CarEquipments__getVariationOrder(carEquipment) == -1) {
            func_0040A6F0(self, tables);
            Rec *weightedRecords = (Rec *)tables[entryIndex].data;
            int candidateCount = weightedRecords[0].a - 1;
            int choice = 0;
            while (choice < candidateCount) {
                if (func_00578598(rng) < weightedRecords[choice].w) break;
                choice++;
            }
            Rec *selected = weightedRecords + choice;
            func_00445880(carEquipment, selected->b);
        }
    }
}
