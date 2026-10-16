typedef struct Node { int f0; int f4; struct Node *next; } Node;
typedef struct Bucket { int f0; Node *head; } Bucket;
typedef struct Obj { char pad0[0x3c]; unsigned count; char pad40[8]; Bucket *buckets; char pad4c[0x14]; void *f60; void *pool; struct Obj *parent; struct Obj *next; } Obj;
int func_00512350(void *, Node *);
int func_00538C68(void *);
int func_00512268(void *);
int func_00510CD0(Obj *self) {
    if (self) {
        unsigned i;
        for (i = 0; i < self->count; i++) {
            Node *n = self->buckets[i].head;
            while (n) {
                Node *next = n->next;
                func_00512350(self->pool, n);
                n = next;
            }
        }
        if (self->buckets) func_00538C68(&self->buckets);
        if (self->pool) func_00512268(self->pool);
        if (self->f60) func_00538C68(&self->f60);
        if (self->parent == 0) {
            Obj *child = self->next;
            while (child) {
                func_00510CD0(child);
                child = self->next;
            }
        } else {
            Obj *prev = self->parent;
            Obj *cur = prev->next;
            while (cur != self) { prev = cur; cur = cur->next; }
            if (prev && cur) prev->next = cur->next;
        }
        func_00538C68(&self);
    }
    return 0;
}
