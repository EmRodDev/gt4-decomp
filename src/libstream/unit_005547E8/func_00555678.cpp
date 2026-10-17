/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
struct Raw {
    unsigned short type;
    short a;
    short b;
    char pad6[0xE - 6];
    unsigned short c;
    unsigned short d;
    unsigned char e;
    char pad13;
    int f;
};
struct Info {
    int v0, v1, v2;
    char pad[0x1C - 0xC];
    int v7, v8, v9, v10;
};
struct Item {
    int fd;
    int value;
    Raw raw;
    char pad[0x20 - 0x8 - sizeof(Raw)];
    Info info;
    char pad2[0x114 - 0x20 - sizeof(Info)];
};
struct Owner { Item items[1]; };
extern "C" void func_00555228(Owner *);
extern "C" void func_00555268(Owner *);
extern "C" int func_00560DE8(int, int, Raw *);
extern "C" void func_00555678(Owner *o, int idx) {
    Item *it = &o->items[idx];
    Raw *raw = &it->raw;
    Info *info = &it->info;
    if (it->fd != -1 && func_00560DE8(it->fd, 1, raw) >= 0) {
        int t = raw->type;
        if (t >= 2) return;
        if (t >= 0) {
            func_00555228(o);
            info->v0 = it->value;
            info->v1 = raw->a;
            info->v2 = raw->b;
            info->v7 = raw->c;
            info->v8 = raw->d;
            info->v9 = raw->e;
            info->v10 = raw->f;
            func_00555268(o);
        }
    }
}
