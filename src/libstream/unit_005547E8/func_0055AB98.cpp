/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Handler {
    short delta;
    int (*function)(void *self);
};

struct Sequence {
    int pending;
    char pad0[0x28 - 4];
    long long target;
    char pad1[0x34 - 0x30];
    int command;
    char pad2[0x44 - 0x38];
    float time;
    float step;
    float limit;
    char pad3[0x58 - 0x50];
    unsigned char *cursor;
    int pad5C;
    int mode;
    Handler *handlers;
};

static inline int isDue(Sequence *s)
{
    return s->time - s->limit >= 0.0f;
}

extern "C" {
void func_0055CFE8(void *out, long long id);
void func_0055C9A0(int, void *, void (*)(void), void *, int);
void func_0055AB00(void);

void func_0055AB98(Sequence *s)
{
    if (s->pending) {
        int id[16];
        func_0055CFE8(id, s->target);
        func_0055C9A0(id[0], id, func_0055AB00, s, 0);
        s->pending = 0;
    }
    if (s->mode == 2) {
        unsigned char **cursor = &s->cursor;
        s->time += s->step;
        while (isDue(s)) {
            if ((signed char)*s->cursor < 0)
                s->command = *(*cursor)++;
            Handler *h = &s->handlers[1];
            if (h->function((char *)s + h->delta))
                break;
        }
    }
    if (s->mode == 3) {
        if (!s->target)
            s->mode = 0;
    }
    /* The exit handler's result is ignored: it is called as a void function. */
    Handler *h = &s->handlers[2];
    ((void (*)(void *))h->function)((char *)s + h->delta);
}
}
