#include "types.h"

struct Elem {
    void *p;
    s32 f4;
};

extern "C" void func_003285A8(void *arg0), func_003285F8(void *arg0);
extern "C" void func_0013BD68(void *arg0, s32 arg1);
extern "C" s32 func_0057F238(s32 arg0, s32 arg1);

extern "C" void func_005C9288(Elem *arg0, Elem *arg1, u8 arg2) {
    volatile u8 flag = arg2;
    Elem *cur = arg0;
    Elem *prev = cur - 1;
    while (func_0057F238(arg1->f4, prev->f4) < 0) {
        if (cur != prev) {
            void *a = prev->p;
            if (a != 0) {
                func_003285A8(a);
            }
            void *b = cur->p;
            if (b != 0) {
                func_003285F8(b);
            }
            cur->p = a;
        }
        cur->f4 = prev->f4;
        cur = prev;
        prev = cur - 1;
    }
    if (cur != arg1) {
        void *a = arg1->p;
        if (a != 0) {
            func_003285A8(a);
        }
        void *b = cur->p;
        if (b != 0) {
            func_003285F8(b);
        }
        cur->p = a;
    }
    cur->f4 = arg1->f4;
    func_0013BD68(arg1, 2);
}
