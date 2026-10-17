/* compiler: ee-gcc2.9-991111 */
typedef struct Msg {
    int a;
    int b;
} Msg;
extern int func_005AE0D0(int, Msg *);

int func_005B9610(int a, char b) {
    Msg m;
    m.a = a;
    m.b = b;
    return func_005AE0D0(3, &m);
}
