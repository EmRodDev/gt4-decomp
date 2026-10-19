typedef unsigned char u8;
typedef unsigned int u32;

/* Text renderer state used while printing a formatted message. */
struct TextCursor { const char *font_name; };
struct TextContext {
    char pad0[0x14];
    TextCursor *cursor;   /* 0x14: current font */
    char pad18[0x24 - 0x18];
    float scale_x;        /* 0x24 */
    float scale_y;        /* 0x28 */
    char pad2c[0x44 - 0x2C];
    u32 color;            /* 0x44 */
    char pad48[0x74 - 0x48];
    int escapes_enabled;  /* 0x74: '%' sequences are interpreted */
    char pad78[0x9C - 0x78];
    int char_bytes;       /* 0x9C: byte length of the character being drawn */
    int next_char;        /* 0xA0: the character after it */
};

typedef int (*DrawChar)(int ch, int arg, TextContext *ctx);

extern "C" int func_00493438(const char **p, int *bytes) throw();
extern "C" int func_00493BC0(const char **p, int flag, TextContext *ctx);
extern "C" void func_00490290(TextContext *ctx, const char *font);
extern "C" int func_00490420(TextContext *ctx, const char *font);
extern "C" void func_00491EB0(void);
extern "C" void func_00491F98(void);
extern "C" void func_004924B8(void);
extern "C" char *func_005A5EF4(const char *s, int c);
extern "C" void func_005A6AB0(char *dst, const char *src, int n);

extern u32 D_00624988;
extern const u32 D_006AE738[4];
extern char D_006AE748[];

/* Draws a UTF-8 string through a per-character callback, interpreting the escapes
   %% (a literal percent), %C<rgb> (colour), %B<c..f> (a Gaiji symbol in one of four
   colours) and %F<font name> (font change). Returns the number of bytes consumed. */
extern "C" int func_004940E8(TextContext *ctx, DrawChar draw, int nested, const char *text)
{
    const char *p = text;
    int bytes;
    int next_bytes;
    int c = func_00493438(&p, &bytes);
    int total = bytes;

    while (c != 0) {
        int next = func_00493438(&p, &next_bytes);
        ctx->next_char = next;
        total += next_bytes;
        if (ctx->escapes_enabled == 0) {
            ctx->char_bytes = bytes;
            if (draw(c, 0, ctx) != 0)
                return -1;
        } else if (c != '%') {
        literal:
            ctx->char_bytes = bytes;
            if (draw(c, 0, ctx) != 0)
                return -1;
        } else if (next == c) {
            /* "%%" draws one percent sign */
            next = func_00493438(&p, &next_bytes);
            ctx->next_char = next;
            total += next_bytes;
            goto literal;
        } else {
            c = next;
            switch (c) {
            case 'C':
                if (func_00493BC0(&p, nested, ctx) < 0)
                    return -1;
                goto argument_done;
            case 'B': {
                int sym = func_00493438(&p, &next_bytes);
                int idx = sym - 'c';
                u32 saved_color = ctx->color;
                /* %Bc .. %Bf pick one of four Gaiji colours, anything else is grey;
                   the alpha of the current colour is kept */
                u32 rgb;
                if (idx >= 0) {
                    if (idx < 4)
                        goto valid;
                }
                rgb = 0x646464;
                goto done;
            valid:
                rgb = D_006AE738[idx];
            done:
                rgb |= saved_color & 0xFF000000;
                D_00624988 = rgb;
                func_00491F98();
                float sx = ctx->scale_x;
                const char *font = ctx->cursor->font_name;
                float sy = ctx->scale_y;
                if (nested == 0)
                    func_004924B8();
                func_00490290(ctx, D_006AE748);
                ctx->scale_x = sx;
                ctx->scale_y = sy;
                if (nested == 0)
                    func_00491EB0();
                if (draw(sym, 0, ctx) != 0)
                    return -1;
                if (nested == 0)
                    func_004924B8();
                func_00490290(ctx, font);
                ctx->scale_x = sx;
                ctx->scale_y = sy;
                if (nested == 0)
                    func_00491EB0();
                D_00624988 = saved_color;
                func_00491F98();
            }
            argument_done:
                next = func_00493438(&p, &next_bytes);
                ctx->next_char = next;
                total += next_bytes;
                break;
            case 'F': {
                if (nested == 0)
                    func_004924B8();
                const char *name = p;
                char *end = func_005A5EF4(name, ' ');
                if (end != 0) {
                    char buf[16];
                    int len = end - name;
                    if (len >= 16)
                        len = 15;
                    buf[15] = 0;
                    func_005A6AB0(buf, name, len);
                    func_00490420(ctx, buf);
                    p = end + 1;
                    next = func_00493438(&p, &next_bytes);
                    total += next_bytes;
                } else {
                    func_00490290(ctx, name);
                    next = 0;
                }
                ctx->next_char = next;
                if (nested == 0)
                    func_00491EB0();
                break;
            }
            default:
                next = func_00493438(&p, &next_bytes);
                ctx->next_char = next;
                total += next_bytes;
                if (draw(c, 0, ctx) != 0)
                    return -1;
                break;
            }
        }
        c = next;
        bytes = next_bytes;
    }
    ctx->next_char = 0;
    return total;
}
