/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Resets a small tracker: f34 = 0, f30 takes the value at data+0x56C, the counters are cleared, and, unless the global D_00623E54 is
 * set, f2C decays toward zero by the amount at data+0x54C (never below zero). Purpose unknown. */
struct Obj {
    char pad0[0x2C];
    float f2C;
    float f30;
    float f34;
    int i38;
    short i3C;
    unsigned char i3E;
    char pad3F[0xA9];
    char *data;
};
extern unsigned char D_00623E54;
extern "C" void func_00464ED8(Obj *obj) {
    char *data = obj->data;
    float speed = *(float *)(data + 0x56C);
    obj->f34 = 0.0f;
    obj->f30 = speed;
    obj->i38 = 0;
    obj->i3E = 0;
    obj->i3C = 0;
    if (D_00623E54 == 0) {
        float current = obj->f2C;
        float floorValue = obj->f34;
        if (floorValue < current) {
            float decayed = current - *(float *)(data + 0x54C);
            obj->f2C = decayed;
            if (decayed < floorValue) obj->f2C = floorValue;
        }
    }
}
