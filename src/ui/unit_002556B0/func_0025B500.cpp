/* Thin wrapper: calls mWidget::getWindowGeometry with the sub-object at +0x34 and four extra values it passes through.
 * The callee name comes from GT HD; the object is presumably an mWidget or a similar window holder (inferred from that call). */
struct C { char pad[0x34]; int f34; };
extern "C" void mWidget__getWindowGeometry(struct C *, int *, int, int, int, int);

extern "C" void func_0025B500(struct C *obj, int a, int b, int c, int d) {
    mWidget__getWindowGeometry(obj, &obj->f34, a, b, c, d);
}
