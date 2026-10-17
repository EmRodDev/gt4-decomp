/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pool { char pad[0x228]; char slots[8][0x4C]; char pad488[0x50]; int next; int freeCount; };
extern "C" void *func_005561B8(Pool *pool) {
    int *next = &pool->next;
    char *slot = pool->slots[(*next)++];
    if (*next == 8) *next = 0;
    pool->freeCount--;
    *(int *)(slot + 0x48) = 0;
    return slot;
}
