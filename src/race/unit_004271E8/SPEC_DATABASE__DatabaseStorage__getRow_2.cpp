typedef int s32;

struct func_00443F00_a0 {
    char pad[0x134];
    s32 items[1];
};

extern "C" s32 func_00449298(s32, s32, s32);

extern "C" s32 func_00443F00(struct func_00443F00_a0 *self, s32 arg1, s32 idx, s32 arg3) {
    s32 p = self->items[idx];
    s32 result = 0;
    if (p == 0) {
        return result;
    }
    return func_00449298(p, arg1, arg3);
}
