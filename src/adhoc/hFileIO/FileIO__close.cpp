typedef short s16;
typedef int s32;

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct VObj { s32 m0; VEntry *vtbl; };
struct Guard { VObj *p; s32 pad[3]; };
extern "C" void func_002F67A0(Guard *);
extern "C" void func_002F6748(Guard *, s32);

/* Layout backed by include/gt4/hFileIO.h:
 *   VObj: vtable slot 54 (0x1B0 / 8) is close()
 */
extern "C" void FileIO__close(void) {
    Guard g;
    func_002F67A0(&g);
    {
        VObj *o = g.p;
        VEntry *e = &o->vtbl[54];
        e->fn((char *)o + e->delta);
    }
    func_002F6748(&g, 2);
}
