/* Expat 1.95.7 XML_SetExternalEntityRefHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x78, expat's m_externalEntityRefHandler. */
#include "types.h"
struct func_004CF4C0_a0 {
    char pad0[0x78];
    s32 externalEntityRefHandler;
};

extern "C" void func_004CF4C0(struct func_004CF4C0_a0 *parser, s32 handler) {
    parser->externalEntityRefHandler = handler;
}
