/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Command {
    int id;
    int x;
    int y;
    int value;
};

struct Obj {
    char pad0[0x18];
    int value;
    char pad1[0x24C - 0x1C];
    Command command;
};

extern "C" {
extern char D_00655340[];
void func_00576100(void *);
void func_00576140(void *);

void func_0055C020(Obj *o, int id, float x, float y)
{
    func_00576100(D_00655340);
    Command *c = &o->command;
    c->id = id;
    c->x = (int)(x * 16383.0f);
    c->y = (int)(y * 16383.0f);
    c->value = o->value;
    func_00576140(D_00655340);
}
}
