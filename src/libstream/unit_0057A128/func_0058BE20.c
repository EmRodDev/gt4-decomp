/* compiler: ee-gcc2.9-991111 */
extern char D_00657A98;
extern char D_00657A9A;
extern int D_00657AA0;
int func_0058BE20(int a) {
    int result;
    if (D_00657A98 == 0) return 1;
    if (D_00657A9A == 1) {
        switch (a) {
        case 0x19: if (D_00657AA0 < 0x9400) return 0; break;
        case 0x1E: if (D_00657AA0 < 0x7C00) return 0; break;
        case 0x32: if (D_00657AA0 < 0x5000) return 0; break;
        case 0x3C: if (D_00657AA0 < 0x4400) return 0; break;
        default: break;
        }
    } else {
        switch (a) {
        case 0x19: if (D_00657AA0 < 0xAC00) return 0; break;
        case 0x1E: if (D_00657AA0 < 0x9000) return 0; break;
        case 0x32: if (D_00657AA0 < 0x5C00) return 0; break;
        case 0x3C: if (D_00657AA0 < 0x5000) return 0; break;
        default: break;
        }
    }
    return 1;
}
