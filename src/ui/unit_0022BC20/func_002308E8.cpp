#include "types.h"
struct Obj {
    char pad0[0x1D08];
    s32 unk1D08;
    void *unk1D0C;
    char pad1[0x28];
    s32 unk1D38;
    s32 unk1D3C;
    s32 unk1D40;
    s32 unk1D44;
};
extern char D_006987A8[];
extern char D_006987B0[];
extern char D_006987B8[];
extern char D_006987C8[];
extern "C" void func_002A39D8(void *, s32 *, s32 *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" s32 func_005CD320(void *, const char *, u32, u32);

static inline bool equal(void *str, const char *s) { return func_005CD320(str, s, 0, func_0057F260(s)) == 0; }

extern "C" void func_002308E8(Obj *self, void *str) {
    s32 w, h;
    if (self->unk1D08 != 0) {
        func_002A39D8(self->unk1D0C, &w, &h);
        s32 x = 0, y = 0;
        if (equal(str, D_006987A8)) {
            x = 0; y = 0;
        } else if (equal(str, D_006987B8)) {
            x = w - 1; y = 0;
        } else if (equal(str, D_006987B0)) {
            x = 0; y = h - 1;
        } else if (equal(str, D_006987C8)) {
            x = w - 1; y = h - 1;
        }
        if (x != self->unk1D38 || y != self->unk1D3C) {
            self->unk1D38 = x;
            self->unk1D3C = y;
            self->unk1D44 = self->unk1D40 ^ 1;
        }
    }
}
