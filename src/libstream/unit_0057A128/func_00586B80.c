/* compiler: ee-gcc2.9-991111 */
struct N { char p[8]; struct N *next; struct N *links; char q[6]; unsigned short flags; };
extern struct N *D_00875898;
int func_00586948(struct N *, struct N *);
int func_00586C08(struct N *, struct N *);
/* Preserve the full SDK callee-saved registers. Repeating the first
   attribute is required by this compiler's attribute processing. */
int func_00586B80(struct N *)
    __attribute__((register_precision(s0, 128),
                   register_precision(s1, 128),
                   register_precision(s0, 128)));
int func_00586B80(struct N *arg) {
    struct N *p = D_00875898;
    while (p) {
        if (!(p->flags & 1) && func_00586948(p, arg)) {
            func_00586C08(arg, p);
            arg->links = p->links;
            p->links = arg;
            return 1;
        }
        p = p->next;
    }
    return 0;
}
