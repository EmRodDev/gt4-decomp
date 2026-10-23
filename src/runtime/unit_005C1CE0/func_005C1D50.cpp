#include "types.h"

/* The type_info function of DisplaySwitching (display_switch_ps2.cxx, anonymous namespace), a
 * GranTurismo4::GameObjectPS2 (func_005C1F98). */
extern "C" void *func_005C1F98();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088D950;
extern int D_0088D960;

extern "C" void *func_005C1D50(void) {
    if (D_0088D950 == 0) {
        func_005C1F98();
        func_005BFB68(&D_0088D950, ((char *)"Q239_GLOBAL_$N$display_switch_ps2.cxxoz6Opl16DisplaySwitching"), &D_0088D960);
    }
    return &D_0088D950;
}
