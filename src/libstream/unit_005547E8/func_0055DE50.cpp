/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Manager layout is provisional: fixed-stride element arrays at +0x4 (0x24 each, 2),
 * +0x4C (0xC each, 7) and +0xA8 (0xE0 each, 0x2F), then bookkeeping words at +0x29F8/+0x2918
 * and the list head/tail at +0x2AA8/+0x2AAC. */
struct Manager;

struct Item {
    char pad0[8];
    Manager *owner;
    Item *next;
    char pad1[0xE0 - 0x10];
};

struct Manager {
    int state;
    char timers[2][0x24];
    char slots[7][0xC];
    int head;
    int count;
    Item items[0x2F];
};

extern "C" {
int func_005681E8(void *);
void func_00568230(void *);
void func_0055CE78(void *);
int func_0055D528(void *);
void func_0055D6F0(void *, int);
int func_0055E948(void *);

int func_0055DE50(Manager *m)
{
    m->state = 1;
    char *p = (char *)m + 4;
    for (int a = 1; a != -1; a--) {
        func_005681E8(p);
        func_00568230(p + 0x1C);
        p += 0x24;
    }
    p = (char *)m + 0x4C;
    for (int b = 6; b != -1; b--) {
        func_0055CE78(p);
        p += 0xC;
    }
    m->head = 0;
    m->count = 0;
    p = (char *)m + 0xA8;
    char *items = p;
    for (int c = 0x2F; c != -1; c--) {
        func_0055D528(p);
        p += 0xE0;
    }
    *(int *)((char *)m + 0x2918) = 6;
    *(int *)((char *)m + 0x29F8) = 6;
    for (int i = 0; i < 0x2E; i++) {
        Item *item = (Item *)((char *)m + 0xA8 + i * 0xE0);
        item->owner = m;
        item->next = i < 0x2F ? item + 1 : 0;
        func_0055D6F0(item, i);
    }
    *(char **)((char *)m + 0x2AA8) = items;
    *(char **)((char *)m + 0x2AAC) = (char *)m + 0x2808;
    return func_0055E948((char *)m + 0x2AB0);
}
}
