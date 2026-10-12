struct Obj { char pad[0xB4]; int fieldB4; int fieldB8; volatile int ready; int result; };
extern "C" void func_00578B10(int);
extern "C" int func_0019A648(Obj *self, int a, int b) {
    self->ready = 0;
    self->fieldB4 = a;
    self->fieldB8 = b;
    if (self->ready == 0) {
        do { func_00578B10(0x3E80); } while (self->ready == 0);
    }
    return self->result;
}
