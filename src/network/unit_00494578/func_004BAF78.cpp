/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Record { char pad0[0x11]; unsigned char num; char pad12[2]; short value; char pad16[6]; };
struct Data {
    Record rec[42];
    unsigned char count;
    unsigned char sum;
    char pad49A[2];
    int total;
    void *handles[42];
    unsigned short selected;
    char pad54A[2];
    void *special;
    short specialCount;
};
struct Owner { char pad[0x30]; Data *data; };
extern "C" void *func_004C4070(void *dst, const void *src, unsigned int length);
extern "C" void func_004C8C38(Owner *owner, void *handle);
static inline unsigned char append(Data *d) { return d->count++; }

extern "C" int func_004BAF78(Owner *owner, Data *dst, Record *rec, int keep)
{
    void *buf[42];
    int i, j;
    int shift;
    unsigned short n = owner->data->count - keep;

    if (owner->data->selected != 0x7FFF && (owner->data->selected & 0x7FFF) < n) {
        owner->data->selected = 0x7FFF;
        owner->data->specialCount = 0;
        if (owner->data->special) {
            func_004C8C38(owner, owner->data->special);
            owner->data->special = 0;
        }
    }
    for (i = 0; i < n; i++) {
        if (owner->data->handles[i]) {
            func_004C8C38(owner, owner->data->handles[i]);
            owner->data->handles[i] = 0;
        }
    }
    shift = dst->count + keep + 1;
    shift -= owner->data->count;
    if (keep > 0 && shift != 0) {
        for (i = 0; i < 42; i++)
            buf[i] = 0;
        for (i = owner->data->count - keep; i < owner->data->count; i++)
            buf[shift + i] = owner->data->handles[i];
        func_004C4070(owner->data->handles, buf, sizeof(buf));
        if (owner->data->selected != 0x7FFF)
            owner->data->selected += shift;
    }
    func_004C4070(&dst->rec[append(dst)], rec, sizeof(Record));
    for (j = 0; j < keep; j++) {
        i = owner->data->count - keep + j;
        func_004C4070(&dst->rec[append(dst)], &owner->data->rec[i], sizeof(Record));
    }
    func_004C4070(owner->data, dst, 0x4A0);
    owner->data->total = 0;
    owner->data->sum = 0;
    for (j = 0; j < owner->data->count; j++) {
        owner->data->total += owner->data->rec[j].value;
        owner->data->sum += owner->data->rec[j].num;
    }
    return 0;
}
