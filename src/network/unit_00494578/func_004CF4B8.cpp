/* Expat 1.95.7 XML_SetNotStandaloneHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x74, expat's m_notStandaloneHandler. */
#include "types.h"
struct func_004CF4B8_a0 {
    char pad0[0x74];
    s32 notStandaloneHandler;
};

extern "C" void func_004CF4B8(struct func_004CF4B8_a0 *parser, s32 handler) {
    parser->notStandaloneHandler = handler;
}
