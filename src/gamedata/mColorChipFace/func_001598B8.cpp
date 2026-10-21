/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Stretches the image object `image` over the widget's full window rectangle through the painter object `painter` (inferred
 * from the calls: widget size from mWidget__getWindowSize, image width/height from its virtuals at +0x70 / +0x78, a destination quad and a
 * source quad of four corners, then painter virtual +0x1B0 with both quads). Does nothing unless image virtual +0x58 is non-zero.
 * The meaning of the 16-byte scratch object set up before the draw (virtual +0x198 of the painter) is unknown; the VCALL macros
 * spell out the compiler's virtual-call form with the this-adjustment stored next to each slot. */
typedef int s32;
typedef float f32;
struct VEntry {
    short delta;
    short index;
    void *fn;
};
#define VCALL0(R, o, off) ({ VEntry *e_ = (VEntry *)(*(char **)((char *)(o) + 4) + (off)); ((R(*)(void *))e_->fn)((char *)(o) + e_->delta); })
#define VCALL1(R, o, off, a) ({ VEntry *e_ = (VEntry *)(*(char **)((char *)(o) + 4) + (off)); ((R(*)(void *, ...))e_->fn)((char *)(o) + e_->delta, a); })
#define VCALL4(o, off, a, b, c, d) ({ VEntry *e_ = (VEntry *)(*(char **)((char *)(o) + 4) + (off)); ((void (*)(void *, s32, void *, void *, s32))e_->fn)((char *)(o) + e_->delta, a, b, c, d); })

struct Pt {
    f32 x, y;
    inline void set(float a,float b) { x=a; y=b; }
    inline void set(int a,int b) { *(int *)&x=a; *(int *)&y=b; }
    inline void set(float a,int b) { x=a; *(int *)&y=b; }
    inline void set(int a,float b) { *(int *)&x=a; y=b; }
};
struct Quad {
    Pt p[4];
};
extern "C" void *func_002030A0(void *);
extern "C" void func_00203118(void *, int);
extern "C" void mWidget__getWindowSize(void *, f32 *, f32 *);

extern "C" void func_001598B8(void *self, void *painter, void *image) {
    f32 windowWidth, windowHeight;
    if (image != 0) {
        if (VCALL0(s32, image, 0x58) != 0) {
            mWidget__getWindowSize(self, &windowWidth, &windowHeight);
            Quad destQuad;
            Pt *destCorners = destQuad.p;
            destCorners[0].set(0,0);
            destCorners[1].set(windowWidth,0);
            destCorners[2].set(0,windowHeight);
            destCorners[3].set(windowWidth,windowHeight);
            f32 imageWidth = VCALL0(f32, image, 0x70);
            f32 imageHeight = VCALL0(f32, image, 0x78);
            Quad sourceQuad;
            Pt *sourceCorners = sourceQuad.p;
            sourceCorners[0].x = 0;
            sourceCorners[0].y = 0;
            sourceCorners[1].x = imageWidth;
            sourceCorners[1].y = 0;
            sourceCorners[2].x = 0;
            sourceCorners[2].y = imageHeight;
            sourceCorners[3].x = imageWidth;
            sourceCorners[3].y = imageHeight;
            char scratch[16];
            func_002030A0(scratch);
            VCALL1(void, painter, 0x198, scratch);
            func_00203118(scratch, 2);
            VCALL0(void, painter, 0x1D0);
            VCALL1(void, painter, 0x1C0, 1);
            VCALL0(void, image, 0x68);
            VCALL4(painter, 0x1B0, 4, destCorners, sourceCorners, 0);
            VCALL0(void, painter, 0x1C8);
            VCALL0(void, painter, 0x1D8);
        }
    }
}
