/* compiler: ee-gcc2.9-991111 */
struct Node { int x; volatile int count; unsigned char *bytes; };
struct Tty { char pad[24]; struct Node *node; };
extern struct Tty D_00886410;
extern void func_005AEFE8(struct Node *);
int func_005AF338(char *buf, int size) {
    int i = 0;
    while (i < size) {
        char *out = buf + i;
        int next = i + 1;
        while (D_00886410.node->count == 0) { }
        *out = *D_00886410.node->bytes;
        func_005AEFE8(D_00886410.node);
        if (*out == 10 || *out == 13) return next;
        i = next;
    }
    return i;
}
