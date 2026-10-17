/* compiler: ee-gcc2.96-no-strict-aliasing */
/* streambuf::setg from libio (gcc 2000-10-03 snapshot): free any backup area, then set the get area. */
struct streambuf {
    int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
};

extern "C" void _IO_free_backup_area(streambuf *);

extern "C" void func_00615530(streambuf *sb, char *eback, char *gptr, char *egptr)
{
    if (sb->_flags & 0x100)
        _IO_free_backup_area(sb);
    sb->_IO_read_base = eback;
    sb->_IO_read_ptr = gptr;
    sb->_IO_read_end = egptr;
}
