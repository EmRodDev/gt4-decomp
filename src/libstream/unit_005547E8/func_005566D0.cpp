/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Signature {
    char bytes[4];
};

struct Device {
    int mode;
    char pad[0x5C - 4];
    int channel;
    char pad2[0x140 - 0x60];
    char *writePos;
};

extern "C" {
extern char D_00655290[];
extern Signature D_006C8720;
int func_00567018(void *, int, void *, int, int);
void func_00565B88(void *, void (*)(void), Device *);
void func_005568A0(void);

void func_005566D0(Device *d)
{
    char command[16];
    Signature signature = D_006C8720;
    func_00567018(D_00655290, d->channel, &signature, 4, 1);
    command[0] = 'R';
    func_00567018(D_00655290, d->channel, command, 1, 1);
    switch (d->mode) {
    case 0:
        command[0] = 'Y';
        break;
    case 1:
        command[0] = 'Z';
        break;
    }
    func_00567018(D_00655290, d->channel, command, 1, 1);
    command[0] = 'B';
    func_00567018(D_00655290, d->channel, command, 1, 1);
    command[0] = '@';
    func_00567018(D_00655290, d->channel, command, 1, 1);
    d->writePos = (char *)d + 0x128;
    func_00565B88(D_00655290, func_005568A0, d);
}
}
