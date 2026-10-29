/* compiler: ee-gcc2.96-no-strict-aliasing */
struct NameRef { const char *name; };
struct Entry { NameRef *ref; int unk4; };
struct Node {
    int f0;
    Node *link;
    int f8;
    unsigned int count;
    int f10;
    Entry entries[1];
};
struct State { int unk0; Node *node; };
struct Slot { const char *name; Entry *found; int unk8; };
extern State D_008468D0;
extern Slot D_006239A8[10];
extern "C" void *func_004624F0(void);
extern "C" int func_005A5A30(char *, int, const char *, ...);
extern "C" int func_004AE230(int, int, int);
extern "C" void func_00460488(Node *, void (*)(void *), int);
extern "C" int func_0057F238(const char *, const char *);

extern "C" void func_00460D50(void) {
    State *s = &D_008468D0;
    if (s->node == 0) {
        char path[0x70];
        unsigned int i = 0;
        func_005A5A30(path, 0x70, "%s/%s/%s", "/music", func_004624F0(), "mid.inf");
        int dummy[8];
        func_004AE230((int)dummy, (int)path, 1);
        Node *n = (Node *)dummy[4];
        unsigned int off2 = 0;
        unsigned int off1 = 0;
        func_00460488(n, 0, 0);
        s->node = n;
        Node **q = &n->link;
        do {
            unsigned int j = 0;
            const char **name = (const char **)((char *)D_006239A8 + off1);
            if (n->count != 0) {
                Entry *e = (Entry *)((char *)n + 0x14);
                Entry **found = (Entry **)((char *)D_006239A8 + 4 + off2);
                Entry **cur = (Entry **)((char *)q + 0x10);
                do {
                    NameRef *ref = (NameRef *)*cur;
                    cur += 2;
                    if (func_0057F238(*name, ref->name) == 0) {
                        *found = e;
                        break;
                    }
                    j++;
                    e++;
                } while (j < n->count);
            }
            i++;
            off2 += 12;
            off1 += 12;
        } while (i < 10);
    }
}
