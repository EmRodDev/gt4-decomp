/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blk {
    Blk *next;
    Blk *prev;
};

struct Heap {
    char pad0[4];
    Blk *head;
    Blk *tail;
};

extern "C" {
void *func_005722A8(Heap *h, void *block, int gap);
void func_005722F8(Heap *h, Blk *b);

/* Align the payload of block `b` to `align`: small gaps shift the header, large ones split the block. */
void *func_005721B8(Heap *h, Blk *b, unsigned int align)
{
    char *payload = (char *)b + 0x10;
    unsigned int mask = align - 1;
    char *aligned = (char *)(((unsigned int)payload + mask) & ~mask);
    Blk *moved;
    if (payload == aligned)
        return b;
    unsigned int gap = aligned - payload;
    if (gap < 0x20) {
        moved = (Blk *)(aligned - 0x10);
        Blk *next = b->next;
        Blk *prev = b->prev;
        moved->prev = prev;
        moved->next = next;
        if (next)
            next->prev = moved;
        else
            h->tail = moved;
        if (prev < h->head)
            prev->next = moved;
    } else {
        moved = (Blk *)func_005722A8(h, b, gap);
        func_005722F8(h, b);
    }
    return moved;
}
}
