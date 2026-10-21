/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Sorts a counted list of 24-byte entries by the float at +4 of each entry, ascending (insertion sort written as a swap-down). */
typedef int s32;
typedef float f32;
typedef unsigned long long s64 __attribute__((aligned(4)));

struct E {
    s64 q0;
    s64 q1;
    s64 q2;
    f32 key() { return *(f32 *)((char *)this + 4); }
} __attribute__((aligned(4)));

struct List {
    s32 n;
    E e[1];
};

extern "C" void func_0040A5A0(List *list) {
    s32 i, j;
    for (i = 0; i < list->n; i++) {
        E moving = list->e[i];
        for (j = 0; j < i; j++) {
            if (list->e[j].key() > moving.key()) {
                E swapped = list->e[j];
                list->e[j] = moving;
                moving = swapped;
            }
        }
        list->e[i] = moving;
    }
}
