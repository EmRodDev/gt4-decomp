/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ring { char *base; int size; };
extern "C" void *func_005A4724(void *, const void *, unsigned);
/* Copies count bytes starting at src (inside the ring) to dst, wrapping at the end of the ring. */
extern "C" void func_00612B48(Ring *ring, char *dst, char *src, int count) {
    char *base = ring->base;
    int wrapped = src - base;
    int first = base + ring->size - src;
    if (count < first) first = count;
    count -= first;
    int second = wrapped;
    if (count < second) second = count;
    func_005A4724(dst, src, first);
    func_005A4724(dst + first, base, second);
}
