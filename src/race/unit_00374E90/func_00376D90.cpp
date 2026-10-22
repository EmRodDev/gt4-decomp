/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Sibling of func_00376E68 with the same context layout: tries to activate an object into a slot table and reports
 * success. func_003FD980 fills a small result (id, an extra int, a hit value, a float position) for the lookup
 * key; with no hit the function returns false. Otherwise func_003FD940 turns the hit and position into a value,
 * the param is converted to a float by func_00578598, and the object is called through its vtable at +0x138 (entry
 * with this-adjustment) with the key, the int at source+0x80, the extra int, the hit, the derived value and the
 * float. The object pointer is then stored in the slot (0x19C bytes per slot, pointer at +0x13C), doneFlag is set
 * to 1 and true is returned. Meaning of the hit and the extra value is unknown. */
typedef int s32;
typedef short s16;
typedef float f32;

struct Obj {
    char pad0[0x80];
    s32 unk80;
};

struct Out {
    s32 id;
    s32 extra;
    s32 hit;
    f32 pos;
};

struct Ctx {
    Obj *source;
    char *slots;
    char *object;
    char pad0C[4];
    s32 slotIndex;
    void *lookupKey;
    s32 *doneFlag;
    void *param;
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *self, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, f32 paramFloat);
};

extern "C" void func_003FD980(Obj *o, void *s, Out *out);
extern "C" s32 func_003FD940(s32 hit, f32 pos);
extern "C" f32 func_00578598(void *a);

extern "C" bool func_00376D90(Ctx *ctx)
{
    Out out;
    s32 value80;
    s32 hit;
    s32 derived;
    char *objectPtr;

    value80 = ctx->source->unk80;
    func_003FD980(ctx->source, ctx->lookupKey, &out);
    if (out.hit == 0) {
        return 0;
    }
    hit = out.hit;
    derived = func_003FD940(hit, out.pos);
    f32 paramFloat = func_00578598(ctx->param);
    objectPtr = ctx->object;
    VEntry *e = (VEntry *)(*(char **)objectPtr + 0x138);
    e->fn(objectPtr + e->delta, ctx->lookupKey, value80, out.extra, hit, derived, paramFloat);
    char *slot=ctx->slots;
    slot+=ctx->slotIndex*0x19C;
    *(char **)(slot+0x13C)=ctx->object;
    *ctx->doneFlag = 1;
    return 1;
}
