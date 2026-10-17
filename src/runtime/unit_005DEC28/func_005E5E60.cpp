struct Blob { char d[0xAE]; } __attribute__((packed, aligned(2)));
struct Self { char pad[0x10]; int tag; Blob blob; };
extern "C" void func_005E5E60(Self *self, int tag, const Blob *src) {
    self->tag = tag;
    self->blob = *src;
}
