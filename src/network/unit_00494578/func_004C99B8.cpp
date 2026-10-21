/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Removes one entry from a table of five 16-byte records (slots 1..5, records start at data+0x50, at 0x40 after the shift). key's low byte selects the slot and is translated through the byte map at obj->map into an internal id; the id must have group 3 (0x300) and the record must be in use, otherwise one of the 0x8000xx76 error codes (undetermined meaning) is returned. The entry is cleared, ids above the removed one are decremented, the later records are moved down by one and, when the last one was reached, the last record is zeroed. Inferred from the access pattern; what the table holds is unknown. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj { char pad[0x24]; char *data; char pad28[0x14]; u8 *map; };
extern "C" int func_004C99B8(Obj *table, int handle) {
    int slotIndex = handle & 255;
    if ((u32)(slotIndex-1) >= 5) return 0x80004A76;
    Obj *o = table;
    u8 *mapEntry = o->map + slotIndex;
    int entryId = *mapEntry;
    if (!entryId) return 0x80004B76;
    handle = (u16)((handle & ~255) | entryId);
    if ((handle & 0xff00) != 0x300) return 0x80004876;
    int slotAfterMap = handle & 255;
    if ((u32)(slotAfterMap-1) >= 5) return 0x80004A76;
    if (!*(int *)(o->data + slotAfterMap*16 + 0x50)) return 0x80004B76;
    *mapEntry = 0;
    int cursor;
    for (cursor=1; cursor<6; cursor++) {
        u8 *otherMap = o->map + cursor;
        if (entryId < *otherMap) --*otherMap;
    }
    cursor = slotAfterMap+1;
    for (; cursor<6; cursor++) {
        int srcOffset = cursor*16+0x50;
        int dstOffset = cursor*16+0x40;
        *(int *)(o->data+dstOffset) = *(int *)(o->data+srcOffset);
        char *second = o->data+4;
        *(int *)(second+dstOffset) = *(int *)(second+srcOffset);
        *(u16 *)(o->data+dstOffset+8) = *(u16 *)(o->data+srcOffset+8);
        *(u16 *)(o->data+dstOffset+10) = *(u16 *)(o->data+srcOffset+10);
        *(u16 *)(o->data+dstOffset+12) = *(u16 *)(o->data+srcOffset+12);
        *(u8 *)(o->data+dstOffset+14) = *(u8 *)(o->data+srcOffset+14);
        if (!*(int *)(o->data+srcOffset)) break;
    }
    if (cursor >= 6) {
        *(int *)(o->data+0xa0)=0;
        *(int *)(o->data+0xa4)=0;
        *(u16 *)(o->data+0xa8)=0;
        *(u16 *)(o->data+0xaa)=0;
        *(u16 *)(o->data+0xac)=0;
        *(u8 *)(o->data+0xae)=0;
    }
    return 0;
}
