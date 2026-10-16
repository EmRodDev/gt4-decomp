/* compiler: ee-gcc2.96-as2004 */
typedef unsigned long long U64 __attribute__((aligned(4)));

/* A peer address, passed by value in one 64-bit register. */
struct NetAddr { U64 raw; };

enum PeerKind { PEER_NONE, PEER_HOST };

/* Internal peer table entry (0x10 bytes). */
struct Peer { enum PeerKind kind; struct NetAddr addr; int port; };

/* One entry of the notification message (0x18 bytes). */
struct PeerInfo { int kind; char text[16]; int port; };

struct Message { int code, status; struct PeerInfo peers[2]; };

struct Saved { struct NetAddr addr; int port; };
struct Owner { char pad[0x100]; struct Saved *saved; };

struct NetOps { char pad[0x7c]; int (*format)(char *buf, struct NetAddr addr); };

void *memcpy(void *, const void *, unsigned int);
extern struct Peer D_00868698[2];
extern struct Message D_008687E0;
extern struct NetOps *D_0064B4B0;
extern void (*D_00868818)(struct Message *);

void func_005367E0(int unused, int reset, struct NetAddr addr, int port, struct Owner *o) {
    struct PeerInfo *dst;
    struct Peer *src;
    unsigned i;

    if (!reset) {
        D_00868698[0].port = port;
        memcpy(&D_00868698[0].addr, &addr, sizeof(addr));
        if (o) {
            struct Saved *s = o->saved;
            if (s) {
                memcpy(&s->addr, &addr, sizeof(addr));
                s->port = port;
            }
        }
    }
    D_008687E0.status = reset ? 37 : 0;
    D_008687E0.code = 1;
    dst = D_008687E0.peers;
    src = D_00868698;
    for (i = 0; i < 2; i++) {
        dst->kind = src->kind;
        dst->port = src->port;
        D_0064B4B0->format(dst->text, src->addr);
        dst++;
        src++;
    }
    D_00868818(&D_008687E0);
}
