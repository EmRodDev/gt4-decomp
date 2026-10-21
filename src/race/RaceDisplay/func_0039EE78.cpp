/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Chooses a caption mode (0, 1 or 2) for a display element and swaps its caption when the mode changes. The object number 0 of the owning
 * device (virtual at vtable +0xD0) is queried with an id (the byte at +0x2F when the state at +0x1C is 8 or 9, else 0) through 00372080 and
 * 00373DA0; a nonzero answer gives mode 2, otherwise mode 1 (when the virtual at +0x1B0 is true, +0x20 is not 4 and the context's +0xF0 is zero)
 * or mode 0. On a change from a valid previous mode, resource text 0x1D / 0x1E / 0x1B (modes 0 / 1 / 2) is set through the virtual at +0xA8 and the
 * two RaceMessageDisplay blocks at +0x23DC and +0x291C are cleared. The names are inferred from that behaviour; what each mode shows is purpose unknown. */
typedef int s32;
typedef short s16;

struct VEnt { s16 delta; s16 textIndex; void *fn; };
struct Dev { char pad[0x64]; char *vtbl; };
struct Ctx { char pad0[0x84]; Dev *p84; char pad88[0xF0 - 0x88]; s32 pF0; };
struct Self {
    char *vtbl;
    Ctx *ctx;
    char pad8[0x14];
    s32 i1C;
    s32 i20;
    char pad24[8];
    signed char captionMode;
    char pad2d[2];
    signed char id2F;
    char pad30[0x23DC - 0x30];
    char msg23DC[0x291C - 0x23DC];
    char msg291C[1];
};
struct Obj { char *vtbl; };

extern void **DisplayRText__rtext_ptrs_;
extern "C" void func_00372080(void *, s32);
extern "C" s32 func_00373DA0(void *, s32);
extern "C" void RaceMessageDisplay__clear(void *);

extern "C" void func_0039EE78(Self *self) {
    Dev *device = self->ctx->p84;
    if (device) {
        signed char queryId = 0;
        VEnt *queryEntry = (VEnt *)(device->vtbl + 0xD0);
        Obj *viewObject = ((Obj *(*)(void *, s32))queryEntry->fn)((char *)device + queryEntry->delta, 0);
        s32 stateWord1C = self->i1C;
        if (stateWord1C < 10) {
            if (stateWord1C >= 8) queryId = self->id2F;
        }
        func_00372080(viewObject, queryId);
        s32 queryResult = func_00373DA0(viewObject, queryId);
        signed char newMode = 0;
        if (queryResult != 0) {
            newMode = 2;
        } else {
            VEnt *enabledEntry = (VEnt *)(viewObject->vtbl + 0x1B0);
            if (((s32 (*)(void *))enabledEntry->fn)((char *)viewObject + enabledEntry->delta) != 0 && (self->i20 ^ 4) != 0) {
                newMode = self->ctx->pF0 == 0;
            }
        }
        s32 oldMode = self->captionMode;
        if (oldMode != newMode) {
            self->captionMode = newMode;
            if (oldMode >= 0) {
                s32 textIndex;
                switch (self->captionMode) {
                case 1: textIndex = 0x1E; break;
                case 2: textIndex = 0x1B; break;
                case 0:
                default: textIndex = 0x1D; break;
                }
                VEnt *setTextEntry = (VEnt *)(self->vtbl + 0xA8);
                ((void (*)(void *, void *, s32, s32))setTextEntry->fn)((char *)self + setTextEntry->delta, DisplayRText__rtext_ptrs_[textIndex], 0, 0);
                RaceMessageDisplay__clear(self->msg23DC);
                RaceMessageDisplay__clear(self->msg291C);
            }
        }
    }
}
