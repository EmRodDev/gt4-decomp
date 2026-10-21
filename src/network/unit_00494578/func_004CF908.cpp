/* Expat 1.95.7 XML_GetCurrentByteCount (identified by address with tools/libmatch.py scan expat): returns eventEndPtr (+0x12C) - eventPtr (+0x128) when both are set, otherwise 0. */
#include "types.h"

struct Obj {
    char pad[0x128];
    s32 eventPtr;
    s32 eventEndPtr;
};

extern "C" s32 func_004CF908(struct Obj *parser) {
    s32 eventEnd = parser->eventEndPtr;
    if (eventEnd != 0) {
        s32 eventStart = parser->eventPtr;
        if (eventStart != 0) {
            return eventEnd - eventStart;
        }
    }
    return 0;
}
