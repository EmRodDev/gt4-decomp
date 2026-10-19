/* compiler: ee-gcc2.96-no-strict-aliasing */
struct SubVEntry { short delta; short index; void (*fn)(void *); };
struct Sub { SubVEntry *vtbl; };
struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj {
    Sub *p;
    int pad;
    VEntry *vtbl;
    char padC[0xC];
    char car_model[0x5C8];
    char pad5E0[0x1660 - 0x5E0];
    void *unk1660;
    void *unk1664;
};
extern char D_00844368[];
extern "C" void func_00450CB8(void *, void *);
extern "C" void RaceCarModel__virtual_15(Obj *o) {
    o->unk1660 = D_00844368;
    o->unk1664 = D_00844368;
    SubVEntry *se = &o->p->vtbl[2];
    se->fn((char *)o->p + se->delta);
    func_00450CB8(o->car_model, o->p);
    VEntry *ve = &o->vtbl[3];
    ve->fn((char *)o + ve->delta);
}
