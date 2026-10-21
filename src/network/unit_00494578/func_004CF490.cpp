/* Expat 1.95.7 XML_SetNotationDeclHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x68, expat's m_notationDeclHandler. */
#include "types.h"
struct func_004CF490_a0 {
    char pad0[0x68];
    s32 notationDeclHandler;
};

extern "C" void func_004CF490(struct func_004CF490_a0 *parser, s32 handler) {
    parser->notationDeclHandler = handler;
}
