/* libio stream wrapper destructor, class identity confirmed by original RTTI.
 * GPLv2 with the libio special exception; see THIRD_PARTY.md. */
// These stream vtables are defined in the original libio implementation unit.
#pragma interface
#define GT4_LIBIO_INLINE_STREAM_DTORS
#include "libio_legacy.h"
// Partial ABI view: the owned stdio buffer retains filebuf alignment;
// its destructor is out of line.
struct __attribute__((aligned(__alignof__(filebuf)))) StdioBuffer {
    char storage[0x60];
    ~StdioBuffer() __asm__("func_0059BB88");
};
struct istdiostream: public istream {
    StdioBuffer buffer;
    virtual ~istdiostream() __asm__("func_00615C88");
};
istdiostream::~istdiostream() {}
