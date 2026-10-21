/* Script method incTotalPrizeMoney: when the script passed a positive argument count, adds the integer argument (vtable slot 11, +0x58, an integer getter,
 * inferred from its return type) to the total prize money at +0x48 of the sub-record at +0x348 of the object behind the handle (func_0015F3E0 fills it, func_0015F388 with 2 releases it). */
struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { int unk0; VEntry *vt; };
struct Owner { char pad[0x10]; char *p; };
extern "C" void func_0015F3E0(void *, void *);
extern "C" void func_0015F388(void *, int);
extern "C" void MGame__incTotalPrizeMoney(void *, void *selfRef, int argc, Obj **args) {
    if (argc > 0) {
        Owner *buf[4];
        func_0015F3E0(buf, selfRef);
        char *p = buf[0]->p + 0x348;
        Obj *o = *args;
        VEntry *e = (VEntry *)((char *)o->vt + 0x58);
        *(long *)((char *)p + 0x48) += e->fn((char *)o + e->delta);
        func_0015F388(buf, 2);
    }
}
