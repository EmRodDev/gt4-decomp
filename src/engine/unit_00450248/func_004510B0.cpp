/* Returns the field at +0x7C of a node picked as: the override pointer when set, otherwise the owner's default child; 0 when the
 * owner or the node is missing. What the node is (and the field) is unknown. */
#include "types.h"

struct Leaf {
    char pad[0x7C];
    s32 unk7C;
};

struct Inner {
    char pad[0x28];
    Leaf *unk28;
};

struct Obj {
    Inner *unk0;
    char pad4[0x5BC - 0x4];
    Leaf *unk5BC;
};

extern "C" s32 func_004510B0(Obj *arg0) {
    s32 result;
    Leaf *node;
    Leaf *override;
    Inner *owner;

    owner = arg0->unk0;
    node = 0;
    if (owner != 0) {
        override = arg0->unk5BC;
        if (override != 0) {
            node = override;
        } else {
            node = owner->unk28;
        }
    }
    result = 0;
    if (node != 0) {
        result = node->unk7C;
    }
    return result;
}
