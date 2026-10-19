#include "types.h"

struct Info {
    s32 dim;
    s32 n;
    s8 *cb;
    s32 cnt;
    s32 flag;
};

extern "C" unsigned func_00567B38(void *, int);

extern "C" void func_0056DB78(s32 *out, Info *info, s32 unused, void *rng, u32 scratch) {
    s32 n = info->n;
    u32 e = scratch + ((16 - scratch) & 15) + n * 4;
    s32 dim = info->dim;
    s32 *A = (s32 *)(e - n * 4);
    s32 *B = (s32 *)(e + ((16 - e) & 15));
    s8 *cb = info->cb;
    s32 flag = info->flag;
    s32 i, j;
    for (i = 0; i < n; i++) {
        if (flag) {
            B[i] = func_00567B38(rng, 1);
        } else {
            B[i] = 0;
        }
        A[i] = func_00567B38(rng, info->cnt);
    }
    for (i = 0; i < n; i++) {
        s32 sign = 1;
        if (B[i]) sign = -1;
        if (sign == 1) {
            for (j = 0; j < dim; j++) {
                out[i * dim + j] = cb[A[i] * dim + j] << 9;
            }
        } else {
            for (j = 0; j < dim; j++) {
                out[i * dim + j] = -(cb[A[i] * dim + j] << 9);
            }
        }
    }
}
