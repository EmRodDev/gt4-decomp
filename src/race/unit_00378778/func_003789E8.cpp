/* Prepares the two sub-objects at +0xDD0 and +0xE28: when the flag at +4 of the options is set it first runs func_003717F8 on the
 * second, then func_003FAC90(first, 1) and func_00371800(second, first). The second and third arguments are not used.
 * Sibling of func_00378A40, which calls other helpers. */
struct S003789E8 {
    char pad[4];
    int unk4;
};

extern "C" void func_003717F8(void *arg0);
extern "C" void func_003FAC90(void *arg0, int arg1);
extern "C" void func_00371800(void *arg0, void *arg1);

extern "C" void func_003789E8(void *self, void *unusedArg1, void *unusedArg2, S003789E8 *options) {
    void *firstBlock = (char *) self + 0xDD0;
    void *secondBlock = (char *) self + 0xE28;
    if (options->unk4 != 0) {
        func_003717F8(secondBlock);
    }
    func_003FAC90(firstBlock, 1);
    func_00371800(secondBlock, firstBlock);
}
