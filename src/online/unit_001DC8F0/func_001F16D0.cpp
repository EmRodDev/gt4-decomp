/* Busy-wait helper: derives a token from the value at +0x1B4 through func_001F0D38, then calls mUpdateContext__Sync(1)
 * repeatedly until func_004F1038(D_00645570, token) reports success, and finally returns func_001F1368(ctx). */
extern "C" int func_001F0D38(int k);
extern "C" int func_001F1368(void *ctx);
extern "C" void mUpdateContext__Sync(int n);
extern "C" int func_004F1038(char *d, int value);
extern char D_00645570[];

extern "C" int func_001F16D0(void *ctx)
{
    int token = func_001F0D38(*(int *)((char *)ctx + 0x1B4));
    while (!func_004F1038(D_00645570, token))
        mUpdateContext__Sync(1);
    return func_001F1368(ctx);
}
