struct In {
    char pad[4];
    virtual void v000(void *, int);
    virtual void v001(void *, int);
    virtual void v002(void *, int);
    virtual void v003(void *, int);
    virtual void v004(void *, int);
    virtual void v005(void *, int);
    virtual void v006(void *, int);
    virtual void v007(void *, int);
    virtual void v008(void *, int);
    virtual void v009(void *, int);
};
/* Layout backed by include/gt4/hModuleVariable.h and config/class_layout.json (size 0x1C):
 *   0x00..0x13: hVariable base fields (0x04 vtable)
 *   0x14: target (variable target reference/value)
 *   0x18: module (pointer to module)
 */
struct hModuleVariableLayout {
    char base[0x14];
    void *target;
    In *module;
};

extern "C" void hModuleVariable__assign(hModuleVariableLayout *arg0, int arg1) {
    arg0->module->v009(&arg0->target, arg1);
}

