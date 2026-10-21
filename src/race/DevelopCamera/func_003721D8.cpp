/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long u64;

extern "C" {
int CameraBase__structor_0(void *);
int func_005792D8(void *);
int func_004009A8(void *);
void func_004006F8(void *);
int func_003FF910(void *);
void *exception__structor_0(int);
int DevelopCamera__virtual_20(void *, int);
void func_00379C08(void *);
void *func_0037BE30(void *);
void func_0037CBB8(void *);
void func_0037D288(void *);
void *func_0037DB50(void *);
void func_0037E360(void *);
void func_0037E430(void *);
void func_00381BF0(void *);
void func_0037FB40(void *);
void func_0037CDF8(void *);
void func_00380DA8(void *);
void func_00382C98(void *);
void func_00383400(void *);
void func_00383C68(void *);
void func_00379CB8(void *, void *);
void func_0037BED8(void *, void *);
void func_00380E40(void *, void *);
void func_0037DBF0(void *, void *);
void func_0037E4D0(void *, void *);
void func_00381C88(void *, void *);
void func_00382D38(void *, void *);
void func_00383498(void *, void *);
void func_00383D00(void *, void *);
}
extern char D_0067A078[];

inline void *operator new(unsigned int, void *p) { return p; }

struct Inner { Inner() {} };
struct Blank { Inner i; char pad[4]; };
struct Window { Blank b[2]; char pad[0x19C - 2 * sizeof(Blank)]; };
struct Windows { Window w[6]; };

struct Mgr {
    char *vt;
    int sub;
    int m8;
    int mC;
    Window windows[6];
    char p9B8[0xACC - 0x9B8];
    int mACC;
    char pAD0[0xB80 - 0xAD0];
    char mB80[0x40];
    char mBC0[0x44];
    char mC04[0x1C];
    u64 mC20;
    int mC28;
    int mC2C;
    int mC30;
};

/* camera table: window i, camera n = type row n / 4, column n % 4 */
inline char *column(Mgr *self, int n) { return (char *)self + 8 + (n % 4) * 4; }
inline int rowOffset(int i, int n) { return i * 0x19C + 0x150 + (n / 4) * 16; }
inline void *&camera(Mgr *self, int i, int n) { return *(void **)(column(self, n) + rowOffset(i, n)); }

#define CREATE(n, size, ctor) \
    { char *c = column(self, n); void **q = (void **)(c + rowOffset(i, n)); \
      void *p = exception__structor_0(size); ctor(p); *q = p; }

extern "C" int func_003721D8(Mgr *self) {
    CameraBase__structor_0(self);
    self->vt = D_0067A078;
    func_005792D8(&self->sub);
    new (self->windows) Windows;
    func_004009A8(self->mB80);
    func_004006F8(self->mBC0);
    func_003FF910(self->mC04);
    self->mC20 &= (0xFFFFFF00FFFFFFFFUL);
    self->mC20 &= 0xFFFF00FFFFFFFFFFUL;
    self->mC28 = 0;
    self->mC2C = 0;
    self->mC30 = 1;
    self->mACC = 0;
    self->m8 = 0;
    self->mC = 0;
    for (int i = 0; i < 6; i++) {
        CREATE(0, 0x2C0, func_00379C08);
        CREATE(1, 0x540, func_0037BE30);
        CREATE(2, 0x1C0, func_0037CBB8);
        CREATE(3, 0x200, func_0037D288);
        CREATE(4, 0x1C0, func_0037DB50);
        CREATE(5, 0x1C0, func_0037E360);
        CREATE(6, 0x5C0, func_0037E430);
        CREATE(7, 0x1C0, func_00381BF0);
        CREATE(8, 0x200, func_0037FB40);
        CREATE(9, 0x300, func_0037CDF8);
        CREATE(10, 0x240, func_00380DA8);
        CREATE(11, 0x300, func_00382C98);
        CREATE(12, 0x340, func_00383400);
        CREATE(13, 0x1C0, func_00383C68);
        camera(self, i, 14) = exception__structor_0(0x14);
        func_00379CB8(camera(self, i, 0), &self->sub);
        func_0037BED8(camera(self, i, 1), &self->sub);
        func_00379CB8(camera(self, i, 9), &self->sub);
        func_00380E40(camera(self, i, 10), &self->sub);
        func_0037DBF0(camera(self, i, 4), &self->sub);
        func_0037DBF0(camera(self, i, 5), &self->sub);
        func_0037E4D0(camera(self, i, 6), &self->sub);
        func_00381C88(camera(self, i, 7), &self->sub);
        func_00382D38(camera(self, i, 11), &self->sub);
        func_00383498(camera(self, i, 12), &self->sub);
        func_00383D00(camera(self, i, 13), &self->sub);
    }
    return DevelopCamera__virtual_20(self, 0);
}
