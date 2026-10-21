/* UPnP request starter: when idle and arguments are valid it sends the 'PortMappingNumberOfEntries' request (func_0053C0E8 with the string at D_006C4330, arg1 as the argument) and, on success, enters state 6, starts the inner object and stores arg2 (completion) and arg1 (number) in it. Returns 2 for null object/arg2, 0xD6DA when busy, 0x64 when func_0053EF68 refuses. Sibling of func_0053E810/func_0053E8D0. */
struct Inner { char pad0[8]; int number; char padC[0x2064-0xC]; int value; };
struct Obj { char pad0[0x3C]; int state; int spare; Inner *inner; };
extern char D_006C4330[];
extern "C" int func_0053A878(char *) throw();
extern "C" int func_0053C0E8(Obj *, int, char *) throw();
extern "C" int func_0053EF68(Obj *);
extern "C" int func_0053E990(Obj *gateway, int number, int completion) {
    if (gateway == 0) return 2;
    if (gateway->state != 0) return 0xD6DA;
    if (completion == 0) return 2;
    if (func_0053EF68(gateway) != 0) return 0x64;
    int status = func_0053C0E8(gateway, number, D_006C4330);
    if (status == 0) {
        gateway->state = 6;
        func_0053A878((char *)gateway->inner + 0x10);
        Inner *inner = gateway->inner;
        inner->value = completion;
        inner->number = number;
    }
    return status;
}
