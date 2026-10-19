/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;
struct Channel { f32 f0; f32 a, b, c, d; f32 e; char pad[0x178 - 0x18]; };
struct Group { Channel ch[6]; };
struct VEntry { short delta, index; void *(*fn)(void *); };
struct VObj { char pad[8]; VEntry *vtbl; };
struct Item { char pad[0x2880]; VObj *obj; };
struct List { char pad[8]; Item **items; };
struct World { char pad[0x60]; List *list; };
struct Owner { World *world; };
struct Res { char pad[0x50]; char *p50; };
extern "C" f32 func_00344AA8(void *, int, f32);
extern "C" f32 func_00344C08(void *, int, f32);
extern "C" void *func_0034C190(Owner *, int);
extern "C" f32 func_003CCB60(void *, f32, f32) throw();
extern "C" int func_003CD900(void *, int, int) throw();
extern "C" void func_003CE4A0(void *, int, Owner *) throw();
extern "C" f32 func_003F3708(void *);

extern "C" void func_003CE930(char *self, int idx, Owner *owner)
{
    void *car = func_0034C190(owner, idx);
    char *base = self + idx * 0x8D0;
    f32 amount = func_003CCB60(self, 0x1.199998p+0f, 0x1.333332p+0f);
    Channel *row = (Channel *)(base + 0x9C4);
    amount += row->e;
    Group *group = (Group *)(base + 0x3E4);
    switch (*(int *)(idx * 4 + self + 0x9658)) {
    case 0: {
        func_003CE4A0(self, idx, owner);
        f32 *p = &group->ch[4].a;
        *p = *p + 0x1.999998p-4f + amount;
        return;
    }
    case 1: {
        int k = func_003CD900(self, idx, 3);
        f32 zero = 0.0f;
        f32 a = func_00344AA8(car, k, zero) + 0x1.999998p-4f;
        f32 b = func_00344C08(car, k, zero) + 0.75f;
        row->a = a + amount;
        row->b = zero;
        row->c = b;
        row->d = 0x1.2d958p+2f;
        break;
    }
    case 2: {
        func_003CE4A0(self, idx, owner);
        f32 *p = &group->ch[4].a;
        *p = *p - 0x1.999998p-4f - amount;
        break;
    }
    case 3: {

        VObj *o = owner->world->list->items[idx]->obj;
        VEntry *e = &o->vtbl[10];
        Res *r = (Res *)e->fn((char *)o + e->delta);
        f32 v = r->p50 ? *(f32 *)(r->p50 + 0xAC) : 0.0f;
        f32 zero = 0.0f;
        f32 f = -0x1.999998p-4f - func_003F3708(car);
        Channel *c = &group->ch[4];
        c->a = v;
        c->b = zero;
        c->c = f - amount;
        c->d = zero;
        break;
    }
    }
}
