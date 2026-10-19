typedef struct { char b[64]; } Block64;

struct TargetStruct {
    char pad[0x578];
    Block64 block;
};

extern "C" void func_00451418(struct TargetStruct *arg0, const Block64 *arg1) {
    arg0->block = *arg1;
}
