/* Expat 1.95.7 XML_FreeContentModel (identified by address with tools/libmatch.py scan expat): calls the free callback of the parser's memory-handling suite (m_mem.free_fcn at +0x14) on the model. */
#include "types.h"

struct S004CFA28 {
    char pad0[0x14];
    void (*free_fcn)(s32 parser);
};

extern "C" void func_004CFA28(struct S004CFA28 *parser, s32 model) {
    parser->free_fcn(model);
}
