/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Translates one flag word into another (button mask to hardware mask). */
extern "C" int func_005664B0(int in) {
    int out = 0;
    if (in & 0x10000) out |= 0x4000;
    if (in & 0x20000) out |= 0x8000;
    if (in & 0x40000) out |= 0x2000;
    if (in & 0x80000) out |= 0x1000;
    if (in & 0x400000) out |= 0x400;
    if (in & 0x800000) out |= 0x800;
    if (in & 0x1000000) out |= 0x100;
    if (in & 0x2000000) out |= 0x200;
    if (in & 0x4000000) out |= 0x4000000;
    if (in & 0x8000000) out |= 0x8000000;
    if (in & 0x200000) out |= 0x1;
    if (in & 0x100000) out |= 0x8;
    return out;
}
