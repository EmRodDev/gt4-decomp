/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Decrypts a block in place (counterpart of func_001D4D10): block[0] and block[1] are the two header words (a nonce word and a checksum word xor key), the payload follows from block+2 with size-8 bytes. With 'extraPass' set it first runs a second pass over the body, then mixes the header words (func_001D4CA8), derives two key states (func_00579420 / func_005792E8, 0x9D0-byte state), runs func_005D2750 over the payload and verifies the checksum func_00572C90 of the payload against the header: returns the payload size or -1 on a mismatch. 'Decrypts' is inferred from the key/checksum structure; the cipher is not identified. */
typedef int s32;
typedef unsigned int u32;
extern "C" void func_001D4C18(s32, s32, s32, s32, s32) throw();
extern "C" void func_001D4CA8(void *, unsigned int, float, void *, unsigned int) throw();
extern "C" unsigned func_00572C90(const unsigned char *, unsigned);
extern "C" void func_005792E8(s32 *, s32);
extern "C" int func_00579420(void *, s32);
extern "C" void func_005D2750(void *, u32, s32, s32);
extern "C" s32 func_001D4E60(s32 *block, s32 totalSize, s32 outerKey, s32 extraPass, float mixParamA, float mixParamB) {
    char keyState[0x9D0];
    s32 keyState2[4];
    s32 payloadSize = totalSize - 8;
    func_001D4CA8(block, totalSize, mixParamB, block, 4);
    if (extraPass != 0) {
        func_00579420(keyState, *block ^ outerKey);
        func_001D4C18((s32)(block + 1), ((totalSize + 0x3F) & ~0x3F) - 4, (s32)keyState, 0, 0);
    }
    s32 *checksumWord = block + 1;
    u32 roundedEnd = totalSize + 0x3F;
    func_001D4CA8(checksumWord, (roundedEnd & ~0x3F) - 4, mixParamA, checksumWord, 4);
    func_00579420(keyState, *checksumWord + *block);
    func_005792E8(keyState2, *checksumWord ^ *block);
    func_005D2750((block + 2), payloadSize, (s32)keyState, (s32)keyState2);
    *checksumWord ^= outerKey;
    return ((*checksumWord ^ func_00572C90((const unsigned char *)(block + 2), payloadSize)) == 0) ? payloadSize : -1;
}
