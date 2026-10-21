/* Writes a race description to a binary stream (inferred from the BinStreamWriter calls): a block with the course code and a name,
 * then one record per car (two names and one byte from a virtual call), an optional extra block when includeExtra is set, and
 * finally per-car detail through func_0033A1B0. What the stream is used for (replay or save data) is unknown. */
#include "types.h"

struct VEnt { s16 off; s16 pad; u32 (*fn)(void *); };
struct Mdl { char *vt; };
struct Item {
    char pad0[0x20];
    char unk20[0x2860];
    Mdl *unk2880;
};
struct List { u32 count; s32 unk4; Item **items; };
struct E { char pad[0x80]; s32 unk80; };
struct D { s32 unk0; E *unk4; };
struct B {
    char pad0[0x60];
    List *unk60;
    s64 unk68;
    void *unk70;
    char pad74[0xC];
    D *unk80;
};
struct C { char pad[0x6C]; B *unk6C; };

extern char D_0069F310[];
extern "C" void func_0045B4D8(void *, void *, void *);
extern "C" void GT4Model__BinStreamWriter__write8u(void *, u32);
extern "C" s64 SPEC_DATABASE__RaceSpec__getCourseCode(void *);
extern "C" s32 func_00447CA0(s64, char *);
extern "C" void func_0045B040(void *, void *);
extern "C" void *func_00445350(void *);
extern "C" s64 func_004454D0(void *);
extern "C" void *func_004541C0(s64);
extern "C" void func_0045AFF0(void *, s32);
extern "C" void func_0033A150(void *, s32) throw();
extern "C" void func_0033A1B0(void *, void *, void *) throw();
extern "C" void func_0045B548(void *, void *);

extern "C" void func_0033A2A0(void *writer, C *session, s32 streamValue, s32 includeExtra) {
    s32 buf0[4];
    char name[0x100];
    u32 i = 0;
    u32 j;
    func_0045B4D8(buf0, writer, D_0069F310);
    GT4Model__BinStreamWriter__write8u(writer, 2);
    B *b = session->unk6C;
    func_00447CA0(SPEC_DATABASE__RaceSpec__getCourseCode(b->unk70), name);
    func_0045B040(writer, name);
    func_00447CA0(b->unk68, name);
    func_0045B040(writer, name);
    u32 n = b->unk60->count;
    GT4Model__BinStreamWriter__write8u(writer, n);
    if (n != 0) {
        do {
            Item *it = b->unk60->items[i];
            i++;
            void *r3 = func_00445350((char *)it + 0x20);
            void *r2 = func_004541C0(func_004454D0((char *)it + 0x20));
            Mdl *m = it->unk2880;
            VEnt *ve = (VEnt *)(*(char **)((char *)m + 8) + 0x38);
            u32 r0 = ve->fn((char *)m + ve->off);
            func_0045B040(writer, r3);
            func_0045B040(writer, r2);
            GT4Model__BinStreamWriter__write8u(writer, r0);
        } while (i < n);
    }
    func_0045AFF0(writer, streamValue);
    if (includeExtra != 0) {
        E *e = session->unk6C->unk80->unk4;
        func_0033A150(writer, e->unk80);
    }
    j = 0;
    if (n != 0) {
        do {
            Item *it = b->unk60->items[j];
            j++;
            func_0033A1B0(writer, it, b);
        } while (j < n);
    }
    func_0045B548(buf0, writer);
}
