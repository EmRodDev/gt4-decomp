/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Port { char pad[0x70]; int count; char tail[0x1bc-0x74]; };
struct State { Port ports[2]; };
extern State *D_0064C3E4;
extern "C" int func_005B72A8(void);
extern "C" int func_0054A370(int n) {
    State *state = D_0064C3E4;
    int enabled = func_005B72A8();
    int result = 0;
    int port = n / 4;
    if (n < 8) {
        Port *entry = (Port *)((char *)state + port * 0x1bc);
        result = n % 4 < entry->count;
    }
    if (enabled) __asm__ volatile("ei");
    return result;
}
