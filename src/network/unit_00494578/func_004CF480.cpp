/* Expat 1.95.7 XML_SetEndDoctypeDeclHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x60, expat's m_endDoctypeDeclHandler. */
#include "types.h"
struct func_004CF480_a0 {
    char pad0[0x60];
    s32 endDoctypeDeclHandler;
};

extern "C" void func_004CF480(struct func_004CF480_a0 *parser, s32 handler) {
    parser->endDoctypeDeclHandler = handler;
}
