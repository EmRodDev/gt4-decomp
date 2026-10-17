/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" {
extern char D_00873F00[];
extern char D_00873F40[];
extern char D_00874180[];
extern int D_00654A80;
void *memcpy(void *, const void *, unsigned int);
int func_005616E8(int, int);
int func_005B19B0(void *, int, int, void *, int, void *, int, void *, void *);

int func_005615B0(void)
{
    func_005616E8(0, 0);
    if (func_005B19B0(D_00873F00, 0x11, 0, D_00873F40, 0x240, D_00873F40, 0x240, 0, 0) == 0) {
        memcpy(D_00874180, D_00873F40 + 0x70, 0x160);
        D_00654A80 = 1;
        return *(int *)D_00873F40;
    }
    D_00654A80 = 0;
    return 0x80000000;
}
}
