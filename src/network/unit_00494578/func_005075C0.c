struct PacketIdBytes { char b[4]; };
struct Raw { int a[25]; };
enum Mode { MODE_0, MODE_1 };
struct Packet {
    char pad0[2];
    struct PacketIdBytes id;
    char pad6[2];
    int status;
    int fC;
    enum Mode mode;
    char pad14[4];
    struct Raw data;
};
enum ObjState { OBJ_FREE, OBJ_USED };
struct Obj {
    struct Raw data;
    enum ObjState state;
    int f68;
    enum Mode mode;
    char f70[100];
    char padD4[0x138 - 0xD4];
    char date[16];
    char time[16];
    char pad158[8];
    int f160;
    int f164;
    int f168;
};
typedef void (*Callback)(int, struct Obj **, int);
extern int D_0064A248;
extern Callback D_0064A2D8;
extern Callback D_0064A2D4;
extern char D_006C1590[];
extern char D_006C15A0[];
int func_0050FCE8(void *, struct Obj **);
int func_0050A1C0(struct Obj **);
int func_0050FC90(struct Obj *);
int func_0050A210(struct Obj **);
void *memcpy(void *, const void *, unsigned int);
void *func_005A48D8(void *, int, unsigned int);
int func_005A6AB0(void *, void *, int);

void func_005075C0(int a0, int a1, int a2, struct Packet *p)
{
    char buf[0x70];
    int key;
    struct Obj *obj = 0;
    struct Obj *r0;
    struct Obj *r1;
    int status;

    key = 0;
    status = p->status;
    memcpy(&key, &p->id, sizeof(key));
    D_0064A248 = 0;
    if (status != 0)
        return;
    if (func_0050FCE8(buf, &obj)) {
        obj = 0;
        if (func_0050A1C0(&obj) == 0) {
            obj->data = p->data;
            if (func_0050FC90(obj))
                func_0050A210(&obj);
        }
    }
    if (obj) {
        obj->state = OBJ_USED;
        obj->f68 = p->fC;
        obj->mode = p->mode;
        obj->data = p->data;
        func_005A48D8(obj->f70, 0, 100);
        func_005A6AB0(obj->date, D_006C1590, 15);
        func_005A6AB0(obj->time, D_006C15A0, 15);
        obj->f160 = 0;
        obj->f164 = 0;
        obj->f168 = 0;
    }
    if (p->mode == MODE_0) {
        r0 = obj;
        D_0064A248 = (int)obj;
        if (D_0064A2D8)
            D_0064A2D8(status, &r0, key);
    } else {
        r1 = obj;
        D_0064A248 = (int)obj;
        if (D_0064A2D4)
            D_0064A2D4(status, &r1, key);
    }
}
