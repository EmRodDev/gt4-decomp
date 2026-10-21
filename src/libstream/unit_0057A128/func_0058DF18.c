/* compiler: ee-gcc2.9-991111 */
extern int D_00657AF0;
extern int D_00657AF4;
extern int D_00657AF8;
extern int D_0087FA40;
void func_005ADCC0(int);
int func_005ADCE0(int);
int func_005ADCF0(int);

int func_0058DF18(int arg0, int *arg1, int *arg2) {
    int state;
    if (D_00657AF0 == 0) return -1;
    if (func_005ADCF0(D_00657AF8) < 0) state = 1;
    else state = 0;
    if (arg0 == 0 && state != 0) {
        state = 0;
        func_005ADCE0(D_00657AF8);
    }
    state = state == 0;
    if (arg1 != 0) *arg1 = D_00657AF0;
    if (state != 0) {
        D_00657AF0 = 0;
        if (arg2 != 0) *arg2 = D_0087FA40;
        func_005ADCC0(D_00657AF4);
    }
    return state;
}
