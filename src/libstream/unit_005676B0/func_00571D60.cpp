/* compiler: ee-gcc2.9-991111 */
typedef int s32;
typedef unsigned char u8;

extern "C" void *func_005A48D8(void *self, s32 arg, unsigned int size);

extern "C" void func_00571D60(char *o) {
    func_005A48D8(o, 0, 0x1340);
    *(s32 *)(o + 0x1300) = -1;
    *(s32 *)(o + 0x1304) = -1;
    *(s32 *)(o + 0x1308) = -1;
    *(s32 *)(o + 0x130C) = -1;
    *(s32 *)(o + 0x1310) = -1;
    *(s32 *)(o + 0x1314) = -1;
    *(s32 *)(o + 0x1318) = -1;
    *(u8 *)(o + 0x1320) = 0xFF;
    *(u8 *)(o + 0x1321) = 0xFF;
    *(u8 *)(o + 0x1322) = 0xFF;
    *(u8 *)(o + 0x1323) = 0;
    *(u8 *)(o + 0x1325) = 0xFF;
    *(u8 *)(o + 0x1326) = 0xFF;
    *(u8 *)(o + 0x1327) = 0xFF;
    *(u8 *)(o + 0x1324) = 4;
    *(u8 *)(o + 0x1328) = 0xFF;
}
