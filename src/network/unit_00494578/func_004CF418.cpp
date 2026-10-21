/* Expat 1.95.7 XML_SetProcessingInstructionHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x48, expat's m_processingInstructionHandler. */
#include "types.h"
struct func_004CF418_a0 {
    char pad0[0x48];
    s32 processingInstructionHandler;
};

extern "C" void func_004CF418(struct func_004CF418_a0 *parser, s32 handler) {
    parser->processingInstructionHandler = handler;
}
