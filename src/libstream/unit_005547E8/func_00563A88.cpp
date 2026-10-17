typedef int s32;
typedef unsigned int u32;

extern "C" u32 func_00563198(int bits);
extern "C" s32 func_00563158(s32 bits);
extern "C" void func_00563258(u32 bits);
extern "C" void func_00563868(void);
extern "C" void func_00563B98(void);
extern "C" void func_00563C70(void);
extern "C" void func_00563CC8(void);

enum MpegCode { ExtensionStart = 0x1B5, UserDataStart = 0x1B2 };
enum ExtensionId { SequenceExtension = 1, SequenceDisplayExtension = 2,
                   PictureCodingExtension = 8 };

/* Consume extension/user-data units, leaving the following start code unread.
   The returned boundary code also preserves the value forwarded by the header
   readers; its meaning outside this parsing family has not been established. */
extern "C" s32 func_00563A88(void) {
    u32 startCode;

    func_00563868();
    while ((startCode = func_00563198(32)) == ExtensionStart || startCode == UserDataStart) {
        func_00563258(32);
        if (startCode != ExtensionStart) {
            func_00563868();
            continue;
        }
        switch ((u32)func_00563158(4)) {
        case SequenceExtension:
            func_00563B98();
            break;
        case SequenceDisplayExtension:
            func_00563C70();
            break;
        case PictureCodingExtension:
            func_00563CC8();
            break;
        }
        func_00563868();
    }
    return (s32)startCode;
}
