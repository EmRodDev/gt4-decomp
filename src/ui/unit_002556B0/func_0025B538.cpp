/* Sets a widget window geometry: packs four floats into locals and passes them by address to mWidget::setWindowGeometry with the geometry sub-object at +0x34.
 * The by-address packing is how the original passes the four values. */
struct C { char pad[0x34]; int f34; };

extern "C" void mWidget__setWindowGeometry(C *widget, int *geometry, float *v0, float *v1, float *v2, float *v3);

extern "C" void func_0025B538(C *widget, float in0, float in1, float in2, float in3) {
    float value0 = in0;
    float value1 = in1;
    float value2 = in2;
    float value3 = in3;

    mWidget__setWindowGeometry(widget, &widget->f34, &value0, &value1, &value2, &value3);
}
