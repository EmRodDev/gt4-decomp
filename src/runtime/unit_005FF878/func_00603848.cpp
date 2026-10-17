typedef int s32;
/* Partial list header. Entries begin at +0x10 and occupy eight bytes;
   the remaining entry fields are not interpreted by this accessor. */
struct List { unsigned char unknown00[8]; s32 count; s32 unknown0C; };
struct Owner { List *list; };
extern "C" s32 func_00603848(Owner *owner, s32 index) {
    if (index < 0) return -1;
    List *list = owner->list;
    if (index >= list->count) return -1;
    s32 offset = index * 8;
    return *(s32 *)((char *)list + offset + 0x10);
}
