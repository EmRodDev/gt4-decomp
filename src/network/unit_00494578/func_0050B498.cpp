/* Submits a request built from `input` to the network layer (inferred from the globals and error codes). Copies the first 0x9C
 * payload bytes and the 0x68-byte tail at +0x9C, sets the fields from +0x104 / +0x10C / +0x110 and, when +0x108 is non-zero, a completion
 * callback (func_0050AEC0, with input->f108 and `callbackArg` given to func_0050AF50). Returns 0 on success; -15 when the state
 * D_0064A308 is not 1; -17 when a request is already pending (D_0064A30C != 0); -2 when func_0052EE68 fails (the code is kept in
 * D_0064A338). Without a callback the new id is kept in D_0064A30C and func_0050E828 runs when D_0064A310 is 1. What the layer is
 * (network/online) is inferred from the unit it sits in. */
struct Input { char data[0x104]; int f104; int f108; int f10c; int f110; };
struct Output { int value; int error; };
struct Request { int f0; int f4; char data[0x9c]; void (*callback)(); char padA8[0xc]; int fB4; int fB8; int fBC; char padC0[0xc]; char tail[0x68]; };
struct Result { int f0; int f4; int value; };
extern int D_0064A308, D_0064A30C, D_0064A338;
extern short D_0064A310;
extern "C" void func_0050AEC0();
extern "C" void func_0050AF50(int, int) throw();
extern "C" void func_0050AF88() throw();
extern "C" void func_0050E828();
extern "C" int func_00533650(Request *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" int func_0052EE68(Request *, Result *);
extern "C" int func_0050B498(Input *input, Output *output, int callbackArg) {
    Request request;
    Result result;
    if (D_0064A308 != 1) { output->value = 0; output->error = -15; return -15; }
    if (D_0064A30C != 0) { output->value = 0; output->error = -17; return -17; }
    func_00533650(&request);
    func_005A4724(request.data, input, 0x9c);
    request.f4 = input->f104;
    if (input->f108) {
        func_0050AF50(input->f108, callbackArg);
        request.callback = func_0050AEC0;
    } else { func_0050AF50(0, 0); }
    request.fB4 = input->f10c;
    request.fBC = input->f110;
    func_005A4724(request.tail, (char *)input + 0x9c, 0x68);
    int status = func_0052EE68(&request, &result);
    if (status) {
        D_0064A338 = status;
        output->value = result.value;
        output->error = -2;
        func_0050AF88();
        return -2;
    }
    if (input->f108 == 0) {
        D_0064A30C = result.value;
        if (D_0064A310 == 1) func_0050E828();
    }
    output->value = result.value;
    output->error = 0;
    return 0;
}
