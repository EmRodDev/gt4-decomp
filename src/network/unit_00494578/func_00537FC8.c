struct Q { int x0; int x4; unsigned int n; int xC; void *data; int arg; };
void *memset(void *, int, unsigned int);
int func_00538BF8(void **, unsigned long long);

int func_00537FC8(struct Q *q, unsigned int n, int arg) {
    if (q == 0)
        return 2;
    if (n == 0)
        return 2;
    memset(q, 0, sizeof(struct Q));
    if (func_00538BF8(&q->data, n) != 0)
        return 100;
    if (q->data == 0)
        return 100;
    q->arg = arg;
    q->n = n;
    q->x4 = 0;
    q->xC = 0;
    q->x0 = 0;
    return 0;
}
