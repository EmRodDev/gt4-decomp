/* Builds and sends a small control packet (header word 0x02080016, ids taken from both endpoint structs) for the peer arg1 through the local object arg0. Before it, it looks at the peer's pending queue (func_0052DD60): a pending node whose flags have bit 0x800 is discarded (func_0052D550, peer count decremented), otherwise it returns 0 with nothing sent. The packet is 0xC bytes, or 0x4C bytes when func_005288E8() reports mode 1 (then an extra block from D_0064B710->fn is appended); it is sent as a gather list of the packet plus a 2- or 4-byte trailer built from the flags returned by func_0052AA88. The goto-based layout is forced by the compiler's block ordering. The protocol meaning (looks like an acknowledgement) is a guess from the sequence. */
struct A {
    char p[0x68];
    unsigned short id;
    char p2[2];
    unsigned short count;
};
struct B {
    char p0[0x14];
    char pad14[0x58];
    unsigned short id;
    char p6e[6];
    unsigned short count;
    char p76[0xE];
    int h84;
};
struct Seg {
    void *base;
    int len;
};
struct Gather {
    Seg seg[8];
    int total;
    int count;
};
struct Pkt {
    int w0;
    char b4;
    char b5;
    unsigned short s6;
    unsigned short s8;
    char rest[0x40];
};
struct Ops {
    char pad[0x30];
    void (*fn)(int, int, void *);
};
struct Node {
    int w0;
    char pad[0x10];
    unsigned short flags;
};
extern Ops *D_0064B710;
extern "C" Node *func_0052DD60(void *);
extern "C" void func_0052D550(void *);
extern "C" int func_005288E8(void) throw();
extern "C" void func_0052AA88(A *, B *, unsigned short, int, unsigned char *) throw();
extern "C" int func_0052AB68(A *, void *, Gather *, int, int) throw();

extern "C" int func_0052BDD8(A *self, B *peer) {
    unsigned char trailerFlags[4];
    Gather gather;
    Pkt pkt;
    struct {
        unsigned short flags;
        unsigned short len;
    } trailer;
    int packetLen;
    unsigned short sendFlags;
    Node *pending;
    int result;
    void *peerQueue = (char *)peer + 0x14;

    goto check;
pending:
    if (!(pending->flags & 0x800)) return 0;
    goto discard;
check:
    pending = func_0052DD60(peerQueue);
    if (pending && pending->w0) goto pending;
ready:
    pkt.b4 = 2;
    pkt.w0 = 0x02080016;
    pkt.s6 = peer->id;
    pkt.s8 = self->id;
    pkt.b5 = 0;
    if (func_005288E8() != 1) goto simple;
    packetLen = 0x4C;
    D_0064B710->fn(-1, peer->h84, pkt.rest);
    sendFlags = 0xC000;
    goto send;
discard:
    func_0052D550(peerQueue);
    peer->count = peer->count + 0xFFFF;
    goto ready;
simple:
    packetLen = 0xC;
    sendFlags = 0x4000;
send:
    func_0052AA88(self, peer, sendFlags, packetLen, trailerFlags);
    ((unsigned char *)&trailer.flags)[0] = trailerFlags[0];
    ((unsigned char *)&trailer.flags)[1] = trailerFlags[1];
    trailer.flags &= 0xF800;
    if (trailer.flags & 0x6000) trailer.len = 4;
    else trailer.len = 2;
    gather.count = 0;
    gather.total = 0;
    {
        char *lenField = (char *)&gather.seg[0].len;
        char *baseField = (char *)&gather.seg[0].base;
        *(int *)lenField = packetLen;
        *(void **)baseField = &pkt;
        int c = gather.count + 1;
        gather.total = gather.total + packetLen;
        gather.count = c;
        if (c < 8) {
            int *length = (int *)(lenField + c * 8);
            void **base = (void **)(baseField + c * 8);
            *length = trailer.len;
            *base = trailerFlags;
            gather.total = gather.total + trailer.len;
            gather.count = gather.count + 1;
        }
    }
    result = func_0052AB68(self, peerQueue, &gather, 0x8800, 0);
    if (result != 0) peer->count = peer->count + 0xFFFF;
    return result;
}
