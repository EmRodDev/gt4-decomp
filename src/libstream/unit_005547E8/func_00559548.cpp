/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct QueueLink {
    void *request;
    char unknown04[0x14];
};
struct PoolEntry {
    QueueLink queue[2];
    char unknown30[0x24];
    s32 state;
};
extern char D_00655340[];
extern "C" void func_00576100(void *section);
extern "C" void func_00576140(void *section);
extern "C" void func_0055D688(void *request, s32 flags);
extern "C" PoolEntry *func_00559548(PoolEntry *self) {
    func_00576100(D_00655340);
    for (s32 i = 0; i < 2; ++i) {
        if (self->queue[i].request != 0) {
            func_0055D688(self->queue[i].request, 0);
            self->queue[i].request = 0;
        }
    }
    func_00576140(D_00655340);
    return self;
}
