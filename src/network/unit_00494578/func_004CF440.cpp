/* Expat 1.95.7 XML_SetEndCdataSectionHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x54, expat's m_endCdataSectionHandler. */
#include "types.h"
struct func_004CF440_a0 {
    char pad0[0x54];
    s32 endCdataSectionHandler;
};

extern "C" void func_004CF440(struct func_004CF440_a0 *parser, s32 handler) {
    parser->endCdataSectionHandler = handler;
}
