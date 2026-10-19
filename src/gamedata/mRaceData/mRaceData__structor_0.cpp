struct mRaceDataObj {
    int unk0;
    void *vtable;
    int unk8;
    int unkC;
    char sub[0xB0];
};

extern "C" void *hObject__structor_0(void);
extern "C" void *func_00446F90(void *arg0);
extern "C" char mRaceData__vtable[];

extern "C" void *mRaceData__structor_0(mRaceDataObj *arg0)
{
    hObject__structor_0();
    arg0->vtable = mRaceData__vtable;
    return func_00446F90(arg0->sub);
}
