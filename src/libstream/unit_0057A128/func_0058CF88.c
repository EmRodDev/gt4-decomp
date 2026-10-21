/* compiler: ee-gcc2.9-991111 */
extern short D_00657AC8;
int func_0058CE48(void);
void func_005ADD50(void *);
int func_0058CF88(void) {
    int status[4];
    int result;
    if (func_0058CE48()) {
        result = D_00657AC8;
    } else {
        func_005ADD50(status);
        result = status[0] >> 21;
        if (((unsigned int)status[0] >> 13 & 7) == 0) result = 540;
    }
    return result;
}
