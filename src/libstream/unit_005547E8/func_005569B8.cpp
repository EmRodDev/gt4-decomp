typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

/* Provisional layout inferred from this parser's stores. The selected mode
   uses either three wide values or a 3-by-3 matrix of narrow values. */
struct ModeParameters {
    s32 mode;
    s32 format;       /* Set to 2 by this parser. */
    s32 compact;      /* Set from mode for the narrow representation. */
    char unknown0C[4];
    s32 common[3];
    union {
        s32 wide[3];
        s16 narrow[3][3];
    } values;
};

/* Each byte pair contributes low bits at bit 2 and high bits at bit 9;
   callers interpret the resulting 16-bit pattern as signed. */
static inline u16 decodePackedBytes(u8 lowByte, u8 highByte) {
    return (u16)(((u16)lowByte << 2) | ((u16)highByte << 9));
}

extern "C" int func_005B72A8(void);
extern "C" int func_005B72F8(void);

extern "C" void func_005569B8(ModeParameters *parameters, const u8 *packed) {
    func_005B72A8();
    s32 mode = parameters->mode;
    parameters->format = 2;
    parameters->common[0] = (s16)decodePackedBytes(packed[0], packed[1]);
    parameters->common[1] = (s16)decodePackedBytes(packed[2], packed[3]);
    parameters->common[2] = (s16)decodePackedBytes(packed[4], packed[5]);

    switch (mode) {
    case 0:
        parameters->compact = 0;
        parameters->values.wide[2] = (s16)decodePackedBytes(packed[6], packed[7]);
        parameters->values.wide[1] = (s16)decodePackedBytes(packed[8], packed[9]);
        parameters->values.wide[0] = (s16)decodePackedBytes(packed[10], packed[11]);
        break;
    case 1:
        parameters->compact = mode;
        parameters->values.narrow[0][0] = (s16)decodePackedBytes(packed[6], packed[7]);
        parameters->values.narrow[1][0] = (s16)decodePackedBytes(packed[8], packed[9]);
        parameters->values.narrow[2][0] = (s16)decodePackedBytes(packed[10], packed[11]);
        parameters->values.narrow[0][1] = (s16)decodePackedBytes(packed[12], packed[13]);
        parameters->values.narrow[1][1] = (s16)decodePackedBytes(packed[14], packed[15]);
        parameters->values.narrow[2][1] = (s16)decodePackedBytes(packed[16], packed[17]);
        parameters->values.narrow[0][2] = (s16)decodePackedBytes(packed[18], packed[19]);
        parameters->values.narrow[1][2] = (s16)decodePackedBytes(packed[20], packed[21]);
        parameters->values.narrow[2][2] = (s16)decodePackedBytes(packed[22], packed[23]);
        break;
    default:
        /* Other modes retain the variant fields as they were. */
        break;
    }
    /* The original enables interrupts here regardless of their entry state. */
    func_005B72F8();
}
