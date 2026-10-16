/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Wait { Wait *next; int thread; int result; };
struct State { char pad[0x49c]; int active; int result; Wait *head; };
extern State *D_0064C3E4;
extern "C" int func_005ADB90(void);
extern "C" void func_005ADBC0(void);
extern "C" int func_005B72A8(void);
extern "C" int func_0054C240(void) {
    Wait wait;
    State *s = D_0064C3E4;
    int enabled = func_005B72A8();
    int sleeping = 0;
    if (s->active) {
        wait.next = s->head;
        wait.thread = func_005ADB90();
        sleeping = 1;
        s->head = &wait;
    } else {
        wait.result = s->result;
    }
    if (enabled) { __asm__ volatile("ei"); }
    if (sleeping) func_005ADBC0();
    return wait.result;
}
