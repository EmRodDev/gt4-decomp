/* compiler: ee-gcc2.96-nogcse */
typedef unsigned char u8;
struct Item {
    int fd;
    int sig;
    char pad8[0x4C - 8];
    char blockA[0x58 - 0x4C];
    int f58;
    char pad5C[0x88 - 0x5C];
    int h88;
    char pad8C[0xC8 - 0x8C];
    int hC8;
    char blockB[0x108 - 0xCC];
    int h108;
    int mode;
    char pad110[0x114 - 0x110];
};
struct Core {
    Item items[2];
    char pad[0x4FC - 2 * sizeof(Item)];
    int count;
    char pad500[0x508 - 0x500];
    unsigned mask;
};
struct Info { char pad[0xC]; u8 flag; char pad2[0x18 - 0xD]; };
extern "C" {
void func_00555130(Core *, int);
void func_00555920(Core *, int);
void func_005559A0(Core *, int);
void func_00555A18(Core *, int);
void func_00556268(Core *, void *);
int func_00560AC0(int, Info *);
int func_00560B88(int, Item *);
int func_00560C28(int);
int func_00560CA0(int, int, int *);
int func_00560D50(int, int, int);
int func_00561538(int);
}
extern "C" void func_00555760(Core *c) {
    Info info;
    int fd;
    Item *it = c->items;
    int i;
    for (i = 0; i < 2; i++, it++) {
        if (it->fd != -1) {
            fd = it->fd;
            it->fd = -1;
            func_00561538(it->h108);
            func_00561538(it->h88);
            func_00561538(it->hC8);
            func_00560C28(fd);
            func_00555130(c, i);
        }
    }
    c->count = 0;
    for (int n = 0; n < 2; n++) {
        if (func_00560AC0(n, &info) < 0) break;
        int idx = (info.flag ^ 1) == 0;
        if (c->mask & (1 << idx)) {
            int mode = 1;
            Item *e = &c->items[idx];
            func_00560B88(n, e);
            fd = e->fd;
            func_00560CA0(fd, 0x10005, &e->sig);
            if (e->sig == 0x46DC298) {
                func_00560D50(fd, 4, 1);
                mode = 2;
            }
            func_00555920(c, idx);
            func_005559A0(c, idx);
            func_00555A18(c, idx);
            e->f58 = 0;
            func_00556268(c, e->blockA);
            func_00560D50(fd, 2, 0);
            func_00556268(c, e->blockB);
            e->mode = mode;
            c->count = c->count + 1;
        }
    }
}
