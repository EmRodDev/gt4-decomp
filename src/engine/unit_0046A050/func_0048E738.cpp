/* Exact equality test of two 16-float blocks (64 bytes, laid out like a 4x4 matrix; the matrix reading is inferred from the size): returns 1 only when every float of arg0 equals the one of arg1, 0 otherwise. The chain of nested ifs is the compiler-forced shape of a short-circuit compare that reloads b each step. Fields stay unkNN because only their position matters. */
#include "types.h"

struct func_0048E738_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
};
struct func_0048E738_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
};

s32 func_0048E738(struct func_0048E738_arg0 *lhs, struct func_0048E738_arg1 *rhs) {
    s32 equal;
    f32 rhsValue;

    equal = 0;
    rhsValue = rhs->unk0;
    if (lhs->unk0 == rhsValue) {
        rhsValue = rhs->unk4;
        if (lhs->unk4 == rhsValue) {
            rhsValue = rhs->unk8;
            if (lhs->unk8 == rhsValue) {
                rhsValue = rhs->unkC;
                if (lhs->unkC == rhsValue) {
                    rhsValue = rhs->unk10;
                    if (lhs->unk10 == rhsValue) {
                        rhsValue = rhs->unk14;
                        if (lhs->unk14 == rhsValue) {
                            rhsValue = rhs->unk18;
                            if (lhs->unk18 == rhsValue) {
                                rhsValue = rhs->unk1C;
                                if (lhs->unk1C == rhsValue) {
                                    rhsValue = rhs->unk20;
                                    if (lhs->unk20 == rhsValue) {
                                        rhsValue = rhs->unk24;
                                        if (lhs->unk24 == rhsValue) {
                                            rhsValue = rhs->unk28;
                                            if (lhs->unk28 == rhsValue) {
                                                rhsValue = rhs->unk2C;
                                                if (lhs->unk2C == rhsValue) {
                                                    rhsValue = rhs->unk30;
                                                    if (lhs->unk30 == rhsValue) {
                                                        rhsValue = rhs->unk34;
                                                        if (lhs->unk34 == rhsValue) {
                                                            rhsValue = rhs->unk38;
                                                            if (lhs->unk38 == rhsValue) {
                                                                equal = 1;
                                                                rhsValue = rhs->unk3C;
                                                                if (lhs->unk3C != rhsValue) {
                                                                    equal = 0;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return equal;
}
