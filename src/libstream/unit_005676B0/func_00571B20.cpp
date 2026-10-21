/* compiler: ee-gcc2.96-nogcse */
struct Node { int kind, busy; unsigned int step; char pad[0x30]; int flag; };
struct Obj { char pad[0x18]; unsigned int size; char *base; char pad20[0x1c]; unsigned int offset; };
extern "C" int func_00571B20(Obj *self, Node **out, unsigned char *flag) {
    int r = 2;
    if (self && out) {
        *out = 0;
        if (flag) {
            *flag = 0;
            unsigned int off = self->offset;
            char *base = self->base;
            Node *n = (Node *)(base + off);
            if (n->busy == 1) {
                unsigned int limit = self->size;
                unsigned int start = off;
                char *scanbase = base;
                do {
                    off = off + n->step + 64;
                    if (off >= limit) off = 0;
                    n = (Node *)(scanbase + off);
                    if (off == start) {
                        *out = 0;
                        *flag = 0;
                        return 0;
                    }
                } while (n->busy == 1);
            }
            int kind = n->kind;
            int value;
            if (kind == 1 && (value = n->flag) == kind) {
                *out = n;
                *flag = value;
            } else {
                *out = 0;
                *flag = 0;
            }
            r = 0;
        }
    }
    return r;
}
