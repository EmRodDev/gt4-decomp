/* compiler: ee-gcc2.96-nsa-as2004 */
struct Block {
    char pad0[0xC];
    unsigned int size;
    char payload[1];
} __attribute__((packed));

struct Ring {
    char pad0[0x3C];
    int generation;
};

extern "C" {
Block *func_00554CA0(Ring *);
void func_00554D60(Ring *, Block *);
void *func_005A4724(void *, const void *, unsigned int);

int func_00554DD8(Ring *ring, char *buffer, int capacity)
{
    char *end = buffer + capacity;
    char *cursor = buffer;
    ring->generation++;
    Block *block;
    char *next;
    while ((block = func_00554CA0(ring)) != 0) {
        unsigned int size = block->size;
        next = cursor + size;
        if (next > end)
            break;
        func_005A4724(cursor, block->payload, size);
        func_00554D60(ring, block);
        cursor = next;
    }
    return cursor - buffer;
}
}
