/* compiler: ee-gcc2.9-991111 */
typedef struct Msg {
    int a;
    int b;
    int c;
} Msg;
extern int func_005AE0D0(int, Msg *);

int func_005B96C0(int a, int b, unsigned short c) {
    Msg m;
    m.a = a;
    m.b = b;
    m.c = c;
    return func_005AE0D0(-5, &m);
}
