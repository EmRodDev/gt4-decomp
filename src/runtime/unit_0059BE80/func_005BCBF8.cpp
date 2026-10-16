/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): func_005BCBF8? (libgcc2.c).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef int s32;

typedef s32 (*FnPtr)(void);
extern FnPtr get_eh_context;

extern "C" s32 func_005BCBF8(void) {
    return get_eh_context() + 0x4;
}
