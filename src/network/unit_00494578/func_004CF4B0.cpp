/* Expat 1.95.7 XML_SetEndNamespaceDeclHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x70, expat's m_endNamespaceDeclHandler. */
#include "types.h"
struct func_004CF4B0_a0 {
    char pad0[0x70];
    s32 endNamespaceDeclHandler;
};

extern "C" void func_004CF4B0(struct func_004CF4B0_a0 *parser, s32 handler) {
    parser->endNamespaceDeclHandler = handler;
}
