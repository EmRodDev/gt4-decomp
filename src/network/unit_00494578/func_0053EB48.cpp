/* Sibling of func_0053EC10: sends the UPnP 'GetSpecificPortMappingEntry' request (empty remote host, the object's external port, protocol UDP) with the same guards (2 for null object/arg2, 0xD6DA when busy, 0x64 when func_0053EF68 refuses). On success it enters state 8, starts the inner object (func_0053A878) and stores arg2 in the inner object at +0x206C; returns the request result. UPnP use is certain from the strings; return codes are not decoded. */
#include "types.h"
struct Inner { char pad0[8]; s32 unk8; char padC[0x206C - 0xC]; s32 unk206C; };
struct Obj { char pad0[0x18]; s32 externalPort; char pad1C[0x20]; s32 state; char pad40[4]; Inner *unk44; };
extern "C" s32 func_0053A878(void *) throw();
extern "C" s32 func_0053C2F0(Obj *, const char *, void *) throw();
extern "C" s32 func_0053EF68(Obj *);
extern "C" void func_0057DA20(void *, const char *, ...);
extern "C" s32 func_0053EB48(Obj *gateway, s32 innerParam, s32 completion) {
    s32 status;
    if (gateway == 0) return 2;
    if (gateway->state != 0) return 0xD6DA;
    if (completion == 0) return 2;
    if (func_0053EF68(gateway) != 0) return 0x64;
    gateway->unk44->unk8 = innerParam;
    func_0057DA20((char *)gateway->unk44 + 0x2A7C, "<NewRemoteHost></NewRemoteHost><NewExternalPort>%d</NewExternalPort><NewProtocol>UDP</NewProtocol>", gateway->externalPort);
    status = func_0053C2F0(gateway, "GetSpecificPortMappingEntry", (char *)gateway->unk44 + 0x2A7C);
    if (status == 0) {
        char *innerStart = (char *)gateway->unk44 + 0x10;
        gateway->state = 8;
        func_0053A878(innerStart);
        gateway->unk44->unk206C = completion;
    }
    return status;
}
