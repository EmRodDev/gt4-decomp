/* compiler: ee-gcc2.9-991111 */
/* Channel 0 timer-mode register in the uncached I/O window. The shared helper
 * performs the register write; the channel-specific wrapper supplies its address. */
extern void func_005B7B18(unsigned address, unsigned value);
void func_005B7B98(unsigned mode) {
    func_005B7B18(0xB0001010, mode);
}
