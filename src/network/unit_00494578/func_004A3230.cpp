/* compiler: ee-gcc2.96-nogcse */
#include "spr.h"
typedef unsigned long long u64;
/* Clear the selected buffers after flushing pending graphics state. Bits 0/1
 * select color/depth writes through GS TEST; bit 2 emits a second pass whose
 * buffer identity is still provisional. Scratchpad field names are local to
 * this helper. The TEST value is 64-bit, as consumed by the packet writer. */
struct ClearState {
    char unknown0[0x228];
    int color, secondaryColor;
    float depth;
    char unknown234[8];
    float depthScale;
    char unknown240[0xc];
    char secondaryRectangle[0x14];
    char rectangle[0x14];
};
extern "C" void func_0049FE28();
extern "C" void func_004A3910(ClearState *);
extern "C" void func_004A3308(ClearState *);
extern "C" void func_004A30B0(ClearState *, u64, int, int, const void *);
extern "C" void func_004A3230(int buffers) {
    ClearState *state = (ClearState *)spr_base();
    if (buffers) {
        func_0049FE28();
        if (buffers & 3) {
            u64 test = 0x32001;
            int depth = (int)(state->depth * state->depthScale);
            if (buffers & 1) {
                test = 0;
                if (buffers & 2) test = 0x30000;
            }
            func_004A3910(state);
            func_004A30B0(state, test, state->color, depth, state->rectangle);
        }
        if (buffers & 4) {
            func_004A3308(state);
            func_004A30B0(state, 0, state->secondaryColor, 0, state->secondaryRectangle);
        }
    }
}
