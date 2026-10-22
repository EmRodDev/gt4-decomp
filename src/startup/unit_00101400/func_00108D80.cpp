/* Shared startup strings are declared at their verified original addresses;
 * the standalone function pools do not follow the executable's pool order. */
extern const char localeUs[] __asm__("D_0068BB20");
extern const char localeJp[] __asm__("D_0068CC60");
extern const char localeKr[] __asm__("D_0068CC90");
extern const char localeTw[] __asm__("D_0068CC78");
extern const char localeUk[] __asm__("D_0068CD08");
extern const char krMenuResource[] __asm__("D_0068CCC8");
extern const char krRaceResource[] __asm__("D_0068CCD8");
extern const char twMenuResource[] __asm__("D_0068CCE8");
extern const char twRaceResource[] __asm__("D_0068CCF8");
extern const char jpMenuResource[] __asm__("D_0068CCA8");
extern const char jpRaceResource[] __asm__("D_0068CCB8");
extern const char fepDirectory[] __asm__("D_0068CD18");

#include "types.h"
extern char D_0068CD10[];
extern "C" s32 func_0057F238(const char *, const char *);
extern "C" s32 func_004B3E50(const char *);
extern "C" void func_004B3E90(void);

extern "C" const char *func_00108D80(s32 menu_context) {
    const char *resource_path = 0;
    if (func_0057F238(localeUs, localeJp) != 0) {
        if (func_0057F238(localeUs, localeKr) == 0) {
            if (menu_context != 0) resource_path = krMenuResource; else resource_path = krRaceResource;
        } else if (func_0057F238(localeUs, localeTw) == 0) {
            if (menu_context != 0) resource_path = twMenuResource; else resource_path = twRaceResource;
        } else if (func_0057F238(localeUs, localeUk) == 0 || func_0057F238(localeUs, D_0068CD10) == 0) {
            if (menu_context != 0) resource_path = jpMenuResource; else resource_path = jpRaceResource;
        }
    } else {
        if (menu_context != 0) resource_path = jpMenuResource; else resource_path = jpRaceResource;
    }
    return resource_path;
}

extern "C" void func_00108E88(void) {
    if (func_0057F238(localeUs, localeJp) == 0) func_004B3E50(fepDirectory);
}

extern "C" void func_00108EC8(void) {
    func_004B3E90();
}
