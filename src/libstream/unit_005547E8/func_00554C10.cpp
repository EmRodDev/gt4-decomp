/* compiler: ee-gcc2.96-nsa-as2004 */
struct Block {
    char pad0[4];
    int size;
    Block *next;
} __attribute__((packed));

struct Pool {
    char pad0[0xC];
    char queue[0xC];
    unsigned int flags;
    char pad1[0x34 - 0x1C];
    int total;
};

extern "C" int func_005B72A8(void);
extern "C" int func_005B72F8(void);
extern "C" void func_00554910(void *, void *);

extern "C" void func_00554C10(Pool *pool, Block *block)
{
    if (pool->flags & 1) {
        func_005B72A8();
        while (block) {
            pool->total += block->size + 0x10;
            block = block->next;
        }
        func_005B72F8();
        func_00554910(pool, pool->queue);
    }
}
