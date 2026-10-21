/* Advances a two-slot state machine on object o: asks the callback at D_0064B4B0+0x60 (with the handle at o->m80+0x1C) for a count; if it is zero the call returns 0 without change. Otherwise it runs func_0053A860 on three fields (+0x20, +0x28, +0x34) of each of the two entries in o->arr, then depending on func_00520230(o->m0) goes to func_0051DDE8 (state 3) or func_0051DE30 (state 4) and stores that state in o->m8 on success. The error value of the failing call is returned. State meanings are not determined. */
struct V { char pad[0x60]; int (*f60)(void *, int *); };
struct Sub {
    char pad[0x1C];
    void *m1C;
};
struct N {
    char pad[0x20];
};
struct O {
    int m0;
    char pad4[4];
    int m8;
    char padC[0x78 - 0xC];
    N *arr[2];
    Sub *m80;
};
extern "C" V *D_0064B4B0;
extern "C" int func_0051DDE8(Sub *);
extern "C" int func_0051DE30(O *);
extern "C" int func_00520230(int);
extern "C" void func_0053A860(void *);

extern "C" int func_0051D448(O *self) {
    int count = 0;
    int status = D_0064B4B0->f60(self->m80->m1C, &count);
    if (status == 0) {
        unsigned int index = 0;
        if (count != 0) {
            N **entryPtr = &self->arr[0];
            do {
                N *entry = *entryPtr;
                entryPtr++;
                if (entry != 0) {
                    func_0053A860((char *)entry + 0x20);
                    func_0053A860((char *)entry + 0x28);
                    func_0053A860((char *)entry + 0x34);
                }
                index++;
            } while (index < 2);
            if (func_00520230(self->m0) != 0) {
                status = func_0051DDE8(self->m80);
                if (status == 0) {
                    self->m8 = 3;
                    goto z;
                }
            } else {
                status = func_0051DE30(self);
                if (status == 0) {
                    self->m8 = 4;
                    goto z;
                }
            }
        } else {
        z:
            status = 0;
        }
    }
    return status;
}
