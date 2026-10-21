/* compiler: ee-gcc2.9-991111 */
typedef struct Node {
    int magic0, magic4;
    struct Node *link, *next;
    char pad10[6]; unsigned short flags; char pad18[8];
    void (*fn)(int, struct Node *);
} Node;
extern int D_00657A80;
extern Node *D_00875898;
extern Node D_008758A0;
int func_005868E0(Node *, Node *);
int func_005868F0(Node *, Node *);
int func_00586948(Node *, Node *);
int func_00586C08(Node *, Node *);
void func_005ADF20(int);
int func_005B72A8(void);
int func_005B72F8(void);
int func_00585B10(Node *arg) {
    int intr;
    Node *p, *q, *next, *list, *outer;
    Node **slot;
    if (!D_00657A80) return 0x81058001;
    if (!arg || arg->magic0 != 0x4c785265 || arg->magic4 != 0x41004269)
        return 0x81059039;
    intr = func_005B72A8();
    list = 0;
    p = D_00875898;
    while (p) {
        if (p == arg || func_005868F0(arg,p)) {
            if (p == arg || func_005868E0(arg,p) <= 0) {
                if (intr) func_005B72F8();
                return 0x81059036;
            }
            q = p->next;
            slot = &p->next;
            p->next = 0;
            if (q) {
                outer = p->link;
                do {
                    next = q->next;
                    if (!(q->flags & 1)) {
                        q->next = list;
                        list = q;
                    } else {
                        *slot = q;
                        q->next = 0;
                        slot = &q->next;
                    }
                    q = next;
                } while (next);
            } else outer = p->link;
        } else outer = p->link;
        p = outer;
    }
    q = &D_008758A0;
    while (q->next) {
        if (func_00586948(arg, q->next)) {
            next = q->next->next;
            q->next->next = list;
            list = q->next;
            q->next = next;
        } else q = q->next;
    }
    arg->next = 0;
    while (list) {
        next = list->next;
        func_00586C08(list, arg);
        list->next = arg->next;
        arg->next = list;
        list = next;
    }
    arg->flags &= 0xfffe;
    arg->link = D_00875898;
    D_00875898 = arg;
    func_005ADF20(2);
    if (intr) func_005B72F8();
    arg->fn(0,arg);
    return 0;
}
