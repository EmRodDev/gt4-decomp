/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Places a car at a world position on the course and (re)builds its derived state: the car state block (+0x104) gets the position, the
 * ground height found by querying the course (func_00395760 with a query record, axes swapped as in convertInit) plus the ride height from
 * the spec block (+0x10), and the rotation blocks are rebuilt by 0036C9F8 from two zero angles and the heading. Then, for each of the
 * variant record's slots (wheels, inferred: the slot offsets are body-relative positions, 0xEC bytes apart from +0x164, with a 0x34-byte
 * ground query each from +0x7B8, and the count byte is 4 for the car layouts seen), the slot's world position is queried, ground height and
 * surface flags are stored (or the slot is set to a default height below the body when the query found nothing), and two contact counters are
 * kept (written to +0x62D and +0x62C of the state). A second pass per slot sets spring-like values from the spec and calls 003F7CA8,
 * 0036A578, 0036A690; finally the previous-position copies (+0x61C..+0x628, +0x4A8) are refreshed and +0x650 cleared. Many float temporaries are
 * reused for unrelated values, so temp_f0..temp_f2 keep their generic names; the physical meaning of most stored values is purpose unknown. */
typedef float f32;
typedef int s32;
typedef short s16;
typedef signed char s8;
typedef unsigned char u8;
struct VI {short delta, index; int (*fn)(void *);};
struct VF {short delta, index; float (*fn)(void *,void *);};
#define NULL 0

#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))

extern "C" void func_00345A20(void *);                      /* extern */
extern "C" char *func_00359510(void *) throw();                        /* extern */
extern "C" void func_0035D350(void *) throw();                      /* extern */
extern "C" f32 func_0036A578(void *, s32, f32, f32);   /* extern */
extern "C" f32 func_0036A690(void *, s32, f32, f32);   /* extern */
extern "C" void func_0036C9F8(void *, void *, void *, f32, f32, f32); /* extern */
extern "C" void func_00395760(s32, void *);  /* extern */
extern "C" s32 func_003F4E40(void *);                           /* extern */
extern "C" s32 func_003F4EA0(void *);                          /* extern */
extern "C" s32 func_003F7C80();                                /* extern */
extern "C" f32 func_003F7CA8(void *, s32, f32, f32); /* extern */
extern "C" f32 func_0057D118(f32, f32);                        /* extern */

