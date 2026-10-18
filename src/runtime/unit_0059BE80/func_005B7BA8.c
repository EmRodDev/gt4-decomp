/* compiler: ee-gcc2.9-991111 */
/* Channel 0 timer compare register; shares the register-write helper with
 * the adjacent count and mode setters. */
extern void func_005B7B18(unsigned address, unsigned value);
void func_005B7BA8(unsigned compare) {
    func_005B7B18(0xB0001020, compare);
}
