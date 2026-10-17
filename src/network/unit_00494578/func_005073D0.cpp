struct Copy { char data[100]; };
struct Config { int words[5]; };
struct Request { int arg; Config cfg; char data[100]; int value; int status; };
extern int D_00853538;
extern int D_0064A1F8;
extern int D_0064A2D4;
extern int D_0064A248;
extern void (*D_0064A304)();
extern Config D_0064A200;
extern "C" void func_005075C0();
extern "C" int func_0050A958();
extern "C" int func_0050A968();
extern "C" int func_0050B460(int, int, int, Request *);
extern "C" int func_005A6AB0(void *, void *, int) throw();
extern "C" int func_005073D0(Copy input, int a1, int a2, int a3) {
    Request req;
    int r;
    if (D_00853538 == 0 || (r = func_0050A968()) != 1) return -5;
    if (func_0050A958() == 0) return -6;
    int n = D_0064A1F8;
    D_0064A248 = 0;
    D_0064A2D4 = a2;
    D_0064A304 = func_005075C0;
    if (n < 5) {
    if (n > 0) {
    req.arg = a3;
    req.cfg = D_0064A200;
    func_005A6AB0(req.data, &input, 100);
    req.value = a1;
    req.status = r;
    req.data[99] = 0;
    int ret = func_0050B460(1, 0xe4, 0x84, &req);
    return ret == 0 ? 0 : -7;
    }
    }
    return 0;
}
