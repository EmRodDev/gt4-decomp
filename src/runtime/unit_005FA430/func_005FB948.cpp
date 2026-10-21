/* Accessor: follows the pointer at +0x60 to a record whose +8 holds an array of char pointers, and returns the
 * address 0x1A0 bytes into element [index]. Meaning of the table unknown (field names stay unkNN). */
#include "types.h"

struct Inner {
    char pad[0x8];
    char **unk8;
};

struct Obj {
    char pad[0x60];
    Inner *unk60;
};

extern "C" char *func_005FB948(Obj *self, s32 index) {
    return self->unk60->unk8[index] + 0x1A0;
}
