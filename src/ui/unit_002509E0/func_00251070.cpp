/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry {
    unsigned short f0;
    char pad2[2];
    unsigned short a;   /* 0x4: read by func_00251038 */
    char pad6[2];
    unsigned short x;   /* 0x8 */
    char padA[2];
    unsigned short y;   /* 0xC */
    char padE[2];
};
struct Obj { char pad[0x4C]; Entry entries[1]; };
extern "C" void func_00251070(Obj *self, int i, unsigned short *x, unsigned short *y) {
    *x = self->entries[i].x;
    *y = self->entries[i].y;
}
