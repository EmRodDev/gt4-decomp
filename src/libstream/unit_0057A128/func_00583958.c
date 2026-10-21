/* compiler: ee-gcc2.9-991111 */
typedef struct Node { char pad[0x10]; int f10; } Node;
extern int D_00657A80;
extern int D_0087585C;
extern int D_00875860;
extern char D_006CE580[];
extern char D_006CE5A0[];
extern char D_006CE5D8[];
extern char D_006CE600[];
extern char D_006CE638[];
void func_00583C88(void);
Node **func_00585248(int *);
int func_00585DE0(Node *);
int func_00586EF0(void);
void func_0058B150(unsigned int *, unsigned int *);
int func_0058B1D8(unsigned int *, int, unsigned int *);
int func_0058B370(int, int, int, unsigned int *);
void func_005B0750(const char *, ...);

int func_00583958(void) {
    unsigned int sp[3];
    int r;
    Node **pp;
    Node *n;
    Node *t;
    if (D_00657A80 == 0) return 0x81058001;
    func_0058B150(sp, 0);
    if (D_0087585C != (int)sp[0]) func_005B0750(D_006CE580);
    r = func_0058B1D8(&sp[1], 1, &sp[2]);
    if (sp[2] == 1 && (int)sp[1] == D_00875860) {
        sp[2] = 0;
    } else if (sp[2] == 0) {
        if (D_00875860 != -1) {
            func_005B0750(D_006CE5A0);
        }
    }
    if (sp[2] != 0) {
        func_005B0750(D_006CE5D8, r);
        return 0x81050010;
    }
    if (D_00875860 != -1) {
        r = func_0058B370(D_00875860, 0, 0, sp);
        if (r != D_00875860) {
            func_005B0750(D_006CE600, r);
            for (;;) ;
        }
        D_00875860 = -1;
    } else {
        func_00583C88();
    }
    func_00586EF0();
    pp = func_00585248(0);
    n = *pp;
    if (n) {
        do {
            r = func_00585DE0(n);
            if (r < 0) {
                func_005B0750(D_006CE638, n->f10, r, n->f10);
                for (;;) ;
            }
            t = *pp;
            n = t;
        } while (t);
    }
    D_0087585C = 0;
    D_00657A80 = 0;
    return 0;
}
