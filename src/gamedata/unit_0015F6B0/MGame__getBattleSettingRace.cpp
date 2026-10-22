/* Script native for MGame.getBattleSettingRace (inferred from the symbol name): builds a 0x18-byte settings record for a race and returns it as a handle.
 * The game state is the object at +0x10 of the context handle (func_0015F3E0). malloc(0x18) provides the record whose six words are copied from
 * state+0x38CB0+0x10FC, +0x1104, +0x1108, the flag (+0x1100 != 0), the word at state+0x3A090, and +0x10E4 (in that order; field meanings unknown).
 * func_00200140(result, record, 1) wraps the record into a handle that is stored into ret with retain-new / release-old. */
#include "types.h"

struct RefCounter;

extern "C" void func_0015F3E0(void *ret, void *ctx);
extern "C" s32 malloc(s32 ret);
extern "C" void func_00200140(void *ret, void *ctx, void *arg2);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_001FFF30(void *ret, int ctx);
extern "C" void func_0015F388(void *ret, int ctx);

struct BS_dst {
    s32 u0;
    s32 u4;
    s32 u8;
    s32 uC;
    s32 u10;
    s32 u14;
};

struct BS_src {
    char pad0[0x10E4];
    s32 u10E4;
    char pad10E8[0x14];
    s32 u10FC;
    s32 u1100;
    s32 u1104;
    s32 u1108;
};

extern "C" void MGame__getBattleSettingRace(s32 *ret, void *ctx) {
    s32 ctxHandle[4];
    s32 resultHandle[4];
    s32 gameState;
    s32 recordMem;
    s32 *resultPtr;
    s32 newVal;
    s32 oldVal;
    func_0015F3E0(ctxHandle, ctx);
    gameState = *(s32 *)((char *)ctxHandle[0] + 0x10);
    recordMem = malloc(0x18);
    resultPtr = resultHandle;
    BS_src *src = (BS_src *)(0x38cb0 + gameState);
    BS_dst *dst = (BS_dst *)recordMem;
    dst->u0 = src->u10FC;
    dst->u4 = src->u1104;
    dst->u8 = src->u1108;
    dst->uC = (src->u1100 != 0);
    dst->u10 = *(s32 *)((char *)gameState + 0x3A090);
    dst->u14 = src->u10E4;
    func_00200140(resultPtr, dst, (void *)1);
    if (ret != resultPtr) {
        newVal = *resultPtr;
        if (newVal != 0) {
            func_003285A8((RefCounter *)newVal);
        }
        oldVal = *ret;
        if (oldVal != 0) {
            func_003285F8((RefCounter *)oldVal);
        }
        *ret = newVal;
    }
    func_001FFF30(resultPtr, 2);
    func_0015F388(ctxHandle, 2);
}
