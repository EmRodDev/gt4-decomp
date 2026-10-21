/* Writes the two bytes at +0x44 (0x18 at index 1, 0 at index 0), then calls func_00370548 with the object, its block at +0x60
 * and the word stored at +0x80. Purpose of the bytes unknown. */
struct func_00370898_arg0 {
    char pad0[0x80];
    int unk80;
};

extern "C" void func_00370548(void *arg0, void *arg1, int arg2);

extern "C" void func_00370898(struct func_00370898_arg0 *self) {
    char *header = (char *)self + 0x44;

    header[1] = 0x18;
    header[0] = 0;
    func_00370548(self, (char *)self + 0x60, self->unk80);
}
