struct E { int state; char pad[0x1C]; int f20; int f24; int f28; };
struct Table { E entries[64]; };
extern Table D_0086A8D8;
extern "C" int func_0053A7B8(int *);
extern "C" void func_00531738(int *) throw();
extern "C" int func_00537E68(void) {
    int now;
    int off = 0;
    unsigned i = 0;
    func_0053A7B8(&now);
    do {
        E *e = &D_0086A8D8.entries[i];
        if (e->state == 2 && (unsigned)(now - e->f20) >= 0x7531) {
            func_00531738((int *)((char *)D_0086A8D8.entries + off + 0x28));
            func_00531738((int *)((char *)D_0086A8D8.entries + off + 0x24));
            e->state = 0;
        }
        i++;
        off += 0x2C;
    } while (i < 0x40);
    return 0;
}
