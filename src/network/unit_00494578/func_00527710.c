typedef unsigned short u16;
typedef struct Record { int kind, handle1, handle2; char pad[0x38]; } Record;
typedef struct Group { Record **slots; char pad[0xc]; int count; int other; } Group;
typedef struct Obj {
    int heap; char pad4[0x80]; Record *records; Group *groups;
    char pad8c[0x30]; unsigned count;
    char padc0[8]; int mode; int cc;
    void (*d0)(int, int, int, int); int d4;
    void (*d8)(int, int); void (*dc)(int, int, int);
    char pade0[8]; int ctx;
} Obj;
void func_00524818(Obj *);
unsigned func_00525FE0(Obj *, int);
void func_00526040(Obj *, int *, u16 *);
int func_005279B0(Obj *, u16 *);
int func_00527BD0(int, Obj *, int, u16, int);
int func_00527C70(Obj *, u16, int);
int func_00528600(Obj *, Group *, u16);
void func_00529650(int, int);
int func_0052D120(int);
int func_0052D140(unsigned *);
void *func_005A48D8(void *, int, unsigned);

int func_00527710(Obj *o, int handle, int mode) {
    u16 first, second;
    int kind;
    unsigned time;
    unsigned idx;
    Record *record;
    unsigned i;

    idx = 0xfffe;
    first = idx;
    second = idx;
    kind = 0;
    idx = func_00525FE0(o, handle);
    if (idx == 0xfffe) {
        func_00529650(o->heap, handle);
        func_00526040(o, &kind, &first);
        if (kind != 5) {
            if (kind != 0) return 0;
        }
        func_00524818(o);
        o->d0(0xfffe, 0, 0xd4e5, o->ctx);
        return 0xd4e5;
    }
    record = o->records + idx;
    func_00526040(o, &kind, &first);
    if (o->groups != 0) {
        for (i = 0; i < o->count; i++) {
            Group *g = o->groups + i;
            if (record == g->slots[idx]) {
                g->slots[idx] = 0;
                g->count--;
                {
                    int r = func_00528600(o, g, first);
                    if (r != 0) return r;
                }
            }
        }
    }
    func_00526040(o, &kind, &first);
    if (kind == 5 || kind == 0) {
        func_00524818(o);
        o->d0(0xfffe, 0, 0xd4e5, o->ctx);
        return 0xd4e5;
    }
    if (record->handle1) {
        func_00529650(o->heap, record->handle1);
        record->handle1 = 0;
    }
    if (record->handle2) {
        func_00529650(o->heap, record->handle2);
        record->handle2 = 0;
    }
    o->dc(idx, 1, o->ctx);
    if (record->kind == 4) func_005279B0(o, &second);
    if (o->mode) func_00527BD0(mode, o, kind, first, idx);
    else func_00527C70(o, first, idx);
    func_005A48D8(record, 0, 0x44);
    if (second != 0xfffe) {
        o->d8(second, o->ctx);
        if (o->mode && second == first) {
            func_0052D140(&time);
            func_0052D120(time >> 2);
        }
    }
    return 0;
}
