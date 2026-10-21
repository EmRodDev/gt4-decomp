/* Rebuilds the per-node flag array self->flags (one byte per node of the list owned by self). For each node it calls virtual slot +0xA8 of *source with the node and its index wrapped in two ref-counted handles and stores whether the returned handle is non-null. What the flag means is unknown. The Handle temporaries mimic the original's ref-counted values, which is why the loop body is heavy. */
#include "types.h"

extern "C" void func_0030BB18(void *arg0);
extern "C" void func_00309378(void *arg0, s32 arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

struct Handle {
    void *p;
    Handle() { func_0030BB18(this); }
    void *get() const { return p; }
    ~Handle() { func_00309378(this, 2); }
    Handle &operator=(const Handle &rhs) {
        if (this != &rhs) {
            void *np = rhs.p;
            if (np != 0) {
                func_003285A8(np);
            }
            if (p != 0) {
                func_003285F8(p);
            }
            p = np;
        }
        return *this;
    }
};

struct Handle16 {
    void *p;
    char pad[0xC];
};

struct Self {
    char pad0[0xF0];
    u8 *flags;
};

struct VEntry {
    short delta;
    short index;
    void (*fn)(void *self, struct Handle16 *out, s32 n, struct Handle *args);
};

struct VObj {
    char pad0[4];
    struct VEntry *vtbl;
};

extern "C" s32 func_00206880(struct Self *arg0);
extern "C" void *func_00206868(struct Self *arg0);
extern "C" void *func_0025C300(void *arg0);
extern "C" void free(void *arg0);
extern "C" u8 *malloc(s32 arg0);
extern "C" void func_00309348(struct Handle16 *arg0, void **arg1);
extern "C" void func_002FE278(struct Handle16 *arg0, s32 arg1);
extern "C" void func_002FC870(struct Handle16 *arg0, s32 arg1);
extern "C" void func_002FE2E0(struct Handle16 *arg0);
extern "C" s32 func_002FE250(void *arg0);

extern "C" void func_002DC178(struct Self *self, struct VObj **source) {
    if (*source != 0) {
        s32 count = func_00206880(self);
        if (count > 0) {
            void *oldFlags = self->flags;
            s32 i;
            s32 index;
            void *listNode;
            if (oldFlags != 0) {
                self->flags = 0;
                free(oldFlags);
            }
            self->flags = malloc(count);
            for (i = 0; i < count; i++) {
                self->flags[i] = 0;
            }
            for (index = 0, listNode = func_00206868(self); listNode != 0; listNode = func_0025C300(listNode), index++) {
                Handle args[2];
                Handle16 result;
                void *nodeRef;
                nodeRef = listNode;
                func_00309348(&result, &nodeRef);
                args[0] = *(Handle *)&result;
                func_00309378(&result, 2);
                func_002FE278(&result, index);
                args[1] = *(Handle *)&result;
                func_002FC870(&result, 2);
                func_002FE2E0(&result);
                {
                    struct VObj *object = *source;
                    struct VEntry *slot = (struct VEntry *)((char *)object->vtbl + 0xA8);
                    slot->fn((char *)object + slot->delta, &result, 2, args);
                }
                self->flags[index] = func_002FE250(((Handle *)&result)->get()) != 0;
                func_002FC870(&result, 2);
            }
        }
    }
}
