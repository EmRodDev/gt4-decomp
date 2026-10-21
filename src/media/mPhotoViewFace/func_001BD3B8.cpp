/* Returns the integer at +0xD4 of the object that the field at +0x10 of the face points to (purpose unknown). */
struct UnkStruct1 {
    char pad[0x10];
    void *unk10;
};

struct UnkStruct2 {
    char pad[0xD4];
    int unkD4;
};

int func_001BD3B8(struct UnkStruct1 *self) {
    return ((struct UnkStruct2 *)self->unk10)->unkD4;
}
