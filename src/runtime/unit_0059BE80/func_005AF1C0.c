/* compiler: ee-gcc2.9-991111 */
struct Tty {
    volatile int fd;
    volatile int size;
    int pad8;
    volatile int busy;
    char *pbuf;
};
extern struct Tty D_00886410;
extern char D_00886440[];
extern int func_005B72A8(void);
extern int func_005B72F8(void);
extern int func_005B9610(int, signed char);
extern void func_005B9640(int);

int func_005AF1C0(const char *s, int len)
{
    int count = 0;
    int i = 0;
    int ret = -1;
    int intr;
    char *buf;
    char *p;
    if (D_00886410.busy == 0) {
        intr = func_005B72A8();
        D_00886410.busy = 1;
        buf = (char *)((unsigned)D_00886440 | 0x20000000);
        D_00886410.pbuf = buf;
        p = buf + 0xC;
        while (--len != -1) {
            if (*s == 10) {
                *p++ = 13;
                i++;
                if (i >= 0x100)
                    break;
            }
            *p = *s;
            i++;
            s++;
            p++;
            count++;
            if (i >= 0x100)
                break;
        }
        D_00886410.size = i + 0xC;
        *(short *)buf = D_00886410.size;
        if (func_005B9610(D_00886410.fd, buf[7]) < 0) {
            D_00886410.busy = 0;
            if (intr)
                func_005B72F8();
            return -1;
        }
        while (D_00886410.busy != 0)
            func_005B9640(D_00886410.fd);
        if (intr)
            func_005B72F8();
        return count;
    }
    return ret;
}
