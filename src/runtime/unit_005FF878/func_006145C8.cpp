/* libio 2.8.0 (gcc 2000-10-03 snapshot): istream default constructor.
 * GPLv2 with the libio special exception; see THIRD_PARTY.md.
 * Real virtual inheritance preserves the original ios-base lifetime. */
#define GT4_LIBIO_ISTREAM_CTOR "func_006145C8"
#include "libio_legacy.h"

istream::istream(): _gcount(0) {}
