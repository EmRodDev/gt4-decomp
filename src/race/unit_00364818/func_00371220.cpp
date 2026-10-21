/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Places an object on a record of the table at root->p4->pCC (records of 64 bytes, indexed by `recordIndex`) at the horizontal
 * position `position` (x and z; its y is not used): puts a probe point at height 100 above it (func_00370DD0 is called with that point),
 * stores x/z in the 2D vector at +0x88, and when the record's halfword +6 is non-zero or `forceHeading` is set derives a heading from the
 * direction to the record's point (+0x18/+0x1C) as func_0036EAD8(func_0036ECD0(dx, dz) + 90.0f) (inferred: an atan2 plus a quarter turn; the
 * units are not confirmed). Finally func_003710D8 updates the scalar, which is kept at +0xCC. */
typedef int s32; typedef float f32; typedef unsigned short u16;

struct Rec { char pad0[6]; u16 h6; char pad8[0x10]; f32 f18, f1C; };
struct Tab { char pad0[0x1C]; char *p1C; };
struct Mid { char pad0[0xCC]; Tab *pCC; };
struct Root { char pad0[4]; Mid *p4; };
struct Obj {
    Root *root;
    char pad4[0x44];
    f32 f48[4];
    f32 f58[2];
    f32 f60[3];
    f32 f6C, f70, f74;
    char pad78[0x84 - 0x78];
    s32 i84;
    f32 f88[2];
    char pad90[0xCC - 0x90];
    f32 fCC;
};

extern "C" f32 func_0036EAD8(f32) throw();
extern "C" f32 func_0036ECD0(f32, f32);
extern "C" f32 func_0036F4E0(void *) throw();
extern "C" void func_00370DD0(Obj *, void *, s32) throw();
extern "C" void func_003710D8(Obj *, f32 *, f32 *, void *, s32) throw();
extern "C" void func_003C8F60(void *, f32 *);

extern "C" void func_00371220(Obj *self, s32 recordIndex, f32 *position, s32 forceHeading) {
    f32 scalar;
    f32 position2D[2];
    f32 *probePoint = self->f60;
    f32 *posZ = (f32 *)((char *)position + 8);
    scalar = func_0036F4E0(self->f48);
    Tab *table = self->root->p4->pCC;
    f32 posX = position[0];
    f32 posZ2 = *posZ;
    self->f60[0] = posX;
    self->f60[1] = 100.0f;
    self->f60[2] = posZ2;
    self->i84 = -1;
    func_00370DD0(self, probePoint, recordIndex);
    position2D[0] = position[0];
    position2D[1] = *posZ;
    func_003C8F60(self->f88, position2D);
    Rec *record = (Rec *)(table->p1C + (recordIndex << 6));
    if (record->h6 != 0 || forceHeading != 0) {
        f32 recordZ;
        f32 deltaX = record->f18 - position[0];
        recordZ = *posZ;
        f32 deltaZ = record->f1C - recordZ;
        f32 direction = func_0036ECD0(deltaX, deltaZ);
        f32 heading = func_0036EAD8(direction + 90.0f);
        f32 *headingPtr = &self->f6C;
        *headingPtr = heading;
        self->f70 = 0;
        self->f74 = 0;
    }
    func_003710D8(self, &scalar, &self->f6C, probePoint, recordIndex);
    self->fCC = scalar;
}
