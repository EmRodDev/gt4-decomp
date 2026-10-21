/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Pushes widget state to a target object through its vtable: first virtual slot +0x198 gets the result of func_002861D8(widget, 0), then, depending on widget->mode (0 or 1), slot +0x260 or +0x268 is called with the widget's block at +0xC4, its iC0 and fBC values and the window width/height. Meaning of modes 0/1 is not determined. */
typedef short s16;
struct VE { s16 delta; s16 index; void (*fn)(void *, void *, int, float *, float); };
struct VE2 { s16 delta; s16 index; void (*fn)(void *, int); };
struct Obj1 { char pad0[4]; char *vtbl; };
struct Obj0 {
    char pad0[0xB8];
    int mode;
    float fBC;
    int iC0;
    char padC4[4];
};
extern "C" float mWidget__getWindowW(void *);
extern "C" float mWidget__getWindowH(void *);
extern "C" int func_002861D8(Obj0 *, int);

extern "C" void func_002E88F8(Obj0 *widget, Obj1 *target) {
    int state = func_002861D8(widget, 0);
    VE2 *setSlot = (VE2 *)(target->vtbl + 0x198);
    setSlot->fn((char *)target + setSlot->delta, state);
    switch (widget->mode) {
    case 0: {
        float windowW = mWidget__getWindowW(widget);
        float windowH = mWidget__getWindowH(widget);
        float windowSize[2];
        windowSize[0] = windowW;
        windowSize[1] = windowH;
        VE *applySlot = (VE *)(target->vtbl + 0x260);
        applySlot->fn((char *)target + applySlot->delta, (char *)widget + 0xC4, widget->iC0, windowSize, widget->fBC);
        break;
    }
    case 1: {
        float windowW = mWidget__getWindowW(widget);
        float windowH = mWidget__getWindowH(widget);
        float windowSize[2];
        windowSize[0] = windowW;
        windowSize[1] = windowH;
        VE *applySlot = (VE *)(target->vtbl + 0x268);
        applySlot->fn((char *)target + applySlot->delta, (char *)widget + 0xC4, widget->iC0, windowSize, widget->fBC);
        break;
    }
    }
}
