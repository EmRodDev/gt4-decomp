/* compiler: ee-gcc2.96-no-strict-aliasing */
struct PacketIdBytes { char b[4]; };
union PacketId { int value; PacketIdBytes raw; };
// Provisional packet prefix: the message discriminator is at byte 12.
struct Packet { char pad[12]; int type; };
extern "C" void func_00507AC8(Packet *);
extern "C" void func_00508480(Packet *);
// The callback receives the packet as a 32-bit address. Keeping that ABI
// representation also preserves the compiler scheduling of the header read.
extern "C" void func_00507A68(int, int, int, unsigned packet) {
    // The packed identifier begins at byte 2; preserve its unaligned copy.
    PacketId packetId;
    packetId.value = 0;
    int type = ((Packet *)packet)->type;
    packetId.raw = *(PacketIdBytes *)(packet + 2);
    if (type == 2) func_00507AC8((Packet *)packet);
    else if (type == 6) func_00508480((Packet *)packet);
}
