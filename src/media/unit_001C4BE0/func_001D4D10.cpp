/* Encrypts a block in place (counterpart of func_001D4E60): the payload starts at +8, its checksum func_00572C90 xor 'key' goes into k4, a fresh random-looking word from func_00579358 into k0, two key schedules (0x9D0-byte state) are derived from them and the payload is processed by func_005D2680; the header words are then mixed with func_001D4CA8 (parameters f0, f1) and an optional extra pass is applied when 'extraPass' is non-zero. Sizes are rounded to a 0x40 multiple. 'Encrypts' and 'random' are inferred from the structure; the algorithm is not identified. */
#include "types.h"
extern "C" void func_001D4BC8(void *, u32, void *, int, int);
extern "C" void func_001D4CA8(void *, u32, void *, u32, float);
extern "C" u32 func_00572C90(void *, u32);
extern "C" void func_005792E8(void *, u32);
extern "C" u32 func_00579358();
extern "C" int func_00579420(void *, u32);
extern "C" void func_005D2680(void *, u32, void *, void *);

struct H { u32 k0; u32 k4; };

extern "C" void func_001D4D10(H *block, int payloadSize, u32 key, int extraPass, float mixParamA, float mixParamB) {
    char keyState[0x9D0];
    char keyState2[0x10];
    u32 roundedSize = (payloadSize + 0x47) & ~0x3F;
    u32 processedSize = roundedSize - 8;
    void *payload = (char *)block + 8;
    u32 mixedSize = roundedSize - 4;
    block->k4 = func_00572C90(payload, processedSize) ^ key;
    u32 nonce = func_00579358();
    block->k0 = nonce;
    func_00579420(keyState, block->k4 + nonce);
    func_005792E8(keyState2, block->k4 ^ block->k0);
    func_005D2680(payload, processedSize, keyState, keyState2);
    func_001D4CA8(((char *)block + 4), mixedSize, ((char *)block + 4), 4, mixParamA);
    if (extraPass != 0) {
        func_00579420(keyState, block->k0 ^ key);
        func_001D4BC8(((char *)block + 4), mixedSize, keyState, 0, 0);
    }
    func_001D4CA8(block, roundedSize, block, 4, mixParamB);
}
