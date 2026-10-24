struct Item { int x0; int a; int b; char pad[0x38]; };
struct Obj { int handle; char pad4[0x80]; struct Item *items; char pad88[0x14]; unsigned short count; };
int func_00529048(int, int, int, int *, int *, int *);

int func_00523E50(struct Obj *self, int *total, int *pending, unsigned int *pct, unsigned int *pct2) {
    int sum2 = 0;
    int sum1 = 0;
    unsigned int sum0 = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    struct Item *it;
    unsigned short i;
    if (self == 0)
        return 2;
    if (total == 0)
        return 2;
    if (pending == 0)
        return 2;
    if (pct == 0)
        return 2;
    if (pct2 == 0)
        return 2;
    *pending = 0;
    it = self->items;
    *total = 0;
    *pct2 = 0;
    *pct = 0;
    for (i = 0; i < self->count; i++, it++) {
        if (it->a) {
            if (func_00529048(self->handle, it->a, 0, &x, &y, &z))
                goto out;
            sum0 += x;
            sum1 += y;
            if (func_00529048(self->handle, it->a, 1, &x, &y, &z))
                goto out;
            sum2 += x;
            sum2 += y;
        }
        if (it->b) {
            if (func_00529048(self->handle, it->b, 0, &x, &y, &z))
                goto out;
            sum0 += x;
            sum1 += y;
            if (func_00529048(self->handle, it->b, 1, &x, &y, &z))
                goto out;
            sum2 += x;
            sum2 += y;
        }
    }
    *total = sum1;
    *pending = 0;
    if (sum0 != 0) {
        unsigned int r = sum1 * 100 / sum0;
        *pct = r;
        if (r > 100)
            *pct = 100;
    } else {
        *pct = 0;
    }
    if (sum2 != 0) {
        unsigned int r = 0 * 100 / (unsigned int)sum2;
        *pct2 = r;
        if (r > 100)
            *pct2 = 100;
    } else {
        *pct2 = 0;
    }
out:
    return 0;
}
