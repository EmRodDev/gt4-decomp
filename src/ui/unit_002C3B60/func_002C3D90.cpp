/* Calls func_004609F8 on the object's field at +0x14 when that field is non-null (a guarded release/cleanup; what func_004609F8 does is unknown). */
typedef int s32;

struct SomeStruct {
    char pad[0x14];
    s32 unk14;
};

extern void func_004609F8(s32);

extern "C" void func_002C3D90(struct SomeStruct *obj) {
    s32 handle;

    handle = obj->unk14;
    if (handle != 0) {
        func_004609F8(handle);
    }
}
