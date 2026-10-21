/* compiler: ee-gcc2.9-991111 */
struct Obj { char pad[0x20]; void *value; };
struct Obj *func_0058B208(void);
extern char D_006DDDF0[];
void *func_005861A0(void) {
    struct Obj *o = func_0058B208();
    if (o == 0) return D_006DDDF0;
    return o->value;
}
