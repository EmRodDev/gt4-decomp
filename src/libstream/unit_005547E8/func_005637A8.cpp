#include "types.h"

extern "C" s32 func_00563158(s32 bits);
extern "C" void func_00563868(void);
extern "C" s32 func_005638B0(void);
extern "C" void func_00563960(void);
extern "C" s32 func_005639B8(void);

enum MpegStartCode {
    PictureStart = 0x100,
    SequenceHeader = 0x1B3,
    SequenceEnd = 0x1B7,
    GroupOfPictures = 0x1B8
};

/* Scan headers until a picture is ready or the sequence ends. Unknown codes
   are consumed and the next start code is sought by the alignment helper. */
extern "C" s32 func_005637A8(void) {
    for (;;) {
        u32 startCode;

        func_00563868();
        startCode = func_00563158(32);
        switch (startCode) {
        case SequenceHeader:
            func_005638B0();
            break;
        case GroupOfPictures:
            func_00563960();
            break;
        case SequenceEnd:
            return 0;
        case PictureStart:
            func_005639B8();
            return 1;
        }
    }
}
