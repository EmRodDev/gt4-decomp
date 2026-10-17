/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Result {
    int status;
    int data[7];
};

struct Message {
    int type;
    int value;
};

struct Session {
    char pad[0x630];
    char events[0x2C];
    char pad2[0x65C - 0x630 - 0x2C];
    char lookup[1];
};

extern "C" {
Result func_004AE6B0(void *lookup);
int func_004AFED8(void *, void *, int);
int func_004AFA20(void *, Message *);
void func_006111D0(void *);

int func_00557F90(Session *s)
{
    Result r = func_004AE6B0(s->lookup);
    Message msg;
    if (r.status == 0) {
        func_004AFED8(s, s->lookup, 0);
        msg.type = 3;
        msg.value = 0x7FFFFFFF;
        func_004AFA20(s, &msg);
        func_006111D0(s->events);
        return 1;
    }
    return 0;
}
}
