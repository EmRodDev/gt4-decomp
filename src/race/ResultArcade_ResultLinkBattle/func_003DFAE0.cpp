/* compiler: ee-gcc2.96-no-strict-aliasing */
/**
 * Updates arcade / link-battle race result presentation.
 * Sorts race entries by finishing rank and populates the display slots
 * with car icon numbers, car names, and the player rank.
 */
typedef int s32;

struct RaceEntryItem {
    char headerPadding[0x10];
    RaceEntryItem *nextEntry;
    s32 entryIndex;
};

struct RaceEntryList {
    char listPadding[0x14];
    RaceEntryItem *headEntry;
};

extern "C" void RaceEntryBase__sortByRank(RaceEntryList *entryList);
extern "C" void ResultArcade__setPlayerRank(void *resultDisplay, s32 rank) throw();
extern "C" void ResultArcade__setCarName(void *resultDisplay, s32 rank, RaceEntryItem *entryItem);
extern "C" void ResultArcade__setCarIconNumber(void *resultDisplay, s32 rank, s32 iconNum);

extern "C" void func_003DFAE0(void *resultDisplay, void *raceContext) {
    char *displayBase = (char *)resultDisplay;
    s32 currentRank;
    RaceEntryItem *currentEntry = (RaceEntryItem *)raceContext;
    char *slotPtr;
    if (*(s32 *)(displayBase + 0x48) == 0) {
        if (*(s32 *)displayBase != 0) {
            currentRank = 0;
            RaceEntryBase__sortByRank(*(RaceEntryList **)((char *)currentEntry + 0x60));
            currentEntry = (*(RaceEntryList **)((char *)currentEntry + 0x60))->headEntry;
            if (currentEntry != 0) {
                s32 *playerIndexPtr = (s32 *)(displayBase + 4);
                slotPtr = displayBase + 0x68;
                do {
                    s32 carIndex = currentEntry->entryIndex;
                    if (*(s32 *)((char *)(playerIndexPtr + carIndex) + 0x10) == 0) {
                        if (*(s32 *)slotPtr != carIndex) {
                            ResultArcade__setCarIconNumber(resultDisplay, currentRank, carIndex);
                            ResultArcade__setCarName(resultDisplay, currentRank, currentEntry);
                        }
                        if (currentEntry->entryIndex == *playerIndexPtr) {
                            ResultArcade__setPlayerRank(resultDisplay, currentRank);
                        }
                    }
                    currentEntry = currentEntry->nextEntry;
                    slotPtr += 0xC0;
                    currentRank += 1;
                } while (currentEntry != 0);
            }
        }
    }
}
