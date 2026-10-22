/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the function at 0x005949A8.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct File;
struct VTable { char pad[0x24]; int (*uflow)(File *); };
struct File {
    int flags;
    char *read_ptr, *read_end, *read_base;
    char pad10[0x14];
    char *save_base;
    char pad28[8];
    void *markers;
    char pad34[0x1C];
    VTable *vtable;
};
extern "C" int _IO_switch_to_get_mode(File *) throw();
extern "C" void _IO_switch_to_main_get_area(File *) throw();
extern "C" int func_00594728(File *) throw();
extern "C" void _IO_free_backup_area(File *) throw();
extern "C" int func_005949A8(File *fp) {
    if (fp->flags & 0x800)
        if (_IO_switch_to_get_mode(fp) == -1) return -1;
    if (fp->read_ptr < fp->read_end)
        return *(unsigned char *)fp->read_ptr++;
    if (fp->flags & 0x100) {
        _IO_switch_to_main_get_area(fp);
        if (fp->read_ptr < fp->read_end)
            return *(unsigned char *)fp->read_ptr++;
    }
    if (fp->markers) {
        if (func_00594728(fp)) return -1;
    } else if (fp->save_base)
        _IO_free_backup_area(fp);
    return fp->vtable->uflow(fp);
}
