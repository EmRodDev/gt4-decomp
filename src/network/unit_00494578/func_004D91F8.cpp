/* Expat 1.95.7 XmlPrologStateInitExternalEntity (identified by address with tools/libmatch.py scan expat): resets includeLevel (+0xC) and documentEntity (+0x10) to 0 and sets the state handler (+0) to the external-subset start state D_004D7830. */
#include "types.h"

struct S {
    void *handler;
    char pad[0xC - 0x4];
    s32 includeLevel;
    s32 documentEntity;
};

extern "C" char D_004D7830[];

extern "C" void func_004D91F8(S *state) {
    state->includeLevel = 0;
    state->documentEntity = 0;
    state->handler = D_004D7830;
}
