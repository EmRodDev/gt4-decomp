/* Expat 1.95.7 XML_MemMalloc (identified by address with tools/libmatch.py scan expat): calls the malloc callback of the parser's memory-handling suite (m_mem.malloc_fcn at +0xC) with the size. */
#include "types.h"

typedef void (*FnPtr)(s32 parser);

struct Obj {
    char pad0[0xC];
    FnPtr malloc_fcn;
};

extern "C" void func_004CFA48(struct Obj *parser, s32 size) {
    parser->malloc_fcn(size);
}
