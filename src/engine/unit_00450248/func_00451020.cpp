/* Returns the field at +0x7C of a node picked as: the override pointer when set, otherwise the owner's default child; 0 when the
 * owner or the node is missing. What the node is (and the field) is unknown. */
#include "types.h"

struct Next {
    char pad[0x7C];
    s32 unk7C;
};

struct Head {
    char pad[0x20];
    Next *unk20;
};

struct Obj {
    Head *unk0;
    char pad4[0x5B4];
    Next *unk5B8;
};

extern "C" s32 func_00451020(Obj *arg0) {
    s32 result;
    Next *node;
    Head *owner;
    Next *override;

    owner = arg0->unk0;
    node = 0;
    if (owner != 0) {
        override = arg0->unk5B8;
        if (override != 0) {
            node = override;
        } else {
            node = owner->unk20;
        }
    }
    result = 0;
    if (node != 0) {
        result = node->unk7C;
    }
    return result;
}
