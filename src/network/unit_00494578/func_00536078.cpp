/* compiler: ee-gcc2.96-g-as2004g */
typedef unsigned long long Addr __attribute__((aligned(4)));
struct Key { Addr value; } __attribute__((packed));
struct Slot { unsigned char state; char pad1[3]; Addr addr; int port; char timer[8]; unsigned int elapsed; void *callback; };
struct Util { char pad[0x70]; int (*test)(Addr); int (*equal)(Addr, Addr); };
extern Util *D_0064B4B0;
extern Slot D_00868848[];
extern "C" void func_0053A890(void *timer, unsigned int *elapsed);
extern "C" void func_00536078(Key key, int port) {
    Slot *s;
    unsigned int i;
    if (D_0064B4B0->test(key.value) == 0) {
        s = D_00868848;
        i = 0;
        do {
            if (D_0064B4B0->equal(s->addr, key.value) != 0) {
                if (s->state == 2) {
                    if (((port ^ s->port) & 0xFFFF) == 0) {
                        func_0053A890(s->timer, &s->elapsed);
                        s->state = 3;
                        break;
                    }
                }
            }
            i++;
            s++;
        } while (i < 0x100);
    }
}
