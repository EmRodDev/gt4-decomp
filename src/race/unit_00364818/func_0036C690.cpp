/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Gear request handler of the car (the data block at +0x104 has the current gear at 0x520, the same fields func_0036C160 reads; this
 * is inferred from that sharing): returns the gear to engage, or -1 for no change. The byte at +0x526 is a shift delay counter
 * (decremented each call, re-armed to 1 when a request is still held); a request of +1/-1 moves one gear up or down within
 * 1..top gear (top gear read from the limits record at +0x236).
 * This variant also launches from neutral using func_0036BF68 when the throttle value at 0x488 is above zero. */
typedef unsigned char u8;
typedef signed char s8;
struct C { char pad[0x236]; u8 f236; };
struct B { char pad[0x463 - 0]; s8 f463; };
struct O { char pad[0x10]; C *f10; };
extern "C" int func_0036BF68(O *, float) throw();
extern "C" int func_0036C690(O *self) {
    char *data = (char *)self + 0x104;
    C *limits = self->f10;
    int gear = *(u8 *)(data + 0x520);
    if (*(s8 *)(data + 0x462) != 0) return gear != 0 ? 0 : -1;
    if (gear == 0 && *(float *)(data + 0x488) > 0.0f) {
        int launchGear = func_0036BF68(self, *(float *)(data + 0x53C));
        return launchGear == 0 ? 1 : launchGear;
    }
    int delayLeft = *(u8 *)(data + 0x526);
    if (delayLeft != 0) {
        int delayNext = delayLeft + 0xFF;
        *(u8 *)(data + 0x526) = delayNext;
        u8 delayByte = delayNext;
        if (delayByte == 0 && *(s8 *)(data + 0x463) != 0) {
            *(u8 *)(data + 0x526) = 1;
        }
    } else {
        if (*(s8 *)(data + 0x463) > 0 && gear < limits->f236) {
            *(u8 *)(data + 0x526) = 1;
            return gear + 1;
        }
        if ((s8)*(u8 *)(data + 0x463) < 0 && gear >= 2) {
            *(u8 *)(data + 0x526) = 1;
            return gear - 1;
        }
    }
    return -1;
}
