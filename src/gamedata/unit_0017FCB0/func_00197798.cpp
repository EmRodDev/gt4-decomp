/* Same as func_00192E20 (current RacePhotoMode instance or 0) but through the holder returned by func_00197788. Two copies exist in the original, one per translation unit. */
struct Unk64 {
    short unk0;
    short pad2;
    int unk4;
};

struct Node {
    int unk0;
    char pad[0x60];
    Unk64 *unk64;
};

extern char RacePhotoMode__tf[];
extern char RacePS2Base__tf[];

extern Node **func_00197788(void);
extern int GT4MC__FileGT4GameData__loadInstance(int, void *, int, void *, void *, void *);

int func_00197798(void)
{
    Node **holder;
    Node *node;
    int result;
    int casted;

    holder = func_00197788();
    result = 0;
    if (holder != 0) {
        node = *holder;
        if (node != 0) {
            Unk64 *u = node->unk64;
            casted = GT4MC__FileGT4GameData__loadInstance(u->unk4, RacePhotoMode__tf, 0,
                                    (char *)node + u->unk0,
                                    RacePS2Base__tf, node);
        } else {
            casted = 0;
        }
        result = casted;
    }
    return result;
}
