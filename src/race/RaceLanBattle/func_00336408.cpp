/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad[0xE470];
    int reserved;
};

extern Obj *D_006201C8;
extern "C" char *func_004601A8(void);

extern "C" char *func_00336408(void) {
    if (D_006201C8->reserved != 0) {
        return func_004601A8();
    }
    return 0;
}
