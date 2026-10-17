/* libio (GNU iostream library, gcc 2000-10-03 snapshot): operator>>(istream&, char*).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct Buf {
    int fd;
    int tie;
    int width;
    char pad0C[4];
    long long flags;
    char pad18[2];
    unsigned char state;
};
struct Stream { struct Buf *buf; };

#define CTYPE_TABLE ((unsigned char *)0x6D0E79)
extern void func_00593020(int tie);
extern int func_00593150(struct Stream *);
extern int func_005941C8(int, char);
extern int _IO_getc(int);

static inline int set_width(struct Buf *b, int nw) {
    int old = b->width;
    b->width = nw;
    return old;
}

struct Stream *func_00591918(struct Stream *is, char *ptr) {
    char *p = ptr;
    int w = set_width(is->buf, 0);
    int ok;
    if (is->buf->state) {
        is->buf->state |= 2;
        ok = 0;
    } else {
        if (is->buf->tie) func_00593020(is->buf->tie);
        ok = ((int)(is->buf->flags & 1) == 0) ? 1 : func_00593150(is);
    }
    if (ok) {
        int fd = is->buf->fd;
        int ch;
        while ((ch = _IO_getc(fd)) != -1) {
            if ((CTYPE_TABLE[ch] & 8) || w == 1) {
                func_005941C8(fd, ch);
                goto done;
            }
            *p++ = ch;
            w--;
        }
        is->buf->state |= 1;
done:
        if (p == ptr) is->buf->state |= 2;
    }
    *p = 0;
    return is;
}
