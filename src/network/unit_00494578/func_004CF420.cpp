/* Expat 1.95.7 XML_SetCommentHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x4C, expat's m_commentHandler. */
#include "types.h"
struct func_004CF420_a0 {
    char pad0[0x4C];
    s32 commentHandler;
};

extern "C" void func_004CF420(struct func_004CF420_a0 *parser, s32 handler) {
    parser->commentHandler = handler;
}
