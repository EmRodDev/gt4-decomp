/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Tbl { u8 *data; char p4[6]; u16 a, b; } Tbl;
typedef struct Obj { char pad[0x24]; u8 *h; } Obj;
typedef struct Field { u16 index; char p2[3]; u8 count; u16 type; char p8[2]; u8 tag; } Field;
typedef struct Item { unsigned int flags; union { u8 *ptr; Field f; u8 b[12]; } u; } Item;
u8 *func_004C0740(int, u8 *, int);
int func_004C3998(u8 *, int, int);
void func_004C9030(u16 *, u8 *, int);
void func_004C9090(u16 *, u8 *, int);
void func_004C3288(Obj *, int, u8 *, u16 *);


int func_004C1788(Obj *self, u16 *out, int capacity, Item *item)
{
    int length = 0;
    unsigned int flags = item->flags;
    if (flags & 0x400000) {
        u16 tag = (signed char)item->u.f.tag | 0x300;
        Field *f = &item->u.f;
        u8 *head = self->h;
        int idx = f->index;
        int mode = f->type >> 14;
        int toff = (tag & 0xff) * 16 + 0x50;
        Tbl *t = (Tbl *)(head + toff);
        int off = idx * 20;
        int n = (t->a + t->b) * 6;
        u8 *p = (u8 *)(n + (off + (int)t->data));
        u8 *q = (u8 *)(off + (int)(t->data + n));
        u8 *base;
        if (((p[6] << 8) | q[7]) == 0) return 0x80001E28;
        switch (mode) {
        case 0:
            length = f->count * 2;
            if (capacity < length) return 0x80001028;
            base = func_004C0740(idx, head, tag);
            if (!base) return 0x80001E28;
            {
                Tbl *tb = (Tbl *)(self->h + toff);
                int o = f->index * 20;
                u8 *r = (u8 *)(o + (int)(tb->data + (tb->a + tb->b) * 6));
                func_004C9090(out, base + r[0x12], f->count);
            }
            break;
        case 1:
            length = q[0xb];
            if (capacity < length) return 0x80001028;
            base = func_004C0740(idx, head, tag);
            if (!base) return 0x80001E28;
            {
                Tbl *tb = (Tbl *)(self->h + toff);
                int o = f->index * 20;
                u8 *r = (u8 *)(o + (int)(tb->data + (tb->a + tb->b) * 6));
                func_004C9030(out, base + r[0x12] + r[0xd], length);
            }
            break;
        case 2:
            length = func_004C3998(head, tag, idx);
            if (capacity < length) return 0x80001028;
            base = func_004C0740(f->index, self->h, tag);
            if (!base) return 0x80001E28;
            {
                Tbl *tb = (Tbl *)(self->h + toff);
                int o = f->index * 20;
                u8 *r = (u8 *)(o + (int)(tb->data + (tb->a + tb->b) * 6));
                func_004C9030(out, base + r[0x12] + r[0xd], length);
            }
            break;
        }
        return length;
    } else {
        u8 *ent = self->h + (signed char)item->u.b[6] * 44;
        if (flags & 0xc00000) length = item->u.b[2];
        else length = item->u.ptr[3] & 0xf;
        if (capacity < length) return 0x80001028;
        func_004C3288(self, *(int *)(ent + 0x18), item->u.ptr, out);
    }
    return length;
}
