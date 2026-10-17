/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" unsigned int func_00566460(unsigned int in)
{
    unsigned int out = (in & 1) << 26;
    if (in & 2)  out |= 0x8000000;
    if (in & 4)  out |= 0x400;
    if (in & 8)  out |= 0x800;
    if (in & 0x10) out |= 0x100;
    if (in & 0x20) out |= 0x200;
    return out;
}
