/* Tree lower-bound search (std::map style red-black tree, inferred from the child links at +8 / +0xC and the node payload at +0x10):
 * walks down from the root comparing the key stored in each node with the search key through func_005C2A50; nodes whose key is
 * not smaller are remembered and the walk goes left, otherwise right. Writes the last remembered node (or the header node) to *outIter. */
struct Node {
    char pad8[8];
    int unk8;
    char pad10[16 - 0xC];
    int unkC;
};

struct Mid {
    char pad0[4];
    struct Node *unk4;
};

extern int func_005C2A50(void *, int, int, int);

struct func_005D6A98_s1 {
    char pad0[0x4];
    struct Node *unk4;
    struct Node *unk8;
};
struct func_005D6A98_s0 {
    char pad0[0xC];
    struct Node *unkC;
};

void **func_005D6A98(void **outIter, struct Mid *tree, int key)
{
    struct Node *result = (struct Node *)tree->unk4;
    struct Node *cursor = ((struct func_005D6A98_s1 *)result)->unk4;

    if (cursor != 0) {
        void *nodeKey = (char *)cursor + 0x10;
        do {
            if (func_005C2A50(nodeKey, key, 0, -1) >= 0) {
                result = cursor;
                cursor = ((struct func_005D6A98_s1 *)result)->unk8;
            } else {
                cursor = ((struct func_005D6A98_s0 *)cursor)->unkC;
            }
            nodeKey = (char *)cursor + 0x10;
        } while (cursor != 0);
    }

    *outIter = (void *)result;
    return outIter;
}
