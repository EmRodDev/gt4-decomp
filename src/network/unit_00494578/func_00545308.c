/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Refer to the original shared constant pool so this individually matched
 * routine can also take part in the complete link. */
extern const char largeIntSourceFile[] __asm__("D_006C5200");
extern const char primeBitCountAssertion[] __asm__("D_006C5250");
typedef unsigned char u8;
extern u8 D_0064C2A8[];
extern u8 D_0064C1A8[];
extern u8 D_0064C228[];
void func_00544830(int *, int);
int func_005448B8(int *);
void func_00544978(int *, int);
void func_005449C8(int *, int);
void func_00544B38(int *, int *, int *);
void func_00544E20(void *, void *, void *);
int func_00545018(int *, int *);
int func_00545148(int *, int *);
void func_00545208(int *, int);
int func_00545A54(int *);
void func_005A2E98(const char *, int, const char *);
void func_00545308(int *prime, int nBits) {
    int buf[32];
    u8 *tab;
    u8 *p;
    u8 c;
    int found = 1;
    int count = 0;
    do {
        func_00545208(prime, nBits);
        *prime |= 1;
        if (nBits != func_00545A54(prime)) {
            func_005A2E98(largeIntSourceFile, 0x374, primeBitCountAssertion);
        }
        func_00544978(prime, nBits - 2);
        func_00544830(buf, 0xD2);
        count++;
        func_00544B38(buf, prime, buf);
        func_005449C8(prime, 0xD2 - buf[0]);
        if (count & 0x7f) {
            tab = D_0064C2A8;
            p = tab;
            do {
                func_005449C8(prime, *p++);
                found = 0;
                func_00544E20(buf, prime, D_0064C1A8);
                if (func_005448B8(buf) != 0) {
                    func_00544E20(buf, prime, D_0064C228);
                    found = func_005448B8(buf) != 0;
                }
                if (found) {
                    func_00544830(buf, 2);
                    found = func_00545018(prime, buf);
                    if (found) {
                        func_00544830(buf, 3);
                        found = func_00545148(prime, buf);
                        if (found) return;
                    }
                }
                if (*p & 1) {
                    c = *p;
                    p = tab;
                    func_005449C8(prime, c);
                }
                count++;
            } while (count & 0x7f);
        }
    } while (!found);
}
