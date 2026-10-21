/* Expat 1.95.7 XML_SetEntityDeclHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x90, expat's m_entityDeclHandler. */
#include "types.h"
struct func_004CF500_a0 {
    char pad0[0x90];
    s32 entityDeclHandler;
};

extern "C" void func_004CF500(struct func_004CF500_a0 *parser, s32 handler) {
    parser->entityDeclHandler = handler;
}
