/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Constructor-shaped (the vtable pointer is set first): activates the object, fills 4 rows of three floats (0, 1, 0), 0x14
 * bytes apart, starting at +0x10, runs func_005792D8 on the tail member and stores the initial value. Meaning of the rows unknown. */
extern char D_00682F98[];
extern "C" int func_005792D8(int *);
struct Obj { void *vtable; int value; int active; int pad; char rows[0x50]; char pad60[8]; int tail[1]; };
static inline void setRow(float *rowPtr, float first, float second) { rowPtr[0] = first; rowPtr[1] = second; rowPtr[2] = first; }
extern "C" void func_005FDE90(Obj *self, int initialValue) {
    self->vtable = D_00682F98;
    float *rowPtr = (float *)self->rows;
    self->active = 1;
    int rowsLeft = 3;
    do {
        rowsLeft -= 1;
        setRow(rowPtr, 0.0f, 1.0f);
        rowPtr = (float *)((char *)rowPtr + 0x14);
    } while (rowsLeft != -1);
    func_005792D8(self->tail);
    self->value = initialValue;
}
