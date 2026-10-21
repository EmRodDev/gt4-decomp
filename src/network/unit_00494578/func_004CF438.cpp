/* Expat 1.95.7 XML_SetStartCdataSectionHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x50, expat's m_startCdataSectionHandler. */
#include "types.h"
struct func_004CF438_a0 {
    char pad0[0x50];
    s32 startCdataSectionHandler;
};

extern "C" void func_004CF438(struct func_004CF438_a0 *parser, s32 handler) {
    parser->startCdataSectionHandler = handler;
}
