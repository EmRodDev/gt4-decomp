/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Initializes a tracker object (purpose unknown) bound to `source` and an item index. With a source it clamps `itemIndex` to the
 * valid range of the source's item list (count at [0], items at [2]; the list pointer is at source+0x60), remembers the index at +0xC and
 * the item at +0x10 and sets the bound flag at +8. Then it clears the two 0x28-byte element records, sets 1.0f at +0x74, configures the
 * curve member with func_0036F710 (1.0, 0.04, 0.01, about 0.034; meaning of the numbers unknown), zeroes the float and the low byte of the
 * flags of the three entries after it, and finishes with func_003FC108. The odd pointer walk at the end reproduces the compiler's
 * induction variables. */
struct Vec3 { float x, y, z; };
struct Elem { Vec3 a, b; int f18, f1c, f20, f24, f28; };
struct Tail { float c; int pad; unsigned d; };
struct Ent { float a, b, c; int pad; unsigned d; };
struct List { int n; int p4; int *items; };
struct Src { char p[0x60]; int l; };
struct Obj {
    Src *src; int v4; int v8; short vC; int v10;
    Elem e[2];
    int v6c; int v70; float v74; Ent t[3];
    char curve[1];
};
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void func_0036F710(void *, float, float, float, float);
extern "C" void func_003FC108(Obj *);

extern "C" void func_003FBAB0(Obj *self, Src *source, int param, int itemIndex)
{
    self->v4 = param;
    self->src = source;
    self->v8 = 0;
    self->vC = itemIndex;
    self->v10 = 0;
    if (source) {
        int itemCount = ((int *)source->l)[0];
        if (itemIndex < 0) itemIndex = 0;
        self->v8 = 1;
        if (itemIndex >= itemCount) itemIndex = itemCount - 1;
        int item = ((int *)((int *)source->l)[2])[itemIndex];
        self->vC = itemIndex;
        self->v10 = item;
    }
    char *fieldBase;
    for (int elementIndex = 0; elementIndex < 2; elementIndex++) {
        func_005A48D8(&self->e[elementIndex].a, 0, 12);
        func_005A48D8(&self->e[elementIndex].b, 0, 12);
        self->e[elementIndex].f18 = 0;
        self->e[elementIndex].f1c = 0;
        self->e[elementIndex].f20 = 0;
        fieldBase = (char *)&self->v8;
        self->e[elementIndex].f24 = 0;
        self->e[elementIndex].f28 = 0;
    }
    self->v6c = 0;
    self->v70 = 0;
    self->v74 = 1.0f;
    func_0036F710(self->curve, 1.0f, 0.04f, 0.01f, 0x1.16872ap-5f);
    unsigned mask = ~0xFFu;
    float *entryFloat = (float *)(fieldBase + 0x70);
    Tail *entryTail = (Tail *)((char *)self + 0x80);
    int remaining = 2;
    do {
        *entryFloat = 0;
        entryFloat += 5;
        remaining--;
        entryTail->d &= mask;
        entryTail = (Tail *)((char *)entryTail + 0x14);
    } while (remaining >= 0);
    func_003FC108(self);
}
