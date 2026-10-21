/* compiler: ee-gcc2.9-991111 */
extern int func_005AE100(void);
extern int func_005AE110(void);
extern long long func_005B9AF0(void);
long long func_005B9AB0(void) {
    if (func_005AE100() == 0x02000000) {
        return func_005B9AF0();
    } else {
        return func_005AE110();
    }
}
