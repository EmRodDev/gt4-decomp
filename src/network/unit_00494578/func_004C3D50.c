/* Bytes needed to hold a 16-bit count of bits: ceil(bits / 8). */
int func_004C3D50(int bits)
{
    unsigned int x = (unsigned short)bits;

    if ((x & 7) == 0)
        return x >> 3;
    return (x >> 3) + 1;
}
