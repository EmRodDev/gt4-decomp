/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Script native for MManager.unloadProject (inferred from the symbol name); the parameters are the usual (ret, ctx, argc, args) set under other names.
 * With argc > 0 it builds the manager handle (func_00211460) and wraps args[0] in another handle (func_002292F8); flag is 1 by default and, when argc == 2,
 * it becomes (args[1] via vtable slot 0x58) != 0, so a missing second argument means 'true'. Then func_00219030(manager, argHandle, flag) is called and both handles are destroyed.
 * ret is not written. */
struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { void *f0; char *vtbl; };
extern "C" void func_00211408(void *, int) throw();
extern "C" void func_00211460(void *) throw();
extern "C" void func_00219030(void *, void *, int);
extern "C" void func_002292A0(void *, int);
extern "C" void func_002292F8(void *, void *);

extern "C" void MManager__unloadProject(int unusedRet, int ctx, int argc, Obj *args) {
    void *managerHandle[4];
    char argHandle[16];
    if (argc > 0) {
        func_00211460(managerHandle);
        func_002292F8(argHandle, args);
        int flag = 1;
        if (argc == 2) {
            Obj *flagArg = *(Obj **)((char *)args + 4);
            VEntry *slot58 = (VEntry *)(flagArg->vtbl + 0x58);
            flag = slot58->fn((char *)flagArg + slot58->delta) != 0;
        }
        func_00219030(managerHandle[0], argHandle, flag);
        func_002292A0(argHandle, 2);
        func_00211408(managerHandle, 2);
    }
}
