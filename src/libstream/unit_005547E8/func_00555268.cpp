/* Leaves a nested interrupt-disabled section:  the outermost
   leave re-enables interrupts if they were enabled when the section was entered. */
typedef int s32;

struct Obj {
    char pad[0x4f0];
    s32 depth;
    s32 enabled;
};

extern "C" void func_00555268(Obj *arg0)
{
    if (--arg0->depth == 0 && arg0->enabled)
        __asm__ volatile("ei");
}
