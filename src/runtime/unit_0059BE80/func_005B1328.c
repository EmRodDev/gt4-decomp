/* compiler: ee-gcc2.9-991111 */
#include "ee_kernel.h"
struct Client { void *packet; int a4; int sema; char padC[8]; int b14; void *gp; int (* volatile end)(void *); void *arg; int b24; };
struct Packet { char pad[28]; struct Client *client; unsigned int cid; int a24; int a28; };
extern void func_005ADCD0(int);
extern void func_005B1298(void *);
void func_005B1328(struct Packet *p) {
    struct Client *c;
    switch (p->cid) {
    case 0x8000000A:
        c = p->client;
        if (c->end) {
            void *old = SetGp(c->gp);
            int (*callback)(void *) = *(int (**)(void *))&c->end;
            callback(c->arg);
            SetGp(old);
        }
        break;
    case 0x80000009:
        c = p->client;
        c->b24 = p->a24;
        c->b14 = p->a28;
        break;
    case 0x8000000B:
    default: break;
    }
    c = p->client;
    if (c->sema >= 0) func_005ADCD0(c->sema);
    func_005B1298(c->packet);
    c->packet = 0;
}
