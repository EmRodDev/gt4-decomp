/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Sets the stream/packet ready flag at offset 0x1F to 1 and copies the two
   16-bit sample rate / channel dimension parameters from the input header. */

typedef unsigned char u8;
typedef short s16;
typedef int s32;

struct Dst {
    char pad0[0x1F];
    u8 flag1F;
    char pad1[0x64 - 0x20];
    s16 val64;
    s16 val66;
};

void func_0055CF88(struct Dst *dst, s32 *src) {
    s32 w1;
    s32 new_var;
    s32 w0;

    new_var = src[0];
    w1 = src[1];
    dst->flag1F = 1;
    do { w0 = new_var; } while (0);
    dst->val64 = w0;
    dst->val66 = w1;
}
