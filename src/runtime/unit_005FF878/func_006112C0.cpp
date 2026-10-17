/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ring { char *base; int size; };
extern "C" void *func_005A4724(void *, const void *, unsigned);
/* Copies count bytes from src into the ring at pos, wrapping to the start of the ring. */
extern "C" void func_006112C0(Ring *ring, char *pos, char *src, int count) {
    char *base = ring->base;
    int wrapped = pos - base;
    int first = base + ring->size - pos;
    if (count < first) first = count;
    count -= first;
    int second = wrapped;
    if (count < second) second = count;
    func_005A4724(pos, src, first);
    func_005A4724(base, src + first, second);
}
