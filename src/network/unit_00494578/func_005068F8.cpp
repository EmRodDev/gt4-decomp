/* compiler: ee-gcc2.96-no-strict-aliasing */
// Sends a request (op 0xe6) through the network layer after storing a callback and a user value;
// returns 0 on success or a negative error code. Purpose of the request is unknown.
// The by-value 100-byte struct argument is copied to the stack by the callee (ldl/ldr loop).
struct Copy { char data[100]; };
struct Request { int arg; char data[100]; int op; int v1; int v2; };
extern int D_00853538;
extern int D_0064A2C4;
extern void (*D_0064A2F4)();
struct Tbl { char pad[0x64]; int a; int b; };
extern Tbl D_0064A178;
extern "C" void func_00506A98();
extern "C" int func_0050A958();
extern "C" int func_0050A968();
extern "C" int func_0050B460(int, int, int, Request *);
extern "C" int func_005A6AB0(void *, void *, int) throw();
extern "C" int func_005068F8(Copy input, int a1, int a2) {
    Request req;
    int status;
    if (D_00853538 == 0 || (status = func_0050A968()) != 1) return -5;
    if (func_0050A958() == 0) return -6;
    D_0064A2C4 = a1;
    D_0064A2F4 = func_00506A98;
    req.arg = a2;
    Request *p = &req;
    func_005A6AB0(p->data, &input, 100);
    const Tbl *t = &D_0064A178;
    p->op = status;
    p->v1 = t->a;
    p->v2 = t->b;
    p->data[99] = 0;
    int r = func_0050B460(1, 0xe6, 0x74, p);
    return r == 0 ? 0 : -7;
}
