/* compiler: ee-gcc2.9-991111 */
extern int D_00655EE8;
extern volatile int D_00655EEC;
extern char D_00657A40[], D_00657500[], D_006570C0[], D_00657090[], D_00655FC0[], D_00655F40[];
int func_00580C28(int code, int *out) {
    int value;
    if (code != 0x8001) {
        if (code != 0x8003) {
            if (code != 0x8002) {
                if (code != 0x8004) {
                    if (code != 0x8011) {
                        value = code == 0x8013 ? (int)D_006570C0 :
                                code == 0x8012 ? (int)D_00657500 :
                                code == 0x8014 ? (int)D_00657A40 : 0;
                    } else {
                        value = D_00655EEC;
                        *out = value;
                        goto done;
                    }
                } else value = (int)D_00657090;
            } else value = (int)D_00655FC0;
        } else value = (int)D_00655F40;
    } else value = D_00655EE8;
    *out = value;
done:
    return 1;
}
