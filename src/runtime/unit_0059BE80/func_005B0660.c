/* compiler: ee-gcc2.9-991111 */
/* vsprintf-style wrapper over the shared formatter (newlib vsprintf.c shape): the sink context
   carries the destination buffer; func_005B0568 stores each produced character. */
typedef char *va_list;

typedef struct Ctx {
    char *buf;
    int pad[3];
} Ctx;

extern int func_005B0568();
extern int func_005AF850(int (*)(), Ctx *, const char *, int, va_list);

int func_005B0660(char *buf, const char *fmt, int x, va_list args) {
    Ctx ctx;
    ctx.buf = buf;
    return func_005AF850(func_005B0568, &ctx, fmt, x, args);
}
