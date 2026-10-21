/* Progress test against the course (names from DynamicsConductor::CurrentTotalTime and GetCourseLength): returns 0, 1 or 2. 0 when the car
 * has no valid state, 1 while a time check passes, and otherwise compares the car's progress counter (+0x4AC) with the limit from
 * virtual slot 0x128, adding one when the course position (+0x4A4) is less than half the course length. 2 means the progress passes
 * the limit. The exact game meaning (probably a lap or finish check) is inferred, not proven. */
#include "types.h"

struct VE343C20 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

extern "C" s32 func_0034C158(s32 x, u32 i);
extern "C" f32 DynamicsConductor__GetCourseLength(void *arg0);
extern "C" u32 DynamicsConductor__CurrentTotalTime(void *arg0);

extern "C" s32 func_00343C20(void *arg0) {
    char *self = (char *)arg0;
    char *carState = self + 0x104;
    char *conductor = *(char **)(self + 4);
    s32 one = 1;
    s32 two = 2;
    s32 answer = 0;

    if (*(u8 *)(carState + 0x4B0) != 0) {
        return answer;
    }
    s32 timeFlag = func_0034C158((s32)conductor, DynamicsConductor__CurrentTotalTime(conductor));
    answer = 1;
    if (timeFlag != 0) {
        return answer;
    }
    VE343C20 *limitSlot = (VE343C20 *)(*(char **)(conductor + 0x10140) + 0x128);
    s32 progressLimit = limitSlot->fn(conductor + limitSlot->delta);
    if (progressLimit == 0) {
        return 0;
    }
    if (*(s16 *)(carState + 0x4AC) < progressLimit) {
        return 0;
    }
    f32 halfCourse = DynamicsConductor__GetCourseLength(conductor) * 0.5f;
    if (*(f32 *)(carState + 0x4A4) < halfCourse) {
        progressLimit += 1;
    }
    s32 verdict = (*(s16 *)(carState + 0x4AC) < progressLimit) ? two : one;
    return verdict;
}
