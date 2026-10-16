/* Row ids keep their upper 32-bit database tag through the lookup chain. */
extern "C" int func_00448A58(long long rowId, void *buf);

struct Dest {
    long long f0;
    long long f8;
    long long f10;
};

extern "C" int func_00448820(long long rowId, Dest *dest) {
    long long buf[3];
    if (func_00448A58(rowId, buf) != 0) {
        dest->f0 = buf[0];
        dest->f8 = buf[1];
        dest->f10 = buf[2];
        return 1;
    }
    return 0;
}
