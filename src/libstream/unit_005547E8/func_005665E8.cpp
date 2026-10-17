/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Translate a pad button bitmask from one bit layout to the other. */
extern "C" unsigned int func_005665E8(unsigned int in)
{
    unsigned int out = 0;
    if (in & 0x10000)    out = 0x4000;
    if (in & 0x20000)    out |= 0x8000;
    if (in & 0x40000)    out |= 0x2000;
    if (in & 0x80000)    out |= 0x1000;
    if (in & 0x800000)   out |= 0x8000000;
    if (in & 0x400000)   out |= 0x4000000;
    if (in & 0x2000000)  out |= 0x200;
    if (in & 0x1000000)  out |= 0x100;
    if (in & 0x200000)   out |= 0x1;
    if (in & 0x100000)   out |= 0x8;
    if (in & 0x8000000)  out |= 0x4;
    if (in & 0x4000000)  out |= 0x2;
    if (in & 0x10000000) out |= 0x20000000;
    if (in & 0x20000000) out |= 0x10000000;
    return out;
}
