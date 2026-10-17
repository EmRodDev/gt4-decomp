typedef int s32;
/* Partial list header. Entries begin at +0x10, occupy eight bytes,
   and this accessor returns the second word of the selected entry. */
struct List { s32 unknown00; s32 count; unsigned char unknown08[8]; };
struct Owner { List *list; };
extern "C" s32 func_006039C8(Owner *owner, s32 index) {
    if (index < 0) return -1;
    List *list = owner->list;
    if (index >= list->count) return -1;
    s32 offset = index * 8;
    return *(s32 *)((char *)list + offset + 0x14);
}
