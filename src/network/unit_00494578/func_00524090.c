typedef int s32;
typedef unsigned short u16;
typedef struct Obj Obj;
typedef struct Entry { s32 x; Obj *a; Obj *b; char pad[0x38]; } Entry;
typedef struct State { void *handle; char pad[0x80]; Entry *entries; char pad2[0x14]; u16 count; } State;

extern s32 func_00529048(void *, Obj *, s32, s32 *, s32 *, s32 *);

s32 func_00524090(State *p, u16 i, s32 *out2, s32 *out1, s32 *out4, s32 *out3) {
    s32 a = 0, b = 0, c = 0;
    if (p == 0) return 2;
    if (i >= p->count) return 2;
    if (out2 == 0) return 2;
    if (out4 == 0) return 2;
    if (out1 == 0) return 2;
    if (out3 == 0) return 2;
    *out1 = 0; *out2 = 0; *out3 = 0; *out4 = 0;
    if (p->entries[i].a) {
        if (func_00529048(p->handle, p->entries[i].a, 0, &a, &b, &c)) return 0;
        *out1 += a; *out2 += b;
        if (func_00529048(p->handle, p->entries[i].a, 1, &a, &b, &c)) return 0;
        *out3 += a; *out4 += b;
    }
    if (p->entries[i].b) {
        if (func_00529048(p->handle, p->entries[i].b, 0, &a, &b, &c)) return 0;
        *out1 += a; *out2 += b;
        if (func_00529048(p->handle, p->entries[i].b, 1, &a, &b, &c)) return 0;
        *out3 += a; *out4 += b;
    }
    return 0;
}
