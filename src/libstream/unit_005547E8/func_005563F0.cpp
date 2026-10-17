/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tracker {
    int state;
    char first[0x2C];
    char second[0x2C];
    int count;
    const void *vtable;
};

extern "C" {
extern char D_00689A10[];
extern Tracker *D_008A1A50;
void *func_005A48D8(void *, int, unsigned int);

void *func_005563F0(Tracker *t)
{
    t->vtable = D_00689A10;
    func_005A48D8(t->first, 0, 0x2C);
    void *r = func_005A48D8(t->second, 0, 0x2C);
    t->count = 0;
    t->state = 0;
    D_008A1A50 = t;
    return r;
}
}
