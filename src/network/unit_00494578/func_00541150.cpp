/* Setter with error code: returns 2 when the object is missing (the library's 'invalid argument' code, inferred from this being the only failure value), otherwise stores the value at +0x8C18 and returns 0. */
struct S00541150 {
    char pad[0x8C18];
    int unk8C18;
};

extern "C" int func_00541150(S00541150 *self, int value) {
    int status;

    status = 2;
    if (self != 0) {
        self->unk8C18 = value;
        status = 0;
    }
    return status;
}
