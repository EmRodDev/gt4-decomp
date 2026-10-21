/* Expat 1.95.7 XML_SetAttlistDeclHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x8C, expat's m_attlistDeclHandler. */
#include "types.h"
struct func_004CF4F8_a0 {
    char pad0[0x8C];
    s32 attlistDeclHandler;
};

extern "C" void func_004CF4F8(struct func_004CF4F8_a0 *parser, s32 handler) {
    parser->attlistDeclHandler = handler;
}
