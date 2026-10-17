typedef int s32;
typedef unsigned int u32;

enum PictureType { PredictivePicture = 2, BidirectionalPicture = 3 };

extern s32 D_00654DA0;
extern s32 func_00563158(s32 count);
extern void func_00563258(u32 count);
extern s32 func_00563A88(void);

s32 func_005639B8(void) {
    s32 *pictureCodingType;

    func_00563158(10);
    pictureCodingType = &D_00654DA0;
    *pictureCodingType = func_00563158(3);
    func_00563158(16);

    /* P and B pictures include forward motion-vector fields. */
    if (*pictureCodingType == PredictivePicture ||
        *pictureCodingType == BidirectionalPicture) {
        func_00563158(1);
        func_00563158(3);
    }
    /* B pictures also include backward motion-vector fields. */
    if (*pictureCodingType == BidirectionalPicture) {
        func_00563158(1);
        func_00563158(3);
    }

    while (func_00563158(1) != 0)
        func_00563258(8);
    return func_00563A88();
}
