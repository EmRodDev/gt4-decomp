/* Expat 1.95.7 XML_SetUnparsedEntityDeclHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x64, expat's m_unparsedEntityDeclHandler. */
#include "types.h"
struct func_004CF488_a0 {
    char pad0[0x64];
    s32 unparsedEntityDeclHandler;
};

extern "C" void func_004CF488(struct func_004CF488_a0 *parser, s32 handler) {
    parser->unparsedEntityDeclHandler = handler;
}
