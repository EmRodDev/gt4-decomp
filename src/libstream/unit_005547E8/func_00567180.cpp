/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x14];
    int active;
    char pad1[0x60 - 0x18];
    void *port;
};

extern "C" {
int func_005657E0(void *, int, int *);
int func_00565C30(void *, int, void *, int, int, int);

void func_00567180(Obj *o, int index)
{
    int slot;
    if (o->active) {
        if (!func_005657E0(o->port, index, &slot))
            func_00565C30(o, slot, 0, 0, 8, 1);
    }
}
}
