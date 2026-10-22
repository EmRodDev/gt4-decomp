/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Tries to activate an object in a slot table and reports success. func_003FDA00 looks up a 3-int position for
 * self->id in self->source; on failure the function returns false. Otherwise it converts self->param to a float
 * with func_00578598, calls the virtual method at vtable offset 0x138 of self->object (the vtable entry holds a
 * this-adjustment and a function pointer, so the call is written out by hand) with id, the int at source+0x80, the
 * y and z of the position, the constant 1 and the float, then stores the object pointer into slot slotIndex of the
 * table (0x19C bytes per slot, pointer at +0x13C), sets doneFlag to 1 and returns true. The x component of the
 * lookup is never used. The inline helper vcall is left unused; the call is spelled out in the body because that
 * is what matched. */
typedef int s32;
typedef short s16;
struct V;
struct VEntry { s16 delta; s16 index; void (*fn)(void *, s32, s32, s32, s32, s32, float); };
struct V { char *vtbl; };
struct Q { char pad[0x80]; s32 u80; };
struct Slot { char pad[0x13C]; V *u13C; char pad2[0x19C - 0x140]; };
static inline void vcall(V *o, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, float f) {
    VEntry *e = (VEntry *)(o->vtbl + 0x138);
    e->fn((char *)o + e->delta, a1, a2, a3, a4, a5, f);
}
struct A {
    Q *source;
    Slot *slots;
    V *object;
    s32 pC;
    s32 slotIndex;
    s32 id;
    s32 *doneFlag;
    s32 param;
};
struct Vec3i { s32 x, y, z; };
extern "C" bool func_003FDA00(Q *, s32, Vec3i *);
extern "C" float func_00578598(s32);
extern "C" bool func_00376E68(struct A *self) {
    Vec3i v;
    bool r = func_003FDA00(self->source, self->id, &v);
    if (!r) return 0;
    {
        s32 z = v.z;
        s32 qValue80 = self->source->u80;
        float f = func_00578598(self->param);
        V *o = self->object;
        VEntry *e = (VEntry *)(o->vtbl + 0x138);
        e->fn((char *)o + e->delta, self->id, qValue80, v.y, z, 1, f);
        char *slot = (char *)self->slots;
        slot += self->slotIndex * 0x19C;
        *(V **)(slot + 0x13C) = self->object;
        *self->doneFlag = 1;
        return 1;
    }

}
