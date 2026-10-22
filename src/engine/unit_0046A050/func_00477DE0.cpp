/* Script value addition, lhs += rhs (inferred from the two paths). A value is a type tag plus payload; tags 3 and
 * 4 count as strings (isString tests type - 3 < 2). If either operand is a string, both are copied, converted with
 * the Any toString method, their lengths taken with func_0057F260, the left operand is released and replaced by a
 * new string value (type 3) with room for both lengths from func_00476630, and the two texts are copied one after
 * the other starting at payload + 2 (the payload has a 2-byte header, inferred from the offsets). The temporaries
 * are released at the end. Otherwise both are read as floats with func_00477460 and the sum stored in lhs with
 * func_00476B78. The tag 3 is held in a local declared first, as in the matched source. */
#include "types.h"

struct Val {
    s32 type;
    s32 v;
    bool isString() const { return (u32)(type - 3) < 2; }
};
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476768(Val *, const Val *);
extern "C" const char *strobe__Any__toString(Val *);
extern "C" f32 func_00477460(const Val *);
extern "C" void func_00476B78(Val *, f32);
extern "C" u32 func_0057F260(const char *);
extern "C" s32 func_00476630(u32 len);
extern "C" char *func_005A609C(char *dst, const char *src);

extern "C" void func_00477DE0(Val *lhs, const Val *rhs) {
    if (lhs->isString() || rhs->isString()) {
        Val tempL, tempR;
        s32 type = 3;
        const char *textL, *textR;
        u32 lenL, lenR;
        func_00476768(&tempL, lhs);
        func_00476768(&tempR, rhs);
        textL = strobe__Any__toString(&tempL);
        textR = strobe__Any__toString(&tempR);
        lenL = func_0057F260(textL);
        lenR = func_0057F260(textR);
        func_004768C0(lhs);
        lhs->type = type;
        lhs->v = func_00476630(lenL + lenR);
        func_005A609C((char *)lhs->v + 2, textL);
        func_005A609C((char *)lhs->v + lenL + 2, textR);
        func_004768C0(&tempR);
        func_004768C0(&tempL);
        return;
    }
    func_00476B78(lhs, func_00477460(lhs) + func_00477460(rhs));
}
