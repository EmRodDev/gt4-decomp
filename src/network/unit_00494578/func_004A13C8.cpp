/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
typedef unsigned long u64;

/* Scratchpad copy of a 64-bit register built from 3-bit fields. */
struct Regs { char pad[0x128]; u64 value; char gap[0xA8]; u64 flag; };

static inline void set_field(Regs *p, u64 field, u64 bits, int shift) {
    p->value = (p->value & ~(bits << shift)) | field;
}

static inline void body(int *arg0, Regs *p, u64 bits, u64 dirty) {
    set_field(p, ((u64)arg0[0] & bits) << 0, bits, 0);
    set_field(p, ((u64)arg0[1] & bits) << 16, bits, 16);
    set_field(p, ((u64)arg0[2] & bits) << 32, bits, 32);
    set_field(p, ((u64)arg0[3] & bits) << 48, bits, 48);
    set_field(p, ((u64)arg0[4] & bits) << 4, bits, 4);
    set_field(p, ((u64)arg0[5] & bits) << 20, bits, 20);
    set_field(p, ((u64)arg0[6] & bits) << 36, bits, 36);
    set_field(p, ((u64)arg0[7] & bits) << 52, bits, 52);
    set_field(p, ((u64)arg0[8] & bits) << 8, bits, 8);
    set_field(p, ((u64)arg0[9] & bits) << 24, bits, 24);
    set_field(p, ((u64)arg0[10] & bits) << 40, bits, 40);
    set_field(p, ((u64)arg0[11] & bits) << 56, bits, 56);
    set_field(p, ((u64)arg0[12] & bits) << 8, bits, 8);
    set_field(p, ((u64)arg0[13] & bits) << 24, bits, 24);
    set_field(p, ((u64)arg0[14] & bits) << 40, bits, 40);
    set_field(p, ((u64)arg0[15] & bits) << 56, bits, 56);
    p->flag |= dirty;
}

extern "C" void func_004A13C8(int *arg0) { body(arg0, (Regs *)spr_base(), 7, 0x200000000ul); }
