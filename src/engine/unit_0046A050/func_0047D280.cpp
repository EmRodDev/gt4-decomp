/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Constructor of an object bound to an Info record (purpose of the object and of the records is unknown). Stores the first
 * and fifth arguments and a constant pointer (D_00688A20), starts an empty refcounted string, and when the record exists copies its
 * name (if any), its value at +8 and one 9-int item of its vector at +0x18, selected by `itemIndex - info->f2` clamped to the last element
 * (inferred from the min() helper); with no record both items are cleared by func_00474ED0. */
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
struct Item { s32 w[9]; };
struct Info;
typedef int Cnt;
struct Vec { Item *begin; Cnt size; Item &operator[](int i) { Item *p=begin+i; return *p; } };
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct SV { const char *p; s32 len; };
struct Info { char pad0[2]; short f2; char pad4[4]; u16 f8; char padA[0xe]; Vec v18; SV f20; };
struct Info;
struct Str { char *p; };
struct Self {
    s32 f0; Info *f4; Item i8; char pad2c_[0]; Item i2c; s32 f50; Str s; s32 f58; s32 f5C;
};
extern "C" void func_00474ED0(void *) throw();
extern "C" s32 func_0057F260(const char *) throw();
extern "C" char *strobe__toUpper(void *);
extern "C" void *strobe__Any__setMember(void *, u32, u32, const char *, u32);
extern char D_00659E20[];
extern char D_00688A20[];

static inline const int &mn(const int &a, const int &b) { return b < a ? b : a; }

extern "C" void func_0047D280(Self *self, s32 param1, Info *infoArg, s32 unusedParam3, Cnt itemIndex, s32 param5) {
    Str *namePtr = &self->s;
    self->f0 = param1;
    self->f5C = (s32)D_00688A20;
    self->f4 = infoArg;
    Rep *emptyRep = (Rep *)D_00659E20;
    char *chars;
    if (emptyRep->sel != 0) {
        chars = (char *)strobe__toUpper(emptyRep);
    } else {
        chars = (char *)((char *)emptyRep + 0x10);
        emptyRep->ref++;
    }
    namePtr->p = chars;
    self->f58 = param5;
    Info *info = self->f4;
    if (!info) {
        self->f50 = 0;
        func_00474ED0(&self->i8);
        func_00474ED0(&self->i2c);
    } else {
        SV *nameView = &info->f20;
        if (nameView->len != 0) {
            const char *literal = nameView->p;
            strobe__Any__setMember(namePtr, 0, (u32)-1, literal, func_0057F260(literal));
            info = self->f4;
        }
        self->f50 = info->f8;
        itemIndex = (Cnt)((s32)itemIndex - info->f2);
        Cnt unusedScratch;
        Vec *items = &info->v18;
        if (items->size != 0) {
            self->i2c = (*items)[mn(itemIndex, items->size - 1)];
        } else {
            func_00474ED0(&self->i2c);
        }
    }
}
