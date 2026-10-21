/* Expat 1.95.7 XmlPrologStateInit (identified by address with tools/libmatch.py scan expat): starts the prolog state machine: handler (+0) = D_004D7050 (the first prolog state), documentEntity (+0x10) = 1, includeLevel (+0xC) and inEntityValue (+0x14) = 0. */
#include "types.h"

extern char D_004D7050;

struct Obj004D91D8 {
    s32 handler;
    char pad4[0xC - 0x0 - 4];
    s32 includeLevel;
    s32 documentEntity;
    s32 inEntityValue;
};

extern "C" void func_004D91D8(struct Obj004D91D8 *state) {
    state->handler = (s32)&D_004D7050;
    state->documentEntity = 1;
    state->includeLevel = 0;
    state->inEntityValue = 0;
}
