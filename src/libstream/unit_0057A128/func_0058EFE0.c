/* compiler: ee-gcc2.9-991111 */
typedef struct { int state; int f4; char pad[0xC]; char f14[0x320]; } Ent;
typedef struct { char p0[2]; unsigned char off; unsigned char len; int f4; char pad[0x14]; unsigned char data[1]; } Buf;
extern Ent D_0087FA80[];
int func_0058F0B0(int);
int func_0058F348(int);
Buf *func_0058F408(int);
int func_0058F4D0(void *, void *);
void *func_005A4724(void *, const void *, unsigned);

int func_0058EFE0(int arg0, void *arg1) {
    Buf *b;
    unsigned char len;
    func_0058F0B0(arg0);
    if (D_0087FA80[arg0].f4 == 0 && func_0058F348(arg0) < 0) return -1;
    b = func_0058F408(arg0);
    len = b->len;
    if (len != 0) {
        unsigned char *cp = b->data;
        if (cp != 0) {
            func_005A4724(arg1, (void *)((int)b->off + (int)b + 0x1C), len);
            func_0058F4D0(b->data + b->off, D_0087FA80[arg0].f14);
        }
    }
    if (b->f4 == 0) return -1;
    return b->len;
}
