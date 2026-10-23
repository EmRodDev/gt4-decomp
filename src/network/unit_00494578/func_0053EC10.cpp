/* Refer to the original shared constant pool so this individually matched
 * routine can also take part in the complete link. */
extern const char deletePortMappingArguments[] __asm__("D_006C4490");
extern const char deletePortMappingAction[] __asm__("D_006C4518");
/* Sends the UPnP 'DeletePortMapping' request to the router (NewRemoteHost empty, NewExternalPort = the object's port field, NewProtocol UDP, built into the request buffer at +0x2A7C of the inner object). Returns 2 for a null object or null arg2, 0xD6DA when a request is already in flight (state field +0x3C non-zero), 0x64 when func_0053EF68 says no, and otherwise starts the request (state 9, arg2 stored in the inner object) and returns the result of func_0053C2F0 (0 on success). The strings make the UPnP use certain; the numeric return codes are not decoded. innerParam (stored at inner +8) has an unknown purpose. */
#include "types.h"
struct Inner { char pad0[8]; s32 unk8; char padC[0x2070 - 0xC]; s32 unk2070; };
struct Obj { char pad0[0x18]; s32 externalPort; char pad1C[0x20]; s32 state; s32 unk40; Inner *unk44; };
extern "C" s32 func_0053A878(void *) throw();
extern "C" s32 func_0053C2F0(Obj *, const char *, void *) throw();
extern "C" s32 func_0053EF68(Obj *);
extern "C" void func_0057DA20(void *, const char *, ...);
static inline void start(Obj *arg0, s32 arg2) {
    arg0->state = 9;
    func_0053A878((char *)arg0->unk44 + 0x10);
    arg0->unk44->unk2070 = arg2;
}
extern "C" s32 func_0053EC10(Obj *gateway, s32 innerParam, s32 completion) {
    s32 status = 0;
    if (gateway == 0) return 2;
    if (gateway->state != 0) return 0xD6DA;
    if (completion == 0) return 2;
    if (func_0053EF68(gateway) != 0) return 0x64;
    if (gateway->unk40 != 0) {
        gateway->unk44->unk8 = innerParam;
        func_0057DA20((char *)gateway->unk44 + 0x2A7C, deletePortMappingArguments, gateway->externalPort);
        status = func_0053C2F0(gateway, deletePortMappingAction, (char *)gateway->unk44 + 0x2A7C);
        if (status != 0) goto done;
        start(gateway, completion);
    } else {
        start(gateway, completion);
    }
done:
    return status;
}
