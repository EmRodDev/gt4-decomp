/* Expat 1.95.7 XML_SetEndElementHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x40, expat's m_endElementHandler. */
#include "types.h"
struct func_004CF408_a0 {
    char pad0[0x40];
    s32 endElementHandler;
};

extern "C" void func_004CF408(struct func_004CF408_a0 *parser, s32 handler) {
    parser->endElementHandler = handler;
}
