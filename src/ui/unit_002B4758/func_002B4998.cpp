/* Reads entry `index` (4-byte elements) of the array whose pointer is stored at +0xCC of the sub-record chosen by the selector at +0xE8: records are 0x10 bytes apart, starting at the object itself (inferred from the idx*0x10 addressing).
 * Sibling func_002B49B8 has the identical body; what the records are is unknown. */
struct S {
    char pad0[0xCC];
    int *ptr;
    char pad1[0xE8 - 0xCC - 4];
    unsigned int idx;
};

extern "C" int func_002B4998(S *obj, unsigned int index) {
    S *record = (S *)((char *)obj + obj->idx * 0x10);
    int *array = record->ptr;
    int byteOffset = index * 4;
    char *elemPtr = (char *)array + byteOffset;
    return *(int *)elemPtr;
}
