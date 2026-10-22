/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Switches the object kept in a slot of the owner's slot table to newObject, unless it is already the one there.
 * The current object comes from the virtual query at owner's vtable+0xD8 (the same query as in func_00375860) for
 * slotIndex. If it differs, its float from a virtual call at vtable+0xC8 is read, newObject gets a virtual call at
 * its vtable+0x140 with param and 0 and its word at +0xE8 is set to 3, newObject is stored in the slot (0x19C
 * bytes each, pointer at +0x13C, as in func_00376E68), out->w0 is set to 1 and the float is stored in out->f8. The
 * vtable entries carry a this-adjustment, hence the small entry structs. What the float and state 3 mean is
 * unknown. */
typedef int s32;
typedef short s16;
typedef float f32;

struct Out {
    s32 w0;
    s32 w4;
    f32 f8;
};

struct Ctx {
    char pad0[4];
    char *owner;
    char pad8[4];
    char *newObject;
    s32 slotIndex;
    s32 param;
    Out *out;
};

struct VA {
    s16 delta;
    s16 index;
    void *(*fn)(void *self, s32 a1);
};

struct VB {
    s16 delta;
    s16 index;
    f32 (*fn)(void *self);
};

struct VC {
    s16 delta;
    s16 index;
    void (*fn)(void *self, s32 a1, s32 a2);
};

extern "C" void func_00377098(Ctx *ctx)
{
    VA *ea = (VA *)(*(char **)ctx->owner + 0xD8);
    char *current = (char *)ea->fn(ctx->owner + ea->delta, ctx->slotIndex);
    if (current != ctx->newObject) {
        VB *eb = (VB *)(*(char **)current + 0xC8);
        f32 value = eb->fn(current + eb->delta);
        VC *ec = (VC *)(*(char **)ctx->newObject + 0x140);
        ec->fn(ctx->newObject + ec->delta, ctx->param, 0);
        *(s32 *)(ctx->newObject + 0xE8) = 3;
        char *record = ctx->owner + ctx->slotIndex * 0x19C;
        *(char **)(record + 0x13C) = ctx->newObject;
        ctx->out->w0 = 1;
        ctx->out->f8 = value;
    }
}
