typedef int s32;

/* Layout backed by include/gt4/hArray.h and config/class_layout.json (size 0x24):
 *   0x00..0x0F: hObject base fields (0x04 vtable)
 *   0x10: vector buffer / Holder:
 *         0x10: capacity / allocator
 *         0x14: start (element pointer)
 *         0x18: finish (element pointer)
 */
struct VectorHolder {
    s32 allocator;
    s32 *start;
    s32 *finish;
};

struct hArrayLayout {
    void *ref_count;
    void *vtable;
    s32 base_fields[2];
    VectorHolder elements;
};

s32 hArray__size(void *arg0)
{
    hArrayLayout *arr = (hArrayLayout *)arg0;
    VectorHolder *v = &arr->elements;
    return v->finish - v->start;
}

