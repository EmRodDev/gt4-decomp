/* compiler: ee-gcc2.9-991111 */
struct TopRequest {
    unsigned char mode;
    unsigned char data;
};

struct TopArg {
    int requestOut;
    int requestIn;
    struct TopRequest request[512];
};

extern int D_00885EE0;
extern char D_006D2338[]; /* "## internel error in libkernl.a!\n" */

int func_005ADCE0(int sema);
int func_005ADB50(int thread);
int func_005ADBD0(int thread);
int func_005ADC10(int thread);
void func_005B07D0(const char *fmt, ...);

/* topThread (thread.o): serves the thread requests queued from interrupt handlers. */
void func_005AE9A0(struct TopArg *arg)
{
    int index;

    while (1) {
        func_005ADCE0(D_00885EE0);
        index = arg->requestOut & 0x1FF;
        arg->requestOut = index + 1;
        switch (arg->request[index].mode) {
        case 0:
            func_005ADBD0(arg->request[index].data);
            break;
        case 1:
            func_005ADB50(arg->request[index].data);
            break;
        case 2:
            func_005ADC10(arg->request[index].data);
            break;
        default:
            func_005B07D0(D_006D2338);
            break;
        }
    }
}
