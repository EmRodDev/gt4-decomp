# Library lookups and registration-link arguments

This batch continues after the independently reviewable playback-query
PR 25, without adding changes to its branch. Its contribution boundary is
`a6cb4b6ac330588a1e305f875688329b0e68bcf7`.

## Recovered lookups

`0055F3E8` compares an entry's name with the supplied search name through
`0057F238` (`strcmp`). Equality returns the entry's 32-bit value at `+4`;
a mismatch returns zero. Caller `0055F420` supplies a default search name
when needed and traverses the list until a nonzero result is found. The
entry's strings remain borrowed; this helper does not allocate or copy them.
Its two-argument signature preserves the name argument passed unchanged
in the original call. Both result branches are explicit in the readable
single-exit implementation.

`00556390` returns the service state selected by `D_0064D20C` from the table
at `D_008A1A50`. If that slot is empty, it uses slot zero. An empty fallback
is allocated as a `0x64`-byte object and initialized through `005563F0`,
which publishes the object in slot zero. The getter reloads slot zero after
that call. The selected-index meaning and object fields remain opaque;
there is no new range check or allocation-failure path absent from retail.

The symbol file associates `005C1498` with exception constructor names,
but its actual code takes an allocation size, calls `00575DC8`, retries
through the new-handler path, and throws on unrecoverable failure. This
call is modeled as an allocator based on those instructions, rather than
the ambiguous symbol aliases.

## Registration-link wrapper

The existing `00612480` source omitted both formal parameters. Its tail
callee `0057CA10` stores argument two in the first word of argument one's
record and zeroes the next two words. Caller `0055F6A0` explicitly passes
the embedded record at `self + 8` and the owning control object.

The wrapper now declares and forwards a `RegistrationLink *` and an opaque
owner pointer. The record stays forward-declared because this wrapper does
not access its fields. This corrects the source-level calling contract
without changing any of its five target instructions; it adds no recovered
code bytes and is counted separately from new functions.

## MPEG header parsing

`005638B0` reads the sequence-header fields after start code `0x1B3` in
caller `005637A8`. The first two 12-bit fields are the horizontal and
vertical sizes. It then consumes aspect ratio, frame rate, bitrate, the
marker bit, VBV size and the constrained-parameters flag before testing
the two optional quantizer-matrix flags. Both flag reads and the ignored
constrained-parameters read must occur: omitting the latter shifts all
following bit consumption.

`005639B8` parses the picture header reached from start code `0x100`.
It consumes temporal reference, picture coding type and VBV delay. Types
2 and 3 have forward-vector fields; type 3 also has backward-vector
fields. Extra picture information uses a condition-first loop: read one
flag bit, and only when it is nonzero skip eight data bits. There is no
unconditional skip before the first flag. Both parsers tail-call
`00563A88`, which handles extension/user-data start codes `0x1B5`/`0x1B2`.

The original globals retain their address names. Descriptive locals and
comments explain the fields without introducing speculative public API
names. The C89 source keeps declarations at block entry while assigning
the picture-type address only after the first bit read, preserving its
original lifetime without artificial uses or register constraints.

A temporary host harness compiled the actual two parser sources with
AddressSanitizer and UndefinedBehaviorSanitizer. Its fixed binary fixtures
cover a constrained sequence header with no matrices, a header with both
optional matrices, and I/P/B pictures with extra-information bytes. It
checks dimensions, coding type, matrix-loader calls, exact bit consumption
and forwarding to the common post-header helper. All fixtures passed.

## Deferred initialization and dispatch

The control initializer `0055F6A0` remains five of 37 instructions different
after correcting its embedded record size and pointer types. The remaining
differences concern scheduling the vtable store, parameter stores and packet
address. A no-strict-aliasing check retained the same residual. No forced
uses or artificial temporary buffers were admitted.

`0055DE50` resets 48 voice records but assigns owners, next pointers and IDs
only for IDs 0 through 45. Its next-pointer condition is nevertheless
`id < 47`, so replacing it with a conventional null-terminated 46-node list
would change behavior. The two final records receive state 6. Corrected
partial layouts and constructor models reached 38/72 differing instructions;
that draft remains excluded from `src/`.

`0055ADB8` dispatches through an eight-byte old-GCC member-function-pointer
table and then updates sequence state/time. The corrected source expresses
this as native `void (SequenceState::*)()` dispatch, followed by an unsigned
64-bit-to-float conversion of the continuation-byte value. Early manual
vtable/float-argument models were rejected as semantically incorrect. The
best corrected candidate remains 52/71 different and is also excluded.
