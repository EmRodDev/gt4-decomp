/* Expat 1.95.7 XML_SetXmlDeclHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x94, expat's m_xmlDeclHandler. */
#include "types.h"
struct func_004CF508_a0 {
    char pad0[0x94];
    s32 xmlDeclHandler;
};

extern "C" void func_004CF508(struct func_004CF508_a0 *parser, s32 handler) {
    parser->xmlDeclHandler = handler;
}
