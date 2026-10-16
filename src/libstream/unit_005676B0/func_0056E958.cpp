extern "C" int func_0056E958(int x) {
    int count = 0;
    if (x == 0) return 0;
    if (x > 0x1000000) { x >>= 10; count = 5; }
    if (x > 0x100000) { x >>= 6; count += 3; }
    if (x > 0x40000) { x >>= 4; count += 2; }
    if (x > 0x8000) { x >>= 2; count++; }
    if (x > 0x4000) { x >>= 2; count++; }
    while (x < 0x1000) { x <<= 2; count--; }
    x = (short)((x * (short)((x * (short)((x * 0x1077 >> 14) - 0x3153) >> 14) + 0x52b5) >> 14) + 0xe32);
    if (count > 0) x <<= count;
    else x >>= -count;
    return (x << 9) >> 16;
}
