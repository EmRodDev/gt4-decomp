/* compiler: ee-gcc2.96-no-strict-aliasing */
/**
 * Initializes the mLeaveEvent instance with its module descriptor name
 * and registers its event class ID via mCrossingEvent base setup.
 * String representation is handled using the project reference-counted buffer.
 */
#define GT4_CXX
#include "gt4/hModule.h"
typedef int s32;

struct StringRep {
    s32 length;
    s32 capacity;
    s32 refCount;
    s32 isStatic;
};

struct AllocatorInfo {
    const char *allocatorName;
};

struct StringWrapper {
    char *buffer;
};

struct EventObject {
    char headerPadding[4];
    char *vtablePtr;
};

extern StringRep D_00659FA8;

extern "C" char *func_005C2560(StringRep *rep);
extern "C" s32 func_0057F260(const char *sourceStr);
extern "C" void *func_005C2630(StringWrapper *destWrapper, s32 position, s32 count, const char *sourceStr, s32 sourceLen);
extern "C" struct AllocatorInfo *func_005C11A8(void);
extern "C" void func_00326798(void *memoryPtr, s32 totalSize, s32 alignment, const char *allocatorName);
extern "C" int mCrossingEvent__GetClassID(void);
extern "C" void func_002F3A30(EventObject *eventObj, s32 classId);

extern "C" void func_002AE010(EventObject *eventObj) {
    StringWrapper moduleNameStr;
    StringWrapper *destPtr = &moduleNameStr;
    const char *moduleName = "MUpdateContextPS2";
    StringRep *defaultRep = &D_00659FA8;
    char *dataPtr = (char *)(defaultRep + 1);
    if (defaultRep->isStatic != 0) {
        dataPtr = func_005C2560(defaultRep);
    } else {
        defaultRep->refCount++;
    }
    destPtr->buffer = dataPtr;
    func_005C2630(destPtr, 0, -1, moduleName, func_0057F260(moduleName));
    ((hModule *)(void *)eventObj)->setName(&moduleNameStr);
    {
        StringRep *activeRep = (StringRep *)(moduleNameStr.buffer - 0x10);
        if (--activeRep->refCount == 0) {
            s32 totalCap = activeRep->capacity + 0x10;
            func_00326798(activeRep, totalCap, 4, func_005C11A8()->allocatorName);
        }
    }
    func_002F3A30(eventObj, mCrossingEvent__GetClassID());
}