struct V {float x,y,z;};
static inline void convert(float *d, const V *s) {
 float z=-s->y; d[1]=s->z; float x=s->x; d[2]=z; d[0]=x;
}
static inline void convertInit(float *d, const V *s) { float x=s->x,y=s->z,z=-s->y; d[0]=x; d[1]=y; d[2]=z; }
static inline int mapWheel(char *p,int i) { if(i < (int)*(u8 *)(p+1)) return *((u8 *)p+0x14+i); return 0; }
extern "C" s32 func_003630C0(char *car, s32 groundId, f32 posX, f32 posY, f32 posZ, f32 heading) {
    struct Query { f32 x,y,z; s32 id; f32 height; char rest[0x2c]; } groundQuery0;
    union Vec {V v; f32 a[3];} pos;
    char *variantPlus4;
    char *specPlus14;
    char *specPlus8;
    f32 temp_f0;
    f32 valueFrom3F7CA8;
    f32 scratchFloat;
    f32 zeroAngle;
    f32 pitchAngle;
    f32 temp_f1;
    f32 valueAt48;
    f32 temp_f2;
    s32 wheelBase58;
    s32 wheelIndex;
    s32 var_v0;
    s32 contactCountB;
    s32 contactCountA;
    u8 *unusedBytePtr;
    s32 unusedV1;
    s32 mappedWheel;
    char *owner;
    char *ownerAgain;
    char *state;
    char *spec;
    char *variantRecord;
    char *ownerTable2;
    char *ownerTable;
    char *wheelSlot;
    char *wheelSlot2;
    char *groundQuery;

    wheelIndex = 0;
    contactCountA = 0;
    contactCountB = 0;
    pos.v.y = posY;
    state = car + 0x104;
    pos.v.z = posZ;
    pos.v.x = posX;
    spec = M2C_FIELD(car, char **, 0x10);
    convertInit(&groundQuery0.x, &pos.v);
    groundQuery0.id = groundId;
    func_00395760(M2C_FIELD(car, s32 *, 8), &groundQuery0);
    M2C_FIELD(state, f32 *, 0) = posX;
    M2C_FIELD(state, s32 *, 0x4A8) = groundQuery0.id;
    M2C_FIELD(state, f32 *, 4) = posY;
    float height = groundQuery0.height;
    temp_f0 = height + M2C_FIELD(spec, f32 *, 0x3C);
    M2C_FIELD(state, f32 *, 0x568) = 0x0.0p+0f;
    M2C_FIELD(state, f32 *, 0x56C) = 0x0.0p+0f;
    zeroAngle = M2C_FIELD(state, f32 *, 0x568);
    M2C_FIELD(state, f32 *, 0x570) = heading;
    M2C_FIELD(state, f32 *, 8) = temp_f0;
    func_0036C9F8(car + 0x110, car + 0x11C, car + 0x128, zeroAngle, zeroAngle, heading);
    pos.v.z = height;
    func_00345A20(car);
    variantRecord = func_00359510(spec);
    if (M2C_FIELD(variantRecord, u8 *, 1) != 0) {
        groundQuery = car + 0x7B8;
        wheelSlot = car + 0x164;
        do {
            f32 ox = M2C_FIELD(wheelSlot, f32 *, 0xC);
            f32 oy = M2C_FIELD(wheelSlot, f32 *, 0x10);
            f32 oz = M2C_FIELD(wheelSlot, f32 *, 0x14);
            temp_f0 = M2C_FIELD(state, f32 *, 0) + ox;
            temp_f1 = M2C_FIELD(state, f32 *, 4) + oy;
            temp_f2 = M2C_FIELD(state, f32 *, 8) + oz;
            pos.v.x = temp_f0;
            pos.v.y = temp_f1;
            pos.v.z = temp_f2;
            convert((float *)groundQuery, &pos.v);
            M2C_FIELD(groundQuery, s32 *, 0xC) = (s32) M2C_FIELD(state, s32 *, 0x4A8);
            func_00395760(M2C_FIELD(car, s32 *, 8), groundQuery);
            if (M2C_FIELD(groundQuery, u8 *, 0x30) == 0) {
                M2C_FIELD(wheelSlot, f32 *, 0x8C) = (f32) M2C_FIELD(groundQuery, f32 *, 0x10);
                M2C_FIELD(wheelSlot, s8 *, 0x89) = func_003F4E40(groundQuery);
                M2C_FIELD(wheelSlot, u8 *, 0x8A) = (u8) M2C_FIELD(groundQuery, u8 *, 0x32);
                M2C_FIELD(wheelSlot, u8 *, 0x8B) = (u8) M2C_FIELD(groundQuery, u8 *, 0x33);
                contactCountA += M2C_FIELD(groundQuery, u8 *, 0x33) & 1;
                if (func_003F4EA0(groundQuery) != 0) {
                    contactCountB += 1;
                }
            } else {
                M2C_FIELD(wheelSlot, s8 *, 0x89) = 0;
                M2C_FIELD(wheelSlot, u8 *, 0x8A) = 0U;
                M2C_FIELD(wheelSlot, u8 *, 0x8B) = 0U;
                M2C_FIELD(wheelSlot, f32 *, 0x8C) = (f32) (height + M2C_FIELD(wheelSlot, f32 *, 0x14));
            }
            wheelIndex += 1;
            groundQuery += 0x34;
            wheelSlot += 0xEC;
        } while (wheelIndex < (s32) M2C_FIELD(variantRecord, u8 *, 1));
    }
    M2C_FIELD(state, u8 *, 0x4B1) = (u8) (M2C_FIELD(state, u8 *, 0x4B1) & 0xEF);
    if (contactCountA != 0) {
        owner = M2C_FIELD(car, char **, 4);
        ownerTable = M2C_FIELD(owner, char **, 0x10140);
        VI *entry = (VI *)(ownerTable + 0x180);
        if (entry->fn(owner + entry->delta) != 0) {
            M2C_FIELD(state, u8 *, 0x4B1) = (u8) (M2C_FIELD(state, u8 *, 0x4B1) | 0x10);
        }
    }
    M2C_FIELD(state, s8 *, 0x62C) = contactCountB;
    M2C_FIELD(state, s8 *, 0x62D) = contactCountA;
    for (wheelIndex = 0; wheelIndex < (s32)M2C_FIELD(variantRecord, u8 *, 1); wheelIndex++) {
        variantPlus4 = variantRecord + 4;
        specPlus14 = spec + 0x14;
        specPlus8 = spec + 8;
        wheelSlot2 = car + 0x164 + wheelIndex * 0xEC;
            mappedWheel = mapWheel(variantRecord, wheelIndex);
            wheelBase58 = mappedWheel * 0x58;
            valueAt48 = (M2C_FIELD(((mappedWheel * 4) + spec), f32 *, 0x1040) / (f32) *(u8 *)(variantPlus4 + mappedWheel)) + M2C_FIELD((wheelBase58 + (s32)specPlus14), f32 *, 0x330);
            M2C_FIELD(wheelSlot2, s8 *, 0xB3) = 0;
            M2C_FIELD(wheelSlot2, f32 *, 0x48) = valueAt48;
            M2C_FIELD(wheelSlot2, f32 *, 0x4C) = valueAt48;
            M2C_FIELD(wheelSlot2, f32 *, 0x94) = (f32) M2C_FIELD((wheelBase58 + (s32)specPlus8), f32 *, 0x310);
            valueFrom3F7CA8 = func_003F7CA8(spec, wheelIndex, 0.0f, 0.0f);
            M2C_FIELD(wheelSlot2, f32 *, 0x1C) = 0x0.0p+0f;
            M2C_FIELD(wheelSlot2, f32 *, 0) = valueFrom3F7CA8;
            M2C_FIELD(wheelSlot2, f32 *, 0x18) = 0x0.0p+0f;
            if (func_003F7C80() == 2) {
                M2C_FIELD(wheelSlot2, f32 *, 0x18) = 0x0.0p+0f;
                M2C_FIELD(wheelSlot2, f32 *, 0x1C) = (f32) M2C_FIELD(wheelSlot2, f32 *, 0);
            }
            M2C_FIELD(wheelSlot2, f32 *, 4) = func_0036A578(spec, wheelIndex, 0.0f, 0.0f);
            scratchFloat = func_0036A690(spec, wheelIndex, 0.0f, 0.0f);
            M2C_FIELD(wheelSlot2, f32 *, 8) = scratchFloat;
    }
    func_0035D350(car);
    M2C_FIELD(state, f32 *, 0x568) = (f32) M2C_FIELD(state, f32 *, 0x574);
    M2C_FIELD(state, f32 *, 0x56C) = (f32) M2C_FIELD(state, f32 *, 0x578);
    scratchFloat = func_0057D118(M2C_FIELD(spec, f32 *, 0x40) - M2C_FIELD(spec, f32 *, 0x44), M2C_FIELD(spec, f32 *, 0x18));
    pitchAngle = M2C_FIELD(state, f32 *, 0x568) + scratchFloat;
    M2C_FIELD(state, f32 *, 0x568) = pitchAngle;
    func_0036C9F8(state + 0xC, state + 0x18, state + 0x24, pitchAngle, M2C_FIELD(state, f32 *, 0x56C), M2C_FIELD(state, f32 *, 0x570));
    M2C_FIELD(state, f32 *, 8) = (f32) (M2C_FIELD(state, f32 *, 0x38) + (M2C_FIELD(state, f32 *, 0x2C) * M2C_FIELD(spec, f32 *, 0x3C)));
    func_00345A20(car);
    ownerAgain = M2C_FIELD(car, char **, 4);
    if (M2C_FIELD(ownerAgain, u8 *, 0xCBDE) == 2) {
        M2C_FIELD(state, f32 *, 0x4A4) = 0x0.0p+0f;
    } else {
        ownerTable2 = M2C_FIELD(ownerAgain, char **, 0x10140);
        VF *entry = (VF *)(ownerTable2 + 0x108);
        M2C_FIELD(state, f32 *, 0x4A4) = entry->fn(ownerAgain + entry->delta, car);
    }
    M2C_FIELD(state, s32 *, 0x628) = (s32) M2C_FIELD(state, s32 *, 0x4A8);
    float x = M2C_FIELD(state, f32 *, 0x30);
    float y = M2C_FIELD(state, f32 *, 0x34);
    float z = M2C_FIELD(state, f32 *, 0x38);
    M2C_FIELD(state, f32 *, 0x624) = z;
    M2C_FIELD(state, f32 *, 0x61C) = x;
    M2C_FIELD(state, f32 *, 0x620) = y;
    M2C_FIELD(state, s32 *, 0x650) = 0;
    return 0;
}
