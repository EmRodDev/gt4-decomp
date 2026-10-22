/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Constructor of mToolTipFace: runs the mWidget constructor, installs the mToolTipFace vtable at +4 and sets every member to its start value.
 * The Style block at +0xA0 is built by func_00246F58 and then its words at +0x18/+0x1C/+0x20 are cleared. The std::string at +0x104 is an empty-rep clone
 * (grab: clone when the selfish flag is set, otherwise bump the ref count). Words +0x108, +0x110, +0x114 and the byte +0x118 are 0, +0x10C is 1; floats +0x11C..+0x12C
 * and the two 3-float vectors at +0x130 and +0x13C are 0.0, +0x148 is 8.0 and +0x14C is 10.0, +0x150 is 0. What each member means is unknown (no names recovered). */
struct Rep { int len, cap, ref; bool selfish;
    char *grab();
};
extern Rep D_00659FA8;
extern char mToolTipFace__vtable[];
extern "C" char *func_005C2560(Rep *);
inline char *Rep::grab() { if (selfish) return func_005C2560(this); ++ref; return (char *)(this + 1); }
struct Str { char *p; };
union Vec { struct { float x,y,z; } v; float a[3]; };
struct Style { char pad[0x18]; int a18,a1c,a20; char rest[0x40]; };
struct Obj {
    int a0; void *vt; char pad[0x98]; Style style;
    Str s104; int a108,a10c,a110,a114; char a118; char p119[3];
    float f11c,f120,f124,f128,f12c; Vec v130,v13c; float f148,f14c; int a150;
};
extern "C" void *mWidget__structor_0(void *);
extern "C" void *func_00246F58(Style *);
static inline void init_str(Str *styleBlock) { styleBlock->p = D_00659FA8.grab(); }
static inline void init_vec(Vec *v, float zero) { v->v.x=zero; v->v.y=zero; v->v.z=zero; }
extern "C" void mToolTipFace__structor_0(Obj *self) {
    Style *styleBlock = &self->style;
    Str *textStr = &self->s104;
    mWidget__structor_0(self);
    self->vt = mToolTipFace__vtable;
    func_00246F58(styleBlock);
    Rep *emptyRep = &D_00659FA8;
    char *data = (char *)(emptyRep + 1);
    if (emptyRep->selfish) data = func_005C2560(emptyRep);
    else ++emptyRep->ref;
    textStr->p = data;
    self->f11c=0.0f;
    float zero = self->f11c;
    self->a108=0; self->a10c=1; self->a110=0; self->a114=0; self->a118=0;
    self->f120=zero; self->f124=zero; self->f128=zero; self->f12c=zero;
    init_vec(&self->v130,zero);
    init_vec(&self->v13c,zero);
    self->f148=8.0f; self->f14c=10.0f; self->a150=0;
    styleBlock->a18=0; styleBlock->a1c=0; styleBlock->a20=0;
}
