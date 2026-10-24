struct Buf { char data[0x8000]; unsigned int size; char pad[0x40C]; int kind; char rest[0x81C]; };
int func_00538BF8(struct Buf **, int);
int func_00538B08(int *, unsigned long long);
void func_00538C68(void *);

int func_00540FB8(struct Buf **out, int flags, unsigned int size) {
    struct Buf *buf = 0;
    int handle = 0;
    int r;
    if (out == 0)
        return 2;
    *out = 0;
    if (flags != 0)
        return 4;
    if (size == 0)
        return 2;
    r = func_00538BF8(&buf, sizeof(struct Buf));
    if (buf == 0)
        return 100;
    if (r != 0)
        return 100;
    buf->kind = 0x18;
    buf->size = size;
    r = func_00538B08(&handle, buf->size);
    if (buf == 0 || r != 0) {
        func_00538C68(&buf);
        return 100;
    }
    func_00538C68(&handle);
    *out = buf;
    return 0;
}
