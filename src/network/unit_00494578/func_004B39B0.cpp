/* Copies entry `entryIndex` of a table into the output object at +0xC through its virtual +0x18 (inferred: the entry's start offset
 * comes from func_004B38F8 or func_004B3938 depending on func_004B38A0, its length is the next offset minus this one, and the base is
 * the value at +4). Returns the handle func_004B3C68 produced for the index; nothing is written when that lookup fails
 * (its out flag is non-zero). In the second format it also calls func_004B36E0 with the handle afterwards. The meaning of the table is unknown. */
struct VEnt { short adj; short pad; void *fn; };
struct Obj { char *vt; };
struct Self { char *vt; int f4; int f8; Obj *oC; };
typedef void (*F0)(void *);
typedef int (*F1)(void *);
typedef int (*F5)(void *, int, int, int, int);
extern "C" void func_004B36E0(int, int);
extern "C" int func_004B38A0(Self *);
extern "C" int func_004B38F8(Self *, int);
extern "C" int func_004B3938(Self *, int);
extern "C" int func_004B3C68(char *, int, int *);

static inline void call1(Obj *b) {
    VEnt *e = (VEnt *)(b->vt + 0x10);
    ((F0)e->fn)((char *)b + e->adj);
}
static inline int call2(Obj *o) {
    VEnt *e = (VEnt *)(o->vt + 0x10);
    return ((F1)e->fn)((char *)o + e->adj);
}
static inline int call3(Obj *b, int a, int c, int d, int e5) {
    VEnt *e = (VEnt *)(b->vt + 0x18);
    return ((F5)e->fn)((char *)b + e->adj, a, c, d, e5);
}

extern "C" int func_004B39B0(Self *self, int entryIndex) {
    int lookupFailed = 0;
    int handle = func_004B3C68((char *)self + 0x10, entryIndex, &lookupFailed);
    if (lookupFailed == 0) {
        if (func_004B38A0(self) == 0) {
            int startOffset = func_004B38F8(self, entryIndex);
            int length = func_004B38F8(self, entryIndex + 1) - startOffset;
            int dataBase = self->f4;
            call1(self->oC);
            int position = call2((Obj *)self);
            call3(self->oC, handle, position, dataBase + startOffset, length);
        } else {
            int startOffset = func_004B3938(self, entryIndex);
            int length = func_004B3938(self, entryIndex + 1) - startOffset;
            int dataBase = self->f4;
            call1(self->oC);
            int position = call2((Obj *)self);
            call3(self->oC, handle, position, dataBase + startOffset, length);
            func_004B36E0(handle, call2((Obj *)self));
        }
    }
    return handle;
}
