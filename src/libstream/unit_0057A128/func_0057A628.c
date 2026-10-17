/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;

/* Add (target - base) to the unaligned little-endian word at (*image + offset). */
void func_0057A628(u8 **image, int offset, int target, int base)
{
    u8 *p = *image + offset;
    target -= base;
    target += p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
    p[0] = target;
    p[1] = target >> 8;
    p[2] = target >> 16;
    p[3] = target >> 24;
}
