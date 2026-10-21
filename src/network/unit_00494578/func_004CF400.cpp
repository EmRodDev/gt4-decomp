/* Expat 1.95.7 XML_SetStartElementHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x3C, expat's m_startElementHandler. */
#include "types.h"
struct func_004CF400_a0 {
    char pad0[0x3C];
    s32 startElementHandler;
};

extern "C" void func_004CF400(struct func_004CF400_a0 *parser, s32 handler) {
    parser->startElementHandler = handler;
}
