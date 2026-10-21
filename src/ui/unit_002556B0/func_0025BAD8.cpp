/* Packs four floats into locals and passes them by address to func_0025BCF0 together with the geometry sub-object at +0x34.
 * Sibling of func_0025B538, which calls mWidget::setWindowGeometry the same way; this one is probably the matching variant (inferred from the identical shape). */
struct C { char pad[0x34]; int f34; };

extern "C" void func_0025BCF0(C *widget, int *geometry, float *v0, float *v1, float *v2, float *v3);

extern "C" void func_0025BAD8(C *widget, float in0, float in1, float in2, float in3) {
    float value0 = in0;
    float value1 = in1;
    float value2 = in2;
    float value3 = in3;

    func_0025BCF0(widget, &widget->f34, &value0, &value1, &value2, &value3);
}
