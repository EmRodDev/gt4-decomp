/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned int u32;

struct PacketHeader {
    u16 length;
    u16 type;
};
struct PacketBuffer {
    PacketHeader header;
    u16 data[0x55];
};
struct Packet;
struct PacketEdits;
struct WordListBlock;
struct BitsetBlock;
struct SizedBlock;

extern "C" PacketBuffer func_0055FCB0(const Packet *packet, const PacketEdits *edits);
extern "C" void func_0055F250(PacketBuffer *destination, u32 type, const WordListBlock *words,
                               const BitsetBlock *bits, const SizedBlock *sized);

struct PacketSource {
    virtual ~PacketSource();
    virtual PacketBuffer packet();
};

struct PacketFilter {
    int x0;
    PacketSource *source;
    PacketEdits *edits;
};

extern "C" PacketBuffer func_00560250(PacketFilter *self) {
    PacketBuffer result;
    if (self->source != 0) {
        PacketBuffer packet = self->source->packet();
        if (self->edits == 0) return packet;
        result = func_0055FCB0((const Packet *)&packet, self->edits);
    } else {
        func_0055F250(&result, 0, 0, 0, 0);
    }
    return result;
}
