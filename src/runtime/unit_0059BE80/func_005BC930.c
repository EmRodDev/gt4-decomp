/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of libgcc.a (libgcc2.c, config/fp-bit.c or frame.c), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef void (*Func)(void);

extern Func get_eh_context;
extern int dwarf_reg_size_table_initialized;

void init_reg_size_table(void);
void func_005BC930(void);
void eh_context_static(void);

void func_005BC930(void)
{
    Func *entry = &get_eh_context;

    if (*entry == func_005BC930)
        *entry = eh_context_static;
    if (dwarf_reg_size_table_initialized == 0)
        init_reg_size_table();
    (*entry)();
}
