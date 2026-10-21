/* compiler: ee-gcc2.9-991111 */
struct State { char pad[16]; int library; };
extern struct State D_0087E1C0;
int func_00589BF8(int choice) {
    if (choice < 3) {
        if (choice >= 0) {
            struct State *s = &D_0087E1C0;
            int old = s->library;
            s->library = choice;
            return old;
        }
    }
    return 0x81050016;
}
