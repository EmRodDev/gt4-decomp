struct Blob { char d[0xB0]; } __attribute__((packed));
struct Self { char pad[0x1344]; int first; };
/* Assigns a record but keeps the destination's own leading word. */
extern "C" void func_006021C8(Self *self, const Blob *src) {
    volatile int keep = self->first;
    *(Blob *)&self->first = *src;
    self->first = keep;
}
