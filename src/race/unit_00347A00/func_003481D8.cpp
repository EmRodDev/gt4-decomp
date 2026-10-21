/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Chooses the 0.0f / 1.0f flag stored at +0x514 of the block at +0x104 (what the flag drives is unknown). It is forced to 0 while
 * the byte at +0x4BC or the short at +0x4BA is non-zero, or +0x467 is 8. Otherwise: mode 3 moves the value at +0x48C into the flag
 * as 1 - value; mode 6 with a non-zero request clears it; a stopped car (speed from +0x53C/+0x540 below 0.22) with +0x490 above 0.8
 * clears it too; the last test sets it from +0x48C below 0.25 or from the short at +0x4FA against a limit read from the owner (+0x202).
 * The owner is the object at +0x10, the same one func_0036D2F8 reads a state byte from at +0x234. */
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;

struct P {
    char pad0[0x462];
    u8 f462;
    u8 f463;
    char pad1[0x467 - 0x464];
    u8 f467;
    char pad2[0x48C - 0x468];
    f32 f48C;
    f32 f490;
    char pad3[0x4BA - 0x494];
    u16 f4BA;
    u8 f4BC;
    char pad5[0x4FA - 0x4BD];
    s16 f4FA;
    char pad6[0x514 - 0x4FC];
    f32 f514;
    char pad7[0x522 - 0x518];
    u8 f522;
    char pad8[0x53C - 0x523];
    f32 f53C;
    f32 f540;
};

struct S {
    char pad0[0x202];
    u16 f202;
    char pad1[0x237 - 0x204];
    u8 f237;
};

struct A {
    char pad0[2];
    s8 f2;
    char pad1[9];
    s16 fC;
};

struct Obj {
    char pad0[0x10];
    S *s;
    char pad1[0x104 - 0x14];
    P p;
};

extern "C" s32 func_003F1F98(void *);

static inline float sqrt_s(float x) {
    float r;
    __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x));
    return r;
}

extern "C" void func_003481D8(Obj *self, A *request, s32 mode) {
    P *drive = &self->p;
    S *owner = self->s;
    if (drive->f4BC == 0 && drive->f4BA == 0 && drive->f467 != 8) {
        if (mode == 3) {
            f32 oldValue = drive->f48C;
            f32 inverted;
            drive->f48C = 0.0f;
            inverted = 1.0f - oldValue;
            drive->f514 = inverted;
            if (inverted != drive->f48C) {
                drive->f463 = 0;
                drive->f462 = 0;
            }
            return;
        }
        if (mode == 6 && (request->f2 != 0 || request->fC != 0)) {
            drive->f514 = 0.0f;
            return;
        }
        if (owner->f237 == 1 && drive->f490 > 0x1.999998p-1f) {
            drive->f514 = 0.0f;
            return;
        }
        if (func_003F1F98((char *)owner + 0x234) != 0 && drive->f490 > 0x1.999998p-1f) {
            f32 x = drive->f53C;
            f32 y = drive->f540;
            if (sqrt_s(x * x + y * y) < 0x1.1c71c6p-2f) {
                drive->f514 = 0.0f;
                return;
            }
        }
        if (drive->f522 == 0) {
            drive->f514 = 0.0f;
            if (drive->f48C < 0.25f) drive->f514 = 1.0f;
        } else {
            drive->f514 = 1.0f;
            if (drive->f4FA < owner->f202) drive->f514 = 0.0f;
        }
    } else {
        drive->f514 = 0.0f;
    }
}
