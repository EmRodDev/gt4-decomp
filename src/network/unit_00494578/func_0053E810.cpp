/* UPnP request starter for 'GetStatusInfo' (string D_006C4160 sent through func_0053C2F0 with an empty argument string): same guards as its siblings (2 null, 0xD6DA busy, 0x64 refused); on success enters state 4, starts the inner object and stores arg2 (completion) and arg1 (number) in it. Return value is the request result. */
struct Inner { char pad0[8]; int number; char padC[0x205C-0xC]; int value; };
struct Obj { char pad0[0x3C]; int state; int spare; Inner *inner; };
extern char D_006C4160[];
extern char D_006C40D8[];
extern "C" int func_0053A878(char *) throw();
extern "C" int func_0053C2F0(Obj *, char *, char *) throw();
extern "C" int func_0053EF68(Obj *);
extern "C" int func_0053E810(Obj *gateway, int number, int completion) {
 if (gateway == 0) return 2;
 if (gateway->state != 0) return 0xD6DA;
 if (completion == 0) return 2;
 if (func_0053EF68(gateway) != 0) return 0x64;
 int status = func_0053C2F0(gateway, D_006C4160, D_006C40D8);
 if (status == 0) {
  gateway->state = 4;
  func_0053A878((char *)gateway->inner + 0x10);
  Inner *inner = gateway->inner;
  inner->value = completion;
  inner->number = number;
 }
 return status;
}
