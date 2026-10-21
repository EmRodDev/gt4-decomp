/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Looks up the ground under the car: queries the collision scene (func_00395760, same query record as func_003630C0) at the car position
 * stored at +0x720, converted to the scene axes (x, z, -y). When the first answer is flagged unusable it retries with the
 * previous surface id kept at +0x5AC. On success the height goes to +0x624 and the surface id to +0x628; otherwise the stored
 * id keeps its value with the sign flipped (meaning of the flip is inferred only from the code). */
struct Loc { float x, y, z; int w; float out; char pad[0x30 - 0x14]; unsigned char flag; };
struct Ctx { char p[0xCBD8]; void *mCBD8; };
struct S104 { char p0[8]; float m8; char p1[0x624 - 0xC]; float m624; int m628; };
struct Self {
    char p0[4]; Ctx *m4; char p1[0x104 - 8]; S104 s;
};
struct V3 { float x, y, z; };
extern "C" void func_00395760(void *, Loc *);

extern "C" void func_00350C20(Self *self) {
    S104 *s = &self->s;
    V3 *carPos = (V3 *)((char *)self + 0x720);
    Ctx *raceCtx = self->m4;
    Loc query;
    s->m624 = s->m8;
    query.w = s->m628;
    query.x = carPos->x;
    query.y = carPos->z;
    query.z = -carPos->y;
    func_00395760(raceCtx->mCBD8, &query);
    unsigned char firstFlag = query.flag;
    if (firstFlag) {
        query.w = *(int *)((char *)self + 0x5AC);
        func_00395760(raceCtx->mCBD8, &query);
    }
    if (!query.flag) {
        s->m624 = query.out;
        s->m628 = query.w;
    } else {
        s->m628 = -s->m628;
    }
}
