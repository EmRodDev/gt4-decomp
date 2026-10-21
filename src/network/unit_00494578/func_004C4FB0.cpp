extern "C" int func_004C4CB8(unsigned short c) throw() __attribute__((const));
extern "C" int func_004C4F38(unsigned short c) throw();

extern "C" int func_004C4FB0(unsigned short *s) {
    int n = 0;
    for (;;) {
        if ((*s == 0) || ((func_004C4F38(*s) != 0) || (func_004C4CB8(*s++) >= 0))) {
            return n;
        }
        n++;
    }
}
