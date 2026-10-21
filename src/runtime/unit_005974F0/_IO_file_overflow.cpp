/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio overflow: writes one character into a FILE's output buffer, setting up the buffer on first use and flushing when it is full, unbuffered, or a newline on a line-buffered stream (glibc _IO_new_file_overflow). */
struct F {
    int flags; char *read_ptr; char *read_end; char *read_base;
    char *write_base; char *write_ptr; char *write_end; char *buf_base; char *buf_end;
};
extern "C" {
void _IO_doallocbuf(F *);
int _IO_do_write(F *, char *, int) throw();
int *func_005A3130(void);
}
int _IO_file_overflow(F *f, int ch) {
    if (f->flags & 8) {
        f->flags |= 0x20;
        *func_005A3130() = 9;
        return -1;
    }
    if ((f->flags & 0x800) == 0) {
        if (f->write_base == 0) {
            _IO_doallocbuf(f);
            f->read_end = f->read_ptr = f->read_base = f->buf_base;
        }
        if (f->read_ptr == f->buf_end)
            f->read_end = f->read_ptr = f->buf_base;
        f->write_ptr = f->read_ptr;
        f->write_base = f->write_ptr;
        f->write_end = f->buf_end;
        f->read_base = f->read_ptr = f->read_end;
        if (f->flags & 0x202) f->write_end = f->write_ptr;
        f->flags |= 0x800;
    }
    if (ch == -1) return _IO_do_write(f, f->write_base, f->write_ptr - f->write_base);
    if (f->write_ptr == f->buf_end)
        if (_IO_do_write(f, f->write_base, f->write_ptr - f->write_base) == -1) return -1;
    *f->write_ptr++ = ch;
    if ((f->flags & 2) || ((f->flags & 0x200) && ch == '\n'))
        if (_IO_do_write(f, f->write_base, f->write_ptr - f->write_base) == -1) return -1;
    return (unsigned char)ch;
}
