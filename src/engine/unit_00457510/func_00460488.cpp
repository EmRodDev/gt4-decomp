/* Rebases an object that moved in memory, then walks its entries (shape inferred, same idea as func_00459100): link at +8 holds the
 * previous address, so diff = current address - link; link is updated. Then each of the count 8-byte entries from +0x14 is passed to
 * func_004603F8(entry, diff, arg2) and, if a callback is given, to the callback. */
struct Node {
    int f0;
    int f4;
    int lastAddress;
    unsigned int entryCount;
    char pad[0x14 - 0x10];
};
extern "C" void func_004603F8(void *arg0, int arg1, int arg2);

extern "C" void func_00460488(Node *self, void (*callback)(void *), int context) {
    unsigned int i;
    int moveDelta;
    long delta;
    char *entry;
    void *entryPtr;
    i = 0;
    moveDelta = (int)self - self->lastAddress;
    self->lastAddress = (int)self;
    if (self->entryCount != 0) {
        delta = moveDelta;
        entry = (char *)self + 0x14;
        do {
            func_004603F8(entry, delta, context);
            entryPtr = entry;
            entry += 8;
            if (callback != 0) {
                callback(entryPtr);
            }
            i += 1;
        } while (i < self->entryCount);
    }
}
