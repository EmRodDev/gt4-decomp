/* Expat 1.95.7 XML_SetCharacterDataHandler (identified by address with tools/libmatch.py scan expat): stores the callback in the parser field at +0x44, expat's m_characterDataHandler. */
#include "types.h"
struct func_004CF410_a0 {
    char pad0[0x44];
    s32 characterDataHandler;
};

extern "C" void func_004CF410(struct func_004CF410_a0 *parser, s32 handler) {
    parser->characterDataHandler = handler;
}
