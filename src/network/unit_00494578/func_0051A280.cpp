/* Applies one received update packet: a 4-byte header (type, count, id) followed by `count` records of one index byte and
 * width*height bytes of data (inferred from the loop; the record size comes from the size table of the packet's type). Returns the number
 * of bytes consumed, or -1 for a malformed packet. When the entry for `id` is in state 2 the data is also copied into its two
 * destination buffers (at +0x1C and +0x20 of the entry; the entry is looked up by func_00515DD8) and the record is
 * time-stamped and reported through func_00516030. In any other state the packet is only walked to measure its length. Purpose of
 * the third argument unknown beyond being range checked against 64. */
#include "types.h"
struct Header { u8 type, count; u16 id; };
struct Size { int x, w, h; };
struct Table { int x, n; char pad8[0x20]; Size *sizes[64]; int offsets[64]; };
struct Entry { u8 type; char pad1[3]; int handle; char pad8[0x14]; char *dst1, *dst2; char pad24[0x18]; int *times; };
struct Context { char pad[0x82f8]; Table tables[(0xe638 - 0x82f8) / 0x228]; char padE5F0[0xe638 - 0x82f8 - (0xe638 - 0x82f8) / 0x228 * 0x228]; signed char state[4096]; };
struct Timer { char pad[0x5c]; int time; };
extern Context *D_0064B4B4;
extern Timer *D_0064B47C;
extern "C" Entry *func_00515DD8(u32) throw();
extern "C" void func_00516030(int, int, u32) throw();
extern "C" void *func_005A4724(void *, const void *, u32);
extern "C" int func_0051A280(int unused0, int unused1, u32 rangeCheckedArg, Header *header) {
    if (rangeCheckedArg >= 64) return -1;
    if (header->id >= 4096) return -1;
    Context **contextSlot = &D_0064B4B4;
    Table *table;
    Size *recordSize;
    u32 recordIndex, i;
    int bytesConsumed = 4;
    u8 *cursor = (u8 *)(header + 1);
    if ((*contextSlot)->state[header->id] != 2) {
        table = &(*contextSlot)->tables[header->type];
        for (i = 0; i < header->count; i++) {
            recordIndex = *cursor++;
            if ((int)recordIndex >= table->n) return -1;
            recordSize = table->sizes[recordIndex];
            bytesConsumed++;
            if (!recordSize) return -1;
            int dataBytes = recordSize->w * recordSize->h;
            cursor += dataBytes;
            bytesConsumed += dataBytes;
        }
    } else {
        Entry *entry = func_00515DD8(header->id);
        if (!entry) return -1;
        table = &(*contextSlot)->tables[entry->type];
        if (!table) return -1;
        for (i = 0; i < header->count; i++) {
            recordIndex = *cursor++;
            if ((int)recordIndex >= table->n) return -1;
            recordSize = table->sizes[recordIndex];
            bytesConsumed++;
            if (!recordSize) return -1;
            int offset = table->offsets[recordIndex];
            char *secondCopy = entry->dst2 + offset;
            func_005A4724(entry->dst1 + offset, cursor, recordSize->w * recordSize->h);
            func_005A4724(secondCopy, cursor, recordSize->w * recordSize->h);
            int dataBytes = recordSize->w * recordSize->h;
            entry->times[recordIndex] = D_0064B47C->time;
            cursor += dataBytes;
            bytesConsumed += dataBytes;
            func_00516030(entry->handle, header->id, recordIndex);
        }
    }
    return bytesConsumed;
}
