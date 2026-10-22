/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct Node {
    unsigned char addr[16];
    unsigned char priority;
    unsigned char tag;
    short rank;
    short score;
    unsigned char x, y;
    void *data;
    struct Node *next;
} Node;
void *func_004C4070(void *, const void *, unsigned);
void *func_004C8C20(int, int);
void func_004C8C38(int, void *);

int func_004C7140(int owner, Node **head, void *src, void *extra, unsigned char *xy,
                  unsigned char tag, short rank, short score, unsigned char *priority, int cmp)
{
    int clear = 0;
    Node *n;

    for (n = *head; n != 0; n = n->next) {
        if (n->tag != tag) continue;
        if (n->data == 0) {
            if (extra != 0) {
                src = 0;
                break;
            }
        } else {
            clear = extra == 0;
        }
        if (!clear) {
            if (n->rank < rank) n->rank = rank;
            if (n->score < score || (n->score == score && cmp < n->priority)) {
                func_004C4070(n, src, 16);
                if (priority == 0) n->priority = 0;
                else n->priority = *priority;
                n->score = score;
                if (extra != 0) {
                    if (n->data == 0) {
                        n->data = func_004C8C20(owner, 16);
                        if (n->data == 0) return 0x80000306;
                    }
                    func_004C4070(n->data, extra, 16);
                } else if (n->data != 0) {
                    func_004C8C38(owner, n->data);
                    n->data = 0;
                }
                func_004C4070(n, src, 16);
                if (priority == 0) n->priority = 0;
                else n->priority = *priority;
                n->score = score;
                if (xy != 0) {
                    n->x = *xy++;
                    n->y = *xy;
                } else {
                    n->x = 0;
                    n->y = 0;
                }
            }
        } else {
            if (n->data != 0) {
                func_004C8C38(owner, n->data);
                n->data = 0;
                n->x = 0;
                n->y = 0;
            }
            func_004C4070(n, src, 16);
            if (priority == 0) n->priority = 0;
            else n->priority = *priority;
            n->score = score;
        }
        src = 0;
        break;
    }
    if (src != 0) {
        n = (Node *)func_004C8C20(owner, 32);
        if (n == 0) return 0x80000306;
        func_004C4070(n, src, 16);
        if (extra != 0) {
            void *p = func_004C8C20(owner, 16);
            n->data = p;
            if (p == 0) {
                func_004C8C38(owner, n);
                return 0x80000306;
            }
            func_004C4070(p, extra, 16);
        } else {
            n->data = 0;
        }
        if (priority == 0) n->priority = 0;
        else n->priority = *priority;
        n->score = score;
        n->rank = rank;
        n->tag = tag;
        if (xy != 0) {
            n->x = xy[0];
            n->y = xy[1];
        } else {
            n->x = 0;
            n->y = 0;
        }
        if (*head != 0) n->next = *head;
        else n->next = 0;
        *head = n;
    }
    return 0;
}
