/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
typedef struct Obj {
    char pad0[0x14];
    int active;
    char pad1[0x60 - 0x18];
    void *port;
} Obj;

int func_005657E0(void *, int, int *);
int func_00565C30(void *, int, void *, int, int, int);

void func_00567230(Obj *o, int index, int value)
{
    int slot;
    if (o->active) {
        if (!func_005657E0(o->port, index, &slot))
            func_00565C30(o, slot, &value, 4, 9, 1);
    }
}
}
