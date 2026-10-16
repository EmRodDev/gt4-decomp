/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tag { int a,b,c,d; };
extern "C" void func_004A0F08(int) throw();
extern "C" void func_004A0F38(int) throw();
extern "C" int func_004A0F68(int) throw();
extern "C" void func_004ABA50(int, void *);
extern "C" void func_005ADF20(int);
static inline int physical(int p) {
    int high = p & 0x70000000;
    p &= 0x0FFFFFFF;
    if (high == 0x70000000) p |= 0x80000000;
    return p;
}
extern "C" void func_004A12B8(int channel, int offset, int size, int source) {
    Tag tags[16];
    int address = physical(source);
    int remaining = ((size + 15) >> 4) * 2;
    Tag *tag = tags;
    while (remaining) {
        int n = remaining < 257 ? remaining : 256;
        tag->a = (n >> 1) | 0x30000000;
        tag->b = address & 0x0FFFFFFF;
        tag->c = 0x10000000;
        int command = ((n & 255) << 16) | 0x4A000000;
        command |= offset;
        tag->d = command;
        offset += n;
        remaining -= n;
        address += n * 8;
        ++tag;
    }
    tag->a = 0x70000000;
    tag->b = 0;
    tag->c = 0;
    tag->d = 0;
    __asm__ volatile("sync");
    func_005ADF20(0);
    func_004A0F08(channel);
    func_004ABA50(channel, tags);
    func_004A0F68(channel);
    func_004A0F38(channel);
}
