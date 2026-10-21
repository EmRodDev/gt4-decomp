/* compiler: ee-gcc2.9-991111 */
typedef unsigned char u8;
extern int D_00655ED0;
extern int D_00657A78;
extern int D_00657A7C;
extern u8 D_00875858[];
extern unsigned int func_005835B0(int, int, int, int, u8 *);
extern void func_005AED18(int);
extern void func_005B0750(const char *, ...);
extern void func_005B0F78(void *, int);

/* sceCddaStRead */
int func_00583358(unsigned int size, unsigned int *buf, unsigned int mode, unsigned int *err)
{
    unsigned int r, rsize, e, last_err;
    int cur;

    if (D_00655ED0 > 0)
        func_005B0750("sceCddaStRead call read size= %d mode= %d\n", size, mode);
    if (D_00657A7C == 0)
        return 0;
    last_err = 0;
    cur = 0;
    func_005B0F78(buf, size * D_00657A78);
    if (mode != 0) {
        do {
            r = func_005835B0(0, size - cur, (int)buf + cur * D_00657A78, 2, D_00875858);
            rsize = r & 0xFFFF;
            e = r >> 16;
            cur += rsize;
            if (e != 0) {
                last_err = e;
                if (D_00655ED0 > 0)
                    func_005B0750("sceCddaStRead BLK Read cur_size= %d read_size= %d req_size= %d err 0x%x\n",
                                  cur, rsize, size, e);
            } else if (rsize == 0) {
                func_005AED18(600);
            }
        } while (cur != size && (e == 0 || rsize != 0));
        *err = last_err;
    } else {
        r = func_005835B0(0, size, (int)buf, 2, D_00875858);
        e = r >> 16;
        cur = r & 0xFFFF;
        *err = e;
    }
    if (D_00655ED0 > 0)
        func_005B0750("sceCddaStRead Read Ended Read:%d err:%02x\n", cur, e);
    return cur;
}
