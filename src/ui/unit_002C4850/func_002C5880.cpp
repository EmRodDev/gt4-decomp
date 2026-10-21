/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Draws or updates a widget part when the widget is active (field +8 non-zero): maps the kind arg2 (0,1,2,3 -> 3,7,5,1, otherwise 4) to a mode code and calls func_00247060 on the sub-object at w1C+0xA0 with arg1, the mode, the position offset (fparg0, fparg1 added to the widget's f58/f5C) and its f60/f64 values. 'Draws' is a guess from the offsets and the float pair; the mode codes' meaning is unknown. */
typedef int s32;
typedef float f32;

struct S2C5880 {
    char p0[8];
    s32 w8;
    char p1[0x10];
    void *w1C;
    char p2[0x38];
    f32 f58;
    f32 f5C;
    f32 f60;
    f32 f64;
};

extern "C" void func_00247060(void *arg0, s32 arg1, s32 arg2, f32 f12, f32 f13, f32 f14, f32 f15);

extern "C" void func_002C5880(void *widget, s32 param, s32 kind, f32 offsetX, f32 offsetY) {
    struct S2C5880 *self = (struct S2C5880 *)widget;
    s32 mode;
    char *target;
    if (self->w8 != 0) {
        target = (char *)self->w1C + 0xA0;
        mode = 4;
        switch (kind) {
        case 0:
            mode = 3;
            break;
        case 1:
            mode = 7;
            break;
        case 2:
            mode = 5;
            break;
        case 3:
            mode = 1;
            break;
        }
        func_00247060(target, param, mode, offsetX + self->f58, offsetY + self->f5C, self->f60, self->f64);
    }
}
