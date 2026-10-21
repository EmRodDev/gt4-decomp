/* Expat 1.95.7 XML_SetSkippedEntityHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x80, expat's m_skippedEntityHandler. */
#include "types.h"
struct func_004CF4D8_a0 {
    char pad0[0x80];
    s32 skippedEntityHandler;
};

extern "C" void func_004CF4D8(struct func_004CF4D8_a0 *parser, s32 handler) {
    parser->skippedEntityHandler = handler;
}
