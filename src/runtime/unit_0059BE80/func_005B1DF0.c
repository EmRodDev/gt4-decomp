/* compiler: ee-gcc2.9-991111 */
/* Unlink a registered group while interrupts are excluded. Returns the old
 * head when removing it, otherwise its predecessor, or null when absent.
 * The caller supplies a valid group; the original always reenables IRQs. */
struct Group { char unknown0[0x14]; struct Group *next; };
struct Pool { char unknown0[0x28]; struct Group *groups; };
extern struct Pool D_00888240;
extern int func_005B72A8(void);
extern int func_005B72F8(void);
struct Group *func_005B1DF0(struct Group *target) {
    struct Group *group;
    func_005B72A8();
    group = D_00888240.groups;
    if (group == target) {
        D_00888240.groups = group->next;
    } else {
        for (; group; group = group->next) {
            if (group->next == target) {
                group->next = target->next;
                break;
            }
        }
    }
    func_005B72F8();
    return group;
}
