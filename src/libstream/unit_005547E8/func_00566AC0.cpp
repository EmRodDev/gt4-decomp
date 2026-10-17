/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Owner;

struct Packet {
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;
};

struct Channel {
    int lock;
    char pad4[0x34 - 4];
    int index;
    char pad38[4];
    int signature;
    char pad40[0x68 - 0x40];
    int enabled;
};

extern "C" {
extern Owner D_0064CD00;
void func_00576788(int *lock);
void func_005767C0(int *lock);
void func_00555AA0(Owner *o, int idx, int enable);
void func_00555C90(Owner *o, int idx, int value, int enable);
void func_00555F68(Owner *o, int idx, int a, int b, int c, int val, int enable);
void func_00555E18(Owner *o, int idx, int a, int b, int val, int enable);

void func_00566AC0(Channel *ch, Packet *pkt)
{
    int *lock = &ch->lock + 1;
    func_00576788(lock);
    int enable = pkt->b3 != 0;
    if (ch->enabled != enable) {
        func_00555AA0(&D_0064CD00, ch->index, ch->enabled = enable);
    }
    if (ch->enabled == 0) {
        func_00555C90(&D_0064CD00, ch->index, pkt->b2 * 2 - 0xFF, 1);
        if (ch->signature == 0x46DC298) {
            int a = pkt->b4;
            a |= pkt->b5 << 8;
            if (a > 0x8000)
                a |= 0xFFFF0000;
            func_00555F68(&D_0064CD00, ch->index, a, pkt->b6, pkt->b6, pkt->b7, 1);
            func_00555E18(&D_0064CD00, ch->index, pkt->b8, pkt->b9, pkt->b10, 1);
        }
    }
    func_005767C0(lock);
}
}
