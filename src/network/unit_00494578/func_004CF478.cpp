/* Expat 1.95.7 XML_SetStartDoctypeDeclHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x5C, expat's m_startDoctypeDeclHandler. */
#include "types.h"
struct func_004CF478_a0 {
    char pad0[0x5C];
    s32 startDoctypeDeclHandler;
};

extern "C" void func_004CF478(struct func_004CF478_a0 *parser, s32 handler) {
    parser->startDoctypeDeclHandler = handler;
}
