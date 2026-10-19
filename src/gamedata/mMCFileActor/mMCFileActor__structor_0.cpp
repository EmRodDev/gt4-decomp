extern "C" void *mFadeActor__structor_0(void *arg0);
extern "C" void *func_00105250(char *arg0);
extern "C" char mMCFileActor__vtable[];

struct mMCFileActorObj {
    char pad0[0x4];
    void *vtable;
    char pad8[0x38];
    char unk40[0x40];
};

extern "C" void *mMCFileActor__structor_0(mMCFileActorObj *arg0)
{
    mFadeActor__structor_0(arg0);
    arg0->vtable = mMCFileActor__vtable;
    return func_00105250(arg0->unk40);
}
