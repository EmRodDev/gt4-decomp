typedef void (*F1)(int);
typedef void (*F3)(int,int);
typedef void (*F5)(int,int,int);
typedef void (*F7)(int,int,int,int);
typedef void (*F9)(int,int,int,int,int);
struct A { F1 w0; int w4; F3 w8; int wC; F5 w10; int w14; F7 w18; int w1C; F9 w20; int w24,w28; };
struct G190 {
    int w0;
    char pad4[0x6C - 4];
    int w6C;
    char pad70[0x7C - 0x70];
    int w7C;
    char pad80[0xD0 - 0x80];
    int wD0;
    char padD4[0x124 - 0xD4];
    int w124;
};
extern int D_0064A308;
extern int D_0064A350;
extern int D_0064A354;
extern G190 D_008A0190;
struct Callbacks { F7 w0; char pad4[0x6c-4]; F1 w6C; char pad70[12]; F5 w7C; char pad80[0xd0-0x80]; F9 wD0; char padd4[0x124-0xd4]; F3 w124; };
extern Callbacks D_008A03B8;
extern "C" void func_0050A9C0(int) throw();
extern "C" int func_0050FE80(void);

extern "C" int func_0050B168(A *a, int *out) {
    if (D_0064A308 == 1) {
        *out = -1;
        return -0x13;
    }
    D_0064A350 = a->w28;
    D_0064A354 = 0;
    func_0050A9C0(0);
    D_008A0190.w6C = a->w4;
    D_008A03B8.w6C = a->w0;
    D_008A0190.w124 = a->wC;
    D_008A03B8.w124 = a->w8;
    D_008A0190.w7C = a->w14;
    D_008A03B8.w7C = a->w10;
    D_008A0190.w0 = a->w1C;
    D_008A03B8.w0 = a->w18;
    D_008A03B8.wD0 = a->w20;
    D_008A0190.wD0 = a->w24;
    if (func_0050FE80() != 0) {
        *out = -1;
        return -1;
    }
    D_0064A308 = 1;
    *out = 0;
    return 0;
}
