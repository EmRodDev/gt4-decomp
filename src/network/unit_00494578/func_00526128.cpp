/* Fills the 0x64-byte record `out` describing entry `entryIndex` of a device table (inferred from the field copies): clears
 * it, stamps an id from func_00525648(0, 0x64), stores the index at +0x18 and the table entry's halfword at +0x5C, then reads two
 * 8-byte blocks plus their halfwords through func_00523CE0 when the index equals the selected one reported by func_00526040 (also flagging
 * byte +0x1A) or through func_00523C20 otherwise. Returns the first non-zero status. On success the optional hook D_0064B710 is called with the
 * record's tail at +0x1C. What the device is is unknown. */
struct B8 { char c[8]; };
struct Ent { char pad[0x2C]; unsigned short v; char pad2[0x44 - 0x2E]; };
struct Dev { char pad[0x84]; Ent *tab; };

struct Out {
    short id; char pad2[2]; B8 a; B8 b; unsigned short s14; unsigned short s16;
    short s18; char c1a; char pad1b; char pad1c[0x5C - 0x1C]; unsigned short s5c;
};
struct Hook { char pad[0x28]; void (*fn)(int, int, void *); };
extern Hook *D_0064B710;
extern "C" void func_00526040(Dev *, int *, unsigned short *) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_00525648(int, int) throw() __attribute__((const));
extern "C" int func_00523C20(Dev *, int, int, void *, unsigned short *) throw();
extern "C" int func_00523CE0(Dev *, int, void *, unsigned short *) throw();

static inline unsigned short invalid_id() { return 0xFFFE; }

extern "C" int func_00526128(Dev *device, int entryIndexArg, Out *out) {
    struct { B8 m0; char p0[8]; B8 m1; char p1[8]; unsigned short s20, p20; int s24; unsigned short s28, p28, s2c, p2c; } local;
    int entryIndex = entryIndexArg & 0xFFFF;
    int status;
    local.s24 = 0;
    local.s20 = invalid_id();
    func_00526040(device, &local.s24, &local.s20);
    func_005A48D8(out, 0, 0x64);
    out->id = func_00525648(0, 0x64);
    out->s18 = entryIndex;
    out->s5c = device->tab[entryIndex].v;
    if (entryIndex == local.s20) {
        out->c1a = 1;
        status = func_00523CE0(device, 0, &local.m0, &local.s28);
        if (status != 0) return status;
        status = func_00523CE0(device, 1, &local.m1, &local.s2c);
        if (status != 0) return status;
    } else {
        status = func_00523C20(device, entryIndex, 0, &local.m0, &local.s28);
        if (status != 0) return status;
        status = func_00523C20(device, entryIndex, 1, &local.m1, &local.s2c);
        if (status != 0) return status;
    }
    {
        out->a = local.m0;
        out->b = local.m1;
        out->s14 = local.s28;
        out->s16 = local.s2c;
        if (D_0064B710 != 0) D_0064B710->fn(-1, 0, (char *)out + 0x1C);
    }
    return status;
}
