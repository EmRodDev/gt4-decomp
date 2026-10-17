/* compiler: ee-gcc2.96-nsa-g */
struct Block { char data[64]; };
struct State { char pad[0x184]; Block a; Block b; };
extern State *D_0064B70C;
extern "C" void func_00544718(Block *a, Block *b) {
    *a = D_0064B70C->a;
    *b = D_0064B70C->b;
}
