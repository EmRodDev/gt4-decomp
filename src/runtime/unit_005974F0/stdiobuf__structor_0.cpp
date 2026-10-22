/* compiler: ee-gcc2.96-no-strict-aliasing */
struct IOFile {
    int flags;
    void *fields[12];
    IOFile *chain;
    int fd;
    char rest[0x14];
} __attribute__((aligned(8)));
struct Fake {
    struct { IOFile file; void *vt; } s;
    void *stdio_file;
};
struct Reent { int x; void *in; void *out; void *err; };
extern Reent *_impure_ptr;
extern IOFile _IO_stderr_;
extern Fake _IO_stdin_buf, _IO_stdout_buf, _IO_stderr_buf;
extern char stdiobuf__vtable[];
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void stdiobuf__structor_0(int init, int prio) {
    Fake a, b, c;
    if (prio == 65535 && init == 1) {
        Fake *dest = &_IO_stdin_buf;
        func_005A48D8(&a.s.file, 0, 0x50);
        a.s.file.flags = (int)0xFBAD208A;
        a.s.file.chain = &_IO_stderr_;
        a.s.vt = stdiobuf__vtable;
        a.stdio_file = _impure_ptr->in;
        *dest = a;
    }
    if (prio == 65535 && init == 1) {
        Fake *dest = &_IO_stdout_buf;
        func_005A48D8(&b.s.file, 0, 0x50);
        b.s.file.flags = (int)0xFBAD2086;
        b.s.file.chain = &_IO_stdin_buf.s.file;
        b.s.file.fd = 1;
        b.s.vt = stdiobuf__vtable;
        b.stdio_file = _impure_ptr->out;
        *dest = b;
    }
    if (prio == 65535 && init == 1) {
        Fake *dest = &_IO_stderr_buf;
        func_005A48D8(&c.s.file, 0, 0x50);
        c.s.file.flags = (int)0xFBAD2086;
        c.s.file.chain = &_IO_stdout_buf.s.file;
        c.s.file.fd = 2;
        c.s.vt = stdiobuf__vtable;
        c.stdio_file = _impure_ptr->err;
        *dest = c;
    }
}
