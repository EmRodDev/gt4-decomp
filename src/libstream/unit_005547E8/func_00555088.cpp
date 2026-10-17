/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { int a; int b; };
struct Self { char pad[0x4E8]; Pair head; int f4F0; int f4F4; int f4F8; int f4FC; int f500; int f504; int f508; };
extern "C" void func_00555130(Self *, int);
extern "C" int func_00555088(Self *self) {
    int i = 0;
    Pair *h = &self->head;
    h->a = 0;
    h->b = 0;
    self->f508 = -1;
    self->f4F0 = 0;
    self->f4F4 = 0;
    self->f504 = 0;
    do {
        func_00555130(self, i++);
    } while (i < 2);
    self->f500 = self->f4FC = 0;
}
